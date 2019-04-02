#include "KochLine.h"

KochLine::KochLine(ofPoint a, ofPoint b, int iterations){
    Koch1 kl = Koch1(a,b);
    lines.push_back(kl);
    for(int i = 0; i < iterations; i++) {
        generateLines();
        std:: cout << "mypoint" << endl;
        std:: cout << a << endl;
        std:: cout << b << endl;

    }
}

void KochLine::display(){
    ofSetColor(0,0,0);
    for(int i = 0;  i < lines.size(); i++ ) {
        lines[i].display();
    }
}

void KochLine::generateLines(){
    std::vector<Koch1>next;
    
    for(int i = 0;  i < lines.size(); i++ ) {
        ofPoint a = lines[i].kochA();
        ofPoint b = lines[i].kochB();
        ofPoint c = lines[i].kochC();
        ofPoint d = lines[i].kochD();
        ofPoint e = lines[i].kochE();
        
        next.push_back( Koch1(a,b));
        next.push_back( Koch1(b,c));
        next.push_back( Koch1(c,d));
        next.push_back( Koch1(d,e));
    }
    lines = next;
}

KochLine::Koch1::Koch1(ofPoint a, ofPoint b){
    start = a;
    end = b;
}
ofPoint KochLine::Koch1::kochA(){
    return start;
}

ofPoint KochLine::Koch1::kochB(){
    ofPoint v = end-start;
    v /= 3;
    v += start;
    return v;
}
ofPoint KochLine::Koch1::kochC(){
    ofPoint a = start;
    ofPoint v = end - start;
    v /= 3;
    a += v;
    v.rotate(-60, *new ofVec3f(0,0));
    a += v ;
    return a;
}
ofPoint KochLine::Koch1::kochD(){
    ofPoint v = end-start;
    v *= (2/3.0);
    v += start;
    return v;
}

ofPoint KochLine::Koch1::kochE(){
    return end;
}
void KochLine::Koch1::display() {
    ofSetColor(255, 0, 0);
    ofDrawLine(start.x, start.y, end.x, end.y);

}
