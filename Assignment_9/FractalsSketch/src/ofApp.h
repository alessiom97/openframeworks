#pragma once

#include "ofMain.h"

class Line{
public:
    Line(){
        startL.set( 0, 0, 0);
        endL.set(ofGetWindowWidth()/2,ofGetWindowHeight()/2, 0);
        vel.set( ofRandom(-5,5), ofRandom(-4,-8), 0);
    }
    
    void update(){
        
        
        startL += vel;
        endL += vel;
        vel.y += .05;
        
        
    }
    
    void draw(){
        
        
        ofDrawLine(startL.x,startL.y,endL.x, endL.y);
        
        cout << startL.x << endl;
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
        void randomer();
        void menuTitle();
        void drawer(int x, int y, float radius);
        void lDrawer(int z, int w, float len);
        void vDrawer(ofVec2f start, ofVec2f end, float size);
    
    vector<Line>lines;
    ofTrueTypeFont myfontTitle;
    ofTrueTypeFont myfontSubTitle;
    ofTrueTypeFont myfontState;
    
    ofPolyline polyline1;
    ofPolyline polyline2;
    
    ofImage     img;
    ofVec2f start;
    ofVec2f end;
    
};
