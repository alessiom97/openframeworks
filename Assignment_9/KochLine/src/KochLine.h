#pragma once
#include "ofMain.h"

class KochLine{
public:
    KochLine(){};
    KochLine(ofPoint a, ofPoint b, int iterations);
    
    void display();
    void generateLines();
    ofVec3f vel;
private:
    
    class Koch1{
    public:
        Koch1() {};
        Koch1(ofPoint a, ofPoint b);
        void display();
        
        ofPoint kochA();
        ofPoint kochB();
        ofPoint kochC();
        ofPoint kochD();
        ofPoint kochE();
        
    private:
        ofPoint start;
        ofPoint end;
    };
    
    vector<Koch1> lines;
};
