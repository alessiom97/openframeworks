#include "ofApp.h"
using namespace std;

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    
    ofPoint st = ofPoint(ofGetWindowWidth()/3, ofGetWindowHeight()/3);
    ofPoint ed = ofPoint(2 * ofGetWindowWidth() / 3,ofGetWindowHeight()/3);
    
    kl.push_back(KochLine(st,ed,5));


    pp = PolygonPoints(6,ofPoint(ofGetWidth() / 2 ,ofGetHeight()/2),300.0);
    pp2 = PolygonPoints(3,ofPoint(ofGetWidth() / 2,ofGetHeight()/2),420);
    
    vector<ofPoint> hexPoints = pp.getPoints();
//    std:: cout << pp.getPoints() << endl;
    for(int i= 0; i < hexPoints.size(); i++){
        int nextPointPos = (i<hexPoints.size()-1)?i+1:0;
//        std::cout << nextPointPos << endl;
        kl.push_back(KochLine(hexPoints[nextPointPos],hexPoints[i],5));
    }
    
    hexPoints = pp2.getPoints();
    for(int i= 0; i < hexPoints.size(); i++){
        int nextPointPos = (i<hexPoints.size()-1)?i+1:0;
        kl2.push_back(KochLine(hexPoints[nextPointPos],hexPoints[i],5));
    }

}

//--------------------------------------------------------------
void ofApp::update(){
    ofBackground(255);

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for(int i= 0; i < kl.size(); i++){
        
//        std:: cout <<"wassap"<< endl;
//        std:: cout <<kl.size()<< endl;
        kl[i].display();
//        std:: cout <<"vectors " << endl;
//        std:: cout << display_vector() << endl;
    }
    for(int i= 0; i < kl2.size(); i++){
        kl2[i].display();
    }

    pp2.display(false,false);

}

//void ofApp:: display_vector(const vector<int> &kl)
//{
//    std::copy(kl.begin(), kl.end(),
//              std::ostream_iterator<int>(std::cout, " "));
//}
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

