#pragma once

#include "ofMain.h"

class Line{
public:
    Line(){
        startL.set( -50, -50, 0);
        endL.set(0,0, 0);
        vel.set( ofRandom(-5,5), ofRandom(-4,-8), 0);
        startC.set(-35,-35,0);
        endC.set(0,0,0);

        
    }
    
    void update(){
        startL += vel;
        endL += vel;
        startC += vel;
        endC += vel;
        vel.y += .08;
        vel.x += .05;

    
    }
    
    void draw(){
        ofPushStyle();
        ofSetColor(255,0,0);
        ofDrawLine(startL.x,startL.y,endL.x, endL.y);
        ofDrawRectangle(startC.x, startC.y, 10, 10);
        ofPopStyle();
        
    }
    
    bool step1;
    bool step2;
    
    ofPoint a;
    ofPoint b;
    ofPoint c;
    ofPoint d;
    ofPoint e;
    
    ofPoint startL;
    ofPoint endL;
    ofPoint startC;
    ofPoint endC;
    
    ofVec3f vel;
    
};


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        void menuTitle();
        void gameState();
        void lossState();
    
    vector<Line>lines;

    ofImage backgroundImg;
    ofImage stationary;
    ofImage right;
    ofImage left;
    ofImage up;
    ofImage down;
    ofImage skull;
    ofImage shield;
    
    ofTrueTypeFont myfontTitle;
    ofTrueTypeFont mySubTitle;
    ofTrueTypeFont myScoreTitle;

};
