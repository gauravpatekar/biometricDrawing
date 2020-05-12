#include "ofApp.h"
#include <stdio.h>
#include <string.h>


//--------------------------------------------------------------
void ofApp::setup(){
    
    serial.listDevices();
    vector <ofSerialDeviceInfo> deviceList = serial.getDeviceList();
    
    int baud = 9600;
    serial.setup(0, baud); //open the first device
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
//    if (serialMessage) {
//        serialMessage = false;
//        serial.writeByte(sendData); // sending the data to arduino
//
//        serial.readBytes(receivedData, 3); // Getting the data from Arduino
//        printf("receivedData is %d \n", receivedData);    // Printing in ASCII format
//    }
    
    if(serial.available()){
        serial.readBytes(receivedData, 3); // Getting the data from Arduino
        printf("receivedData is %d \n", receivedData);    // Printing in ASCII format
        ofSetColor(0, 255, 255);
        ofDrawCircle(300, 300, 10);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(0);    // Black background
    ofSetColor(255);    // Text color is white

    string msg;
    //msg += "Click to turn LED \n";
    msg += receivedData;
    int value = atoi(msg.c_str());
    
    ofDrawBitmapString(msg, 200, 200); // Write the data on the output window
    ofDrawCircle(700, 200, value/3);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    serialMessage = true;

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
