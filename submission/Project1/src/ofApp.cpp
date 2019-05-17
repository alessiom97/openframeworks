#include "ofApp.h"
int midX, midY, x, y;
int state = 1;
//--------------------------------------------------------------
void ofApp::setup(){
    midX = ofGetWidth()/2;
    midY = ofGetWidth()/2;
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofDrawBitmapString(ofGetElapsedTimef(), 50, 50);

    
    if(state == 1){
    ofSetBackgroundColor(255, 255, 255);
    ofSetColor(0,255,0);
    ofTranslate(ofGetElapsedTimef()*10, 10);
    ofRotate(ofGetElapsedTimef()*10, 1, 1, 0);
    ofDrawRectangle(midX-50, midY-50, 50, 50);
    ofSetColor(0,0,255);
    ofDrawTriangle(midX-55, midY-55, midX, midY+10, midX+55, midY);
    }
    if (int(ofGetElapsedTimef()) % 5 == 1){
        state = 2;
    } else if (int(ofGetElapsedTimef()) % 10 == 2){
        state = 3;
    } else if(ofGetElapsedTimef()>20&&ofGetElapsedTimef() < 80){
        state = 4;
    } else if(int(ofGetElapsedTimef()) % 30 == 3){
        state = 5;
    } else if (int(ofGetElapsedTimef()> 50)){
        state = 6;
    }
    if(state ==2){
        ofDrawCircle(midX+75, midY-100, 89);
        ofSetColor(244, 109, 154);
        ofRotate(ofGetElapsedTimef()*30, 1, 0, 0);
        ofDrawCircle(midX+75, midY-64, 55);
        ofSetColor(14, 100, 192);
        ofSetColor(255,255,255);
        ofDrawBitmapString("in my soul you are as alive as you ever were", 100, 200);

    }
    if(state == 3){
        ofPopMatrix();
        ofTranslate(ofGetElapsedTimef()*2, 100);
        if (ofGetElapsedTimef()*2 > ofGetWidth()) {
            ofTranslate(ofGetElapsedTimef()*0*2, 100);
        }
        ofSetBackgroundColor(135, 144, 201);
        ofDrawEllipse(midX+100, midY+38, 109, 33);
        ofPushMatrix();
    }
    if(state == 4){
        ofDrawCircle(midX+=50, 55, 309);
        ofSetColor(14, 100, 192);
        ofSetColor(255, 255, 255);
        ofDrawBitmapString("the room was filled with your presence and now it is filled with your absence", 100, 200);
        ofDrawLine(100, midY, ofGetWidth(), ofGetHeight());
        ofRotate(ofGetElapsedTimef()*10, 1, 0, 0);
        ofDrawLine(110, midY, ofGetWidth(), ofGetHeight());
        ofRotate(ofGetElapsedTimef()*10, 1, 0, 0);
        ofDrawLine(120, midY, ofGetWidth(), ofGetHeight());
        ofRotate(ofGetElapsedTimef()*10, 1, 0, 0);
        ofDrawLine(130, midY, ofGetWidth(), ofGetHeight());
        ofRotate(ofGetElapsedTimef()*10, 1, 0, 0);
        ofDrawLine(140, midY, ofGetWidth(), ofGetHeight());

    }
    if(state == 5){
        ofSetColor(255, 10, 50);
        ofRotate(ofGetElapsedTimef()*3, 0, 1, 0);
        ofDrawTriangle(400, midY+90, midX-199, midY+300, midX+399, 0);
    }
               if(state == 6){
                   ofSetColor(0,0,0);
                   ofDrawRectangle(100, 100, 300, 300);
                   ofSetColor(0, 244, 100);
                   ofDrawBitmapString("absence", 100, 250);
                   ofDrawBitmapString("absence", 150, 200);
                   ofDrawBitmapString("absence", 200, 300);
                   ofDrawBitmapString("absence", 250, 350);
                   ofDrawBitmapString("absence", 300, 500);
                   ofDrawBitmapString("absence", 350, 400);
                   ofDrawBitmapString("absence", 400, 450);
                   ofDrawBitmapString("faith walks alongside me now", 450, 200);
               }
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
void ofApp::happyFace(){
}
