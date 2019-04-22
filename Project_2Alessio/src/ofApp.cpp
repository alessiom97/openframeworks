#include "ofApp.h"
ofVec3f v[6];
ofVec3f n[6];
ofFloatColor c[6];
ofVbo vbo;
int midX, midY, x, y, backgroundChecker, currTime;
string sunStrengthNum, windGustNum, windSpeedNum, moonPhaseNum, currTimeNum;
float windSpeed, windGust, sunStrength, sunRise, sunSet, moonPhase = 0;
bool doit, changeC, changeB, UIDOIT = false;

const float Verts[] = {
    0.000f,  0.000f, 1.000f,
    0.894f,  0.000f, 0.447f,
    0.276f,  0.851f, 0.447f,
    -0.724f, 0.526f, 0.447f,
    -0.724f, -0.526f, 0.447f,
    0.276f, -0.851f, 0.447f,
    0.724f,  0.526f, -0.447f,
    -0.276f, 0.851f, -0.447f,
    -0.894f, 0.000f, -0.447f,
    -0.276f, -0.851f, -0.447f,
    0.724f, -0.526f, -0.447f,
    0.000f, 0.000f, -1.000f
};

const ofIndexType Faces[]{
    2, 1, 0,
    3, 2, 0,
    4, 3, 0,
    5, 4, 0,
    1, 5, 0,
    11, 6,7,
    11, 7, 8,
    11, 8, 9,
    11, 9, 10,
    11, 10, 6,
    1, 2, 6,
    2, 3, 7,
    3, 4, 8,
    4, 5, 9,
    5, 1, 10,
    2, 7, 6,
    3, 8, 7,
    4, 9, 8,
    5, 10, 9,
    1, 6, 10
};
//--------------------------------------------------------------

void ofApp::setup(){
    
    weatherData.load("sfTrans.ttf", 12);

    gui.setup();
    gui.add(uvIndex.setup("UV INDEX", 25, 0, 100));
    gui.add(windGustSlider.setup("WIND GUST", 1, 0, 10));
    gui.add(windSpeedSlider.setup("WIND SPEED", 1, 0, 10));
    gui.add(colorR.setup("RED", ofRandom(1.0), 0, 1));
    gui.add(colorB.setup("GREEN", ofRandom(1.0), 0, 1));
    gui.add(colorG.setup("BLUE", ofRandom(1.0), 0, 1));


    std::string url = "https://api.darksky.net/forecast/4187ebfda41b046e6cf6a4386211410c/42.3601,-71.0589";
    bool parsingSuccessful = json.open(url);
    if (parsingSuccessful)
    {ofLogNotice("ofApp::setup") << json.getRawString(true);} else {ofLogNotice("ofApp::setup") << "Failed to parse JSON.";}

    for (int i = 0; i < 6; i++ ){
        c[i].r = ofRandom(1.0);
        c[i].g = ofRandom(1.0);
        c[i].b = ofRandom(1.0);
    }
    
    midX = ofGetWidth();
    midY = ofGetHeight();
}

