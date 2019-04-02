#include <vector>
#include "ofMain.h"

class PolygonPoints{

public:

    PolygonPoints(){};
    PolygonPoints(int init1, ofPoint initMid, float init2);
    vector<ofPoint> getPoints();
    float getDistFromPoint();
    void display(bool showLines, bool showPoints);

private:

    float distFromPoint;
    int sides;
    float sideLen;
    ofPoint center;
    vector<ofPoint> points;

};

