//code copied from https://maker.pro/arduino/projects/how-to-send-and-receive-data-through-the-openframeworks-platform-using-arduino
// Code to send and receive data from openFrameworks
bool ledState = false; // Variable for storing the led state
int ledPin = 13;

void setup() {
  // Start the serial communication
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);  // Declaring the LED pin as output
}

void loop() {
  if (Serial.available()) { // If there is any data available
    char inByte = Serial.read(); // store the incoming data
    if (inByte == 1) {    // Whether the received data is '1'
      ledState = !ledState; // Change the LED state
      digitalWrite(ledPin, ledState); // Turn the LED
    }

    if (ledState == true) {
      char mystr[10] = "LED is OFF";
      Serial.write(mystr, 10); // send the response in return
    }
    else if (ledState == false) {
      char mystr[10] = "LED is ON ";      
      Serial.write(mystr, 10); // send the response in return
    }
  }
}
