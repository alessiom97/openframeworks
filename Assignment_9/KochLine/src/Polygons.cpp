#include "Polygons.h"

PolygonPoints::PolygonPoints(int init1, ofPoint initMid, float init2){
    sides = init1;
    center = initMid;
    sideLen = init2;
    
    float sumIntAngles = (sides-2) * 180.0;
    float intAngleSides = sumIntAngles / sides;
    float intAngleCenter = 180.0 - intAngleSides;
    
    distFromPoint = sideLen / (2 * sin(ofDegToRad(intAngleCenter/2)) );
    ofPoint radiusVec = ofPoint(0,distFromPoint);
    
    for(int i = 0; i < sides; i++) {
        ofPoint p = radiusVec;
        p.rotate(i * intAngleCenter,*new ofVec3f(0,0));
        p += center;
        points.push_back(p);
    }

}
void PolygonPoints::display(bool showLines, bool showPoints){
    ofSetColor(0,0,0);
    
    for(int i = 0; i < sides; i++) {
        if(showPoints) ofDrawCircle(points[i].x,points[i].y,5);
        if(showLines) {
            int nextPointPos = (i<sides-1)?i+1:0;
        ofDrawLine(points[i].x,points[i].y,points[nextPointPos].x,points[nextPointPos].y);
        }
    }
     ofDrawLine(center.x,center.y,points[0].x,points[0].y);

}
vector<ofPoint> PolygonPoints::getPoints() {
    return points;
}

float PolygonPoints::getDistFromPoint() {
    return distFromPoint;
}

