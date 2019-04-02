#pragma once

#include "ofMain.h"
#include "KochLine.h"
#include "Polygons.h"


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
        void display_vector(const vector<int> &kl);
    
    vector<KochLine> kl;
    PolygonPoints pp;
    vector<KochLine> kl2;
    PolygonPoints pp2;
};
