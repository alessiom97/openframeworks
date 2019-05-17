#include "ofApp.h"
int a,e = 0;
bool leftB, rightB, upB, downB, shieldB= false;
bool floater = false;
bool statB = true;
bool dead = false;
bool collision = false;
bool transport = false;
int state;
int randU;
int score = 0;
int w = 270;
int h = 266;
int u, t = 0;
int vel = 0;
float noise = 0;
int difficulty = 2;

bool shouldRemove(Line &p){
    if(p.startL.y > ofGetHeight() )return true;
    else return false;
}


//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(1600, 900);
    
    backgroundImg.load("1.png");
    stationary.load("retry/stat.png");
    right.load("retry/left.png");
    left.load("retry/right.png");
    down.load("retry/down.png");
    up.load("retry/up.png");
    skull.load("retry/skull.png");
    shield.load("retry/shield.png");
    
    myfontTitle.load("sfTrans.ttf", 54);
    myScoreTitle.load("sfTrans.ttf", 28);
    mySubTitle.load("sfTrans.ttf", 16);
    
    a = ofGetWidth()/2;
    e = ofGetHeight()-520;
    
    state = 0;
    
    vel = ofRandom(2,10);
    u = 20;
    t = 50;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    u += vel;
    
    vel *= 1.1;
    
    if(u > ofGetWidth()){
        vel = ofRandom(2,20);
        vel += 2;
        u = -30;
        t = ofRandom(0, ofGetHeight());
    }
    
    
    if(!dead){
        score++;
    }
    if(dead){
        score;
    }
    
    ofRemove(lines,shouldRemove);
    
    if(state ==1){
        
        for(int i = 0; i < lines.size(); i++){
            lines[i].update();
        }
        
        if(upB){
            e -= 13;
        }
        if(downB){
            e += 13;
        }
        if(rightB){
            a += 13;
        }
        if(leftB){
            a -= 13;
        }
        
        if(shieldB){
            h-=5;
            if(h < 0){
                h = 1;
                shieldB = false;
            }
        }
        if(!shieldB){
            h+=3;
            if(h > 400){
                h = 399;
            }
        }
        
        if(a+250 > ofGetWidth()){
            a = ofGetWidth()-260;
        }
        if(a < 50){
            a = 50;
        }
        if(e > ofGetHeight()){
            e = ofGetHeight()-50;
        }
        if(e < 50){
            e = 51;
        }
    }
    
    for(int i = 0; i < lines.size(); i++){
        if(ofDist(lines[i].endL.x, lines[i].endL.y, a,e) < 10){
            collision = true;
        }
        if((ofDist(lines[i].endL.x, lines[i].endL.y, a,e) < 200) && shieldB){
            collision = false;
        }
    }
    if(collision){
        state = 2;
        collision = false;
    }
    
    if(state > 2){
        state = 0;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    if(state == 0){
        menuTitle();
    }else if(state == 1){
        gameState();
    }else if(state == 2){
        lossState();
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(state == 1){
        floater = true;
        statB = false;
        
        if (key == OF_KEY_LEFT){
            leftB = true;
        }
        if (key == OF_KEY_RIGHT){
            rightB = true;
        }
        if (key == OF_KEY_UP){
            upB = true;
        }
        if (key == OF_KEY_DOWN){
            downB = true;
        }
        
        if (key == ' ') {
            shieldB = true;
        }
    
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
    if(key == 'x'){
        state = state + 1;
    }
    if (key == OF_KEY_LEFT){
        leftB = false;
    }
    if (key == OF_KEY_UP){
        upB = false;
    }
    if (key == OF_KEY_DOWN){
        downB = false;
    }
    if (key == OF_KEY_RIGHT){
        rightB = false;
    }
    if (key == ' ') {
        shieldB = false;
    }
    if (key == 't'){
        transport = false;
    }
    
    statB = true;
    
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
void ofApp:: menuTitle(){
    ofSetBackgroundColor(255,255,255);
    ofPushStyle();
    ofSetColor(255,0,0);
    myfontTitle.drawString("SKELLY", ofGetWidth()/2-150, ofGetHeight()/2);
    mySubTitle.drawString("AVOID FALLING SPIKES- SPACE BAR FOR INVULNERABILITY", ofGetWidth()/2-380, ofGetHeight()/2+50);
    if (int(ofGetElapsedTimef()) % 2 == 1){
        mySubTitle.drawString("PRESS X TO START", ofGetWidth()/2-150, ofGetHeight()/2+100);
    }
    ofPopStyle();

    skull.draw(u,t);
    stationary.draw(u-91,t+70);
}

//--------------------------------------------------------------
void ofApp:: gameState(){
    ofSetBackgroundColor(255,255,255);
    
    dead = false;
    ofPushMatrix();
    skull.draw(a,e);
    
    if(rightB){
        left.draw(a-90,e+70);
    }
    else if(leftB){
        right.draw(a+20,e+70);
    }
    else if(statB){
        stationary.draw(a-91,e+70);
    }
    else if(upB){
        up.draw(a-65,e+70);
    }
    else if(downB){
        down.draw(a-65,e-135);
    }

    ofPopMatrix();
    if(shieldB){
        ofPushStyle();
        shield.draw(a-102,e-90,270,266);
        ofSetColor(0, 0, 0);
        ofDrawRectangle(ofGetWidth()-200, ofGetHeight()-600, 30, 400);
        ofPopStyle();
        ofSetColor(255, 255, 255);
        ofDrawRectangle(ofGetWidth()-201, ofGetHeight()-600, 29, h);
    }
    for(int i = 0; i < lines.size(); i++){
        lines[i].draw();
    }
    lines.push_back(Line());
    
    ofPushStyle();
    ofSetColor(255, 0, 0);
    myScoreTitle.drawString("SCORE "+to_string(score), 85, ofGetWindowHeight()-100);
    ofPopStyle();
}

void ofApp:: lossState(){
    dead= true;
    
    ofPushStyle();
    ofBackground(255, 0, 0);
    ofSetColor(255, 255, 255);
    myScoreTitle.drawString("DEAD AT = "+to_string(score), ofGetWidth()/2-150, ofGetHeight()/2);
    if (int(ofGetElapsedTimef()) % 2 == 1){
    mySubTitle.drawString("TRY AGAIN?", ofGetWidth()/2-100, ofGetHeight()/2+100);
    }
    ofPopStyle();
    skull.draw(a,e);
    a++;
}
