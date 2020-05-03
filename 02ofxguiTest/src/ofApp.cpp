#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    gui.setup();
    
    gui.add(intSlider.setup("int slider", 64, 3, 64));
    gui.add(floatSlider.setup("float slider", 30, 0, 300));
    
    gui.add(toggle.setup("toggle", false));
    gui.add(button.setup("button"));
    gui.add(label.setup("label", "this is a label"));
    
    gui.add(intField.setup("int field", 20, 0, 100));
    gui.add(floatField.setup("float field", 22, 0, 25));
    gui.add(textField.setup("text field", "text"));
    gui.add(vec2Slider.setup("vec2 slider", ofVec2f(0, 0), ofVec2f(0, 0), ofVec2f(100, 100)));
    gui.add(vec3Slider.setup("vec3 slider - color", ofVec3f(0, 0, 0), ofVec3f(0, 0, 0), ofVec3f(255, 255, 255)));
    gui.add(vec4Slider.setup("vec4 slider", ofVec4f(0, 0, 0, 0), ofVec4f(0, 0, 0, 0), ofVec4f(100, 100, 100, 100)));
    gui.add(colorSlider.setup("color slider", 0, 0, 255));

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofxGuiSetBackgroundColor(ofColor(255,255,0));
    ofSetCircleResolution(intField);
    
    if(toggle){
        //ofSetColor(ofRandom(vec3Slider->x), ofRandom(vec3Slider->y), ofRandom(vec3Slider->z));
        ofSetColor(vec3Slider->x, vec3Slider->y, vec3Slider->z);

    }
    
    ofDrawCircle(500, 300, 100);
    
    ofSetColor(colorSlider);
    ofDrawCircle(800, 300, 100);
    
    gui.draw();
    
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
