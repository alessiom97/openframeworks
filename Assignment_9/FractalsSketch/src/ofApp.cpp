#include "ofApp.h"
using namespace std;

int state =0;
int midX, midY, g;
int xT, yT;
int w =10;
int k =200;
int j = 2/3;

bool keydown, keyup;
bool shouldRemove(Line &p){
    if(p.startL.y > ofGetHeight() )return true;
    else return false;
}

//--------------------------------------------------------------
void ofApp::setup(){
    
    myfontTitle.load("sfTrans.ttf", 54);
    myfontSubTitle.load("sfTrans.ttf", 22);
    myfontSubTitle.load("sfTrans.ttf", 22);
    myfontState.load("sfTrans.ttf", 10);
    
    ofSetBackgroundColor(126, 72, 84);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    midX = ofGetWindowWidth()/2;
    midY = ofGetWindowHeight()/2;
    
    xT = midX/2;
    yT = midY/2;
    
    for(int i = 0; i < lines.size(); i++){
        lines[i].update();
    }
    
    ofRemove(lines,shouldRemove);
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    myfontState.drawString("press X for screenshot", midX*1.55, midY*1.9);

    
    if(state == 0){
        menuTitle();
        drawer(midX, midY, k);
    }else if(state == 1){
        myfontState.drawString("drawing1", midX*1.75, midY*1.85);
        lDrawer(midX, midY, k);
    }else if(state == 2){
        myfontState.drawString("modifying2", midX*1.75, midY*1.85);
        for(int i = 0; i < lines.size(); i++){
            lines[i].draw();
        }

    }
    if(state > 3){
        state = 0;
    }
    
//--------------------------------------------------------------
    if (keyup){
        for (int i = 0; i < 10; i++) {
            k++;
        }
    }
    
    if(keydown){
        for (int i = 0; i < 10; i++) {
            k--;
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(key == ' '){
    state++;
        std:: cout << state << endl;

    }
    
    if(key == OF_KEY_RIGHT){
        k = k+10;
        std:: cout << k << endl;
    }
    if(key == OF_KEY_LEFT){
        k = k-10;
        std:: cout << k << endl;

    }
    if(key == OF_KEY_UP){
        keyup = true;
        lines.push_back(Line());


    }
    if(key == OF_KEY_DOWN && w > 10){
        keydown = true;
    }
    
    
    if(key == 'x'){
        img.grabScreen(0, 0 , ofGetWidth(), ofGetHeight());
        img.save("screenshot.png");
    }
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    keydown = false;
    keyup = false;
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

//--------------------------------------------------------------
//void ofApp::randomer(){
//    int randSpacer = ofRandom(0,10);
//    bool randSpacerListener = false;
//
//    int randDelete = ofRandom(0,50);
//    bool randDeleteListener = false;
//    if(randDelete == 7){
//        randDeleteListener = true;
//    }
//    if(randDeleteListener){
//        polyline1.clear();
//    }
//}

//--------------------------------------------------------------
void ofApp::menuTitle(){
    ofSetColor(255,0,0);
    myfontSubTitle.drawString("THE DAO &", xT-169,yT-149);
    myfontTitle.drawString("DESIRE", xT-(xT/2-1),yT-(yT/2-1));
    ofSetColor(255,255,255);
    myfontSubTitle.drawString("THE DAO &", xT-170,yT-150);
    myfontTitle.drawString("DESIRE", xT-(xT/2),yT-(yT/2));
    myfontState.drawString("main menu0", midX*1.75, midY*1.85);
}

//--------------------------------------------------------------
void ofApp::drawer(int x, int y, float radius){

    ofSetBackgroundColor(126, 72, 84);
    ofNoFill();

    ofDrawCircle(x, y, radius);
    if(radius > w){
        drawer(x+radius/2, y, radius/2);
        drawer(x-radius/2, y, radius/2);
        drawer(x, y+radius/2, radius/2);
        drawer(x, y-radius/2, radius/2);
    }
}

//--------------------------------------------------------------
void ofApp::lDrawer(int x, int y, float len){
    if(len>=3){
    ofDrawLine(x-len,y-len/5,x+len,y+len);
    ofDrawLine(x,y-len,x-len,y+len);
    ofDrawLine(x+len,y+len,x,y-len);
    y+= 5;
        
    lDrawer(x-len*1/3,y,len/3);
    lDrawer(x+len*1/3,y,len/3);
    lDrawer(x,y+len*1/3,len/3);
    lDrawer(x,y-len*1/3,len/3);
    }
}

//--------------------------------------------------------------
//void ofApp::vDrawer(ofVec2f start, ofVec2f end, float size){
//
//    vector<float>lines;
////    lines.push_back(10.5);
////    lines.erase(lines.begin());
//    vector<float>:: iterator it = lines.begin();
//    lines.resize(100);
//
//    start.set(0,200);
//    end.set(ofGetWidth(), 200);
//
//    int * kochLines;
//    kochLines = new int[6];
//
//    for(int j = 0; j < lines; j++){
//    ofDrawLine(start.x, start.y, end.x, end.y);
//    }
//
//}


