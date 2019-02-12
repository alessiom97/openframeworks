#include "ofApp.h"

int size = 10;
int step = 1;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);

}
//--------------------------------------------------------------
void ofApp::update(){
    size += step;
    
    if(size > 200 || size < 10){
        step *= -1;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    int midX = ofGetWindowWidth();
    int midY = ofGetWindowHeight();
    
    ofSetColor(50, 80, 50);
    ofDrawRectangle(50, 50, size, size);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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
