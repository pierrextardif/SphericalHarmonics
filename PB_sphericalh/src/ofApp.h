#pragma once

#include "ofMain.h"
#include "ofxGui.h"


#include "Harmonics.hpp"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
        void keyPressed(int key);

    ofEasyCam cam;
    
    
    ofColor colorOne = ofColor(0, 0, 0);
    ofColor colorTwo = ofColor::orangeRed;
    
    
    
    
    Harmonics harmonics;
    
    // ==== gui ==== //
    
    ofxPanel gui;
    ofParameter < float > m0Control;
    ofParameter < int > m1Control;
    ofParameter < float > m2Control;
    ofParameter < int > m3Control;
    ofParameter < float > m4Control;
    ofParameter < int > m5Control;
    ofParameter < float > m6Control;
    ofParameter < int > m7Control;
    
    bool guiON = false;
    
    // ==== listeners ==== //
    void updateShapeM0(float& param);
    void updateShapeM1(int& param);
    void updateShapeM2(float& param);
    void updateShapeM3(int& param);
    void updateShapeM4(float& param);
    void updateShapeM5(int& param);
    void updateShapeM6(float& param);
    void updateShapeM7(int& param);
    
};
