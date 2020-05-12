#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    ofSetWindowShape(1024,768);
    leftMouseButtonPressed = false;
    minDistance = 10.0;
    
    //ofxgui code
    gui.setup();
    gui.add(intSlider.setup("int slider", 2, 1, 10));
    gui.add(colorSlider.setup("color slider", 200, 0, 255));

}

//--------------------------------------------------------------
void ofApp::update(){
    
    if (leftMouseButtonPressed) {
        ofPoint mousePos(ofGetMouseX(), ofGetMouseY());
        if (lastPoint.distance(mousePos) >= minDistance) {
            // a.distance(b) calculates the Euclidean distance between point a and b.  It's
            // the straight line distance between the points.
            currentPolyline.curveTo(mousePos);
            lastPoint = mousePos;
        }
    }
    
//    //jitteryness
//    for (int i=0; i<polylines.size(); i++) {
//        for (auto &vert : polylines[i].getVertices()){
//            if(i == polylines.size() -1){
//                vert.x += ofRandom(-1,1);
//                vert.y += ofRandom(-1,1);
//            }
//        }
//     }
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofColor colorA(255, 0, 0);
    
    ofSetColor(colorSlider);
    ofSetLineWidth(intSlider);
    
    for (int i=0; i<polylines.size(); i++) {
        ofPolyline polyline = polylines[i];
        ofSetColor(tempColor[i]);
        ofSetLineWidth(lineWidth[i]);
        polyline.draw();
    }
    //ofSetColor(255,0,0);  // Orange color for active polyline
    currentPolyline.draw();
    
    gui.draw();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
//    for (int i=0; i<polylines.size(); i++) {
//           ofPolyline polyline = polylines[i];
//           polyline.clear();
//       }

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
    
    lineWidth[l] = intSlider;
    tempColor[l] = colorSlider;
    l++;
    
    if (button == OF_MOUSE_BUTTON_LEFT) {
        leftMouseButtonPressed = true;
        currentPolyline.curveTo(x, y);  // Remember that x and y are the location of the mouse
        currentPolyline.curveTo(x, y);  // Necessary duplicate for first control point
        lastPoint.set(x, y);  // Set the x and y of a ofVec2f in a single line
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
    if (button == OF_MOUSE_BUTTON_LEFT) {
        leftMouseButtonPressed = false;
        currentPolyline.curveTo(x, y);   // Necessary duplicate for last control point
        polylines.push_back(currentPolyline);
        currentPolyline.clear();  // Erase the vertices, allows us to start a new brush stroke
    }

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
