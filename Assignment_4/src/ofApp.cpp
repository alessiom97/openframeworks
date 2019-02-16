#include "ofApp.h"
#include <iostream>
int midX, midY;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    midX = ofGetWidth() / 2;
    midY = ofGetHeight() / 2;
    ofSetBackgroundColor(255, 255, 255);
}

bool drawFirst = true;
bool drawSecond = true;
bool drawThird = true;
bool drawFourth = true;

ofColor mouth(255, 255, 255);
ofColor body(17, 30, 54);
ofColor contour(255, 255, 255);
//ofColor body(72, 60, 70);
//ofColor mouth(66,76,85);
ofColor eyes(26,97,153);
ofColor red(186, 18, 0);
//--------------------------------------------------------------
void ofApp::update(){
    int sec = (ofGetFrameNum()/60) %60;
    drawFirst = sec < 2;
    drawSecond = sec < 4;
    drawThird = sec < 6;
    drawFourth = sec < 8;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(body);
    ofSetLineWidth(5);
    ofSetCircleResolution(100);
    ofDrawCircle(650, 360, 225);
    ofDrawLine(510, 310, 620, 390);
    ofDrawLine(690, 390, 800, 310);
    
    if(drawFirst){
        eyesNarrow(); //Angry
        mouthHappy();
    }
    else if(drawSecond){
        eyesCrying(); //Sad
        mouthAngry();
    
}
    else if(drawThird){
        eyesOpen(); //Happy
        mouthHappy();
    }
    else if(drawFourth){
        eyesSurprise();     //Surprise
        mouthAngry();
    }
    cout << mouseX << endl;
    cout << mouseY << endl;
}
//--------------------------------------------------------------
void eyesOpen(){
    ofFill();
    ofSetColor(red);
    ofDrawTriangle(460, 380, 620, 390, 510, 310);
    ofDrawTriangle(690, 390, 850, 380, 800, 310);
    
}
//--------------------------------------------------------------
void mouthHappy(){
    ofFill();
    ofSetColor(mouth);
    ofDrawBezier(470, 440, 660, 550, 660, 550, 850, 410);
    cout << "im prada you" << endl;
}

void mouthAngry(){
    ofFill();
    ofSetColor(mouth);
    ofDrawBezier(470, 580, 660, 280, 660, 280, 850, 550);
    cout << "whats gucci" << endl;
}
//--------------------------------------------------------------
void eyesNarrow(){
    
    ofFill();
    
    ofPushMatrix();
    ofSetColor(contour);
    ofDrawLine(480, 285, 630, 350);
    ofDrawLine(695, 350, 845, 285);
    ofDrawBezier(485, 290, 515, 370, 575, 400, 630, 350);
    ofDrawBezier(695, 350, 740, 400, 800, 375, 840, 285);
    ofPopMatrix();
    
    ofSetColor(eyes);
    ofDrawLine(480, 285, 630, 350);
    ofDrawLine(695, 350, 845, 285);
    ofDrawBezier(485, 290, 515, 370, 575, 400, 630, 350);
    ofDrawBezier(695, 350, 740, 400, 800, 375, 840, 285);
}
//--------------------------------------------------------------
void eyesCrying(){
    ofFill();
    ofSetColor(red);
    ofDrawLine(480, 285, 630, 350);
    ofDrawLine(695, 350, 845, 285);
    ofDrawBezier(485, 290, 430, 400, 520, 315, 630, 350);
    ofDrawBezier(695, 350, 785, 315, 895, 400, 840, 290);
}

void eyesSurprise(){
    ofFill();
    ofSetColor(red);
    ofDrawLine(527, 350, 627, 350);
    ofDrawLine(730, 350, 830, 350);
    ofDrawBezier(527, 350, 527, 150, 627, 150, 627, 350);
    ofDrawBezier(730, 350, 730, 150, 830, 150, 830, 350);
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