//--------------------------------------------------------------
void ofApp::update(){
    windSpeed = json["currently"]["windSpeed"].asFloat();
    windSpeedNum = json["currently"]["windSpeed"].asString();
    windGust = json["currently"]["windGust"].asFloat();
    windGustNum = json["currently"]["windGust"].asString();
    sunStrength = json["daily"]["data"][0]["uvIndex"].asFloat();
    sunStrengthNum = json["daily"]["data"][0]["uvIndex"].asString();
    currTime = json["currently"]["time"].asInt();
    currTimeNum = json["currently"]["time"].asString();
    sunRise = json["daily"]["data"][0]["SunriseTime"].asFloat();
    sunSet = json["daily"]["data"][0]["SunsetTime"].asFloat();
    moonPhase = json["daily"]["data"][0]["moonPhase"].asFloat();
    moonPhaseNum = json["daily"]["data"][0]["moonPhase"].asString();
    
    
    
    int i, j = 0;
    
    for ( i = 0; i < 6; i++ ){
        if(!doit){
        v[i][0] = Verts[j] * int(300+ (10*sunStrength));
            j++;
        v[i][1] = Verts[j] * int(300+ (5*sunStrength));
            j++;
        }
        if(doit){
        v[i][0] = Verts[j] * int(100+ (10*(20*moonPhase)));
            j++;
        v[i][1] = Verts[j] * int(100+ (10*(20*moonPhase)));
            j++;
        v[i][2] = Verts[j] * int(100+ (10*(20*moonPhase)));
            j++;
        }
        if(UIDOIT){
            sunStrength = uvIndex;
            moonPhase = uvIndex;
        }
    }
    
    
    
    for (int i = 0; i < 6; i++ ){
//        c[i].r = ofRandom(colorR);
//        c[i].g = ofRandom(colorG);
//        c[i].b = ofRandom(colorB);
//
        if(changeC){
//            colorR = ofRandom(1.0);
//            colorG = ofRandom(1.0);
//            colorB = ofRandom(1.0);
            c[i].r = ofRandom(1.0);
            c[i].g = ofRandom(1.0);
            c[i].b = ofRandom(1.0);
        }
        
        if(UIDOIT){
        for (int i = 0; i < 6; i++ ){
            c[i].r = ofRandom(colorR);
            c[i].g = ofRandom(colorG);
            c[i].b = ofRandom(colorB);
            if(changeC){
            colorR = ofRandom(1.0);
            colorG = ofRandom(1.0);
            colorB = ofRandom(1.0);
        
            }
            }
        }
        std:: cout<<"color val"<< endl;
        std:: cout<<colorR<<endl;
    }
    
    vbo.setVertexData( &v[0], 6, GL_STATIC_DRAW );
    vbo.setColorData( &c[0], 6, GL_STATIC_DRAW );
    vbo.setIndexData( &Faces[0], 60, GL_STATIC_DRAW );
    glEnable(GL_DEPTH_TEST);

    backgroundChecker = ofLerp(currTime, sunSet, 3);
    
    if(doit){
    ofBackground(17,17,40);
    }else{
    ofBackground(211,179,52);
    }
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofPushMatrix();
    
   int windSpeedAdj = ofMap(windSpeed, 1, 30, 35, 100);
   int windGustAdj = ofMap(windGust, 1, 30, 10, 50);

    if(UIDOIT){
        windGustAdj = windGustSlider;
        windSpeedAdj = windSpeedSlider;
        
        ofSetColor(255,255,255);
        gui.draw();
    }
    
    ofRotate((ofGetElapsedTimef()*(15+windSpeedAdj)), 0.7, 0.5, 0.1);
    ofTranslate(ofGetWidth()/2-50, ofGetHeight()/2-50, 0);

    std:: cout << "Wind Speed Adjusted" << endl;
    std:: cout <<windSpeedAdj << endl;
    std:: cout << "Wind Gust Adjusted" << endl;
    std:: cout <<windGustAdj << endl;
    std:: cout << "UV Index" << endl;
    std:: cout <<sunStrength << endl;
    std:: cout << "Moon Phase" << endl;
    std:: cout <<moonPhase << endl;
    std:: cout << "Time" << endl;
    std:: cout <<currTime<< endl;
    
    glPointSize(1.f);
    int numRay = 5+sunStrength;
    for(int i = 0; i < numRay; i++){
        ofRotate(ofGetElapsedTimef() * (15+windGustAdj), 1, 0, 1);
        vbo.drawElements( GL_POLYGON, 60);
        std:: cout << numRay << endl;
    }
    ofPopMatrix();
    
    int x = ofGetWidth()-300;
    int y = ofGetHeight()-100;
    weatherData.drawString("WIND GUST = ", x, y-200);
    weatherData.drawString(windGustNum, x+170, y-200);
    weatherData.drawString("WIND SPEED = ", x, y-150);
    weatherData.drawString(windSpeedNum, x+170, y-150);
    weatherData.drawString("MOONPHASE = ", x, y-100);
    weatherData.drawString(moonPhaseNum, x+170, y-100);
    weatherData.drawString("UV INDEX = ", x, y-50);
    weatherData.drawString(sunStrengthNum, x+170, y-50);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if( key == 'x'){
        doit = !doit;
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2, 100);
        
    }
    if( key == 'c'){
        changeC = true;
    }
    if( key == 'u'){
        UIDOIT = !UIDOIT;
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    changeC = false;

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
