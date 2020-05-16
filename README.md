###Description: 

In this project, my intent was to use some type of biometric data to augment the drawing. I ended up making a prototype of a drawing tool that captures part of the emotional state of the person into the drawing. I use a sensor for electrodermal activity (EDA) as an input for the color of the strokes drawn, so while the user chooses what to draw, each stroke gets colored based on the current level of emotional arousal of the user. 

###Technical setup: 

2 electrodes attached to 2 fingers capture EDA data using an EDA sensor from Seeed Studio, this sensor is connected to an Arduino nano on the forearm that is connected to the computer through a USB cable. The Arduino converts the analog sensor value into a value in the range of 0-1024, to reduce noise, the Arduino calculates an average of 10 values and sends it over a serial port to the computer. The computer is running an openFrameworks code that allows the user to draw lines using a mouse and colors the strokes based on the sensor reading. The sketch continuously calculates the baseline of the sensor readings and compared it to the latest reading from the sensor in order to identify peaks or valleys.
