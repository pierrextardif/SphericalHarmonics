
#include "ofApp.h"

void ofApp::setup()
{
    cam.setDistance(600);
    harmonics.setup();
    
    float rad = 1000.0;
    
    gui.setup("harmonicControls");
    gui.add(m0Control.set("m0Control", 0.0, -rad, rad));
    gui.add(m1Control.set("m1Control", 0, 0, 100));
    gui.add(m2Control.set("m2Control", 0.0, -rad, rad));
    gui.add(m3Control.set("m3Control", 0, 0, 100));
    gui.add(m4Control.set("m4Control", 0.0, -rad, rad));
    gui.add(m5Control.set("m5Control", 0, 0, 100));
    gui.add(m6Control.set("m6Control", 0.0, -rad, rad));
    gui.add(m7Control.set("m7Control", 0, 0, 100));
    
    // ==== listeners to the controls ==== //
    
    m0Control.addListener(this, &ofApp::updateShapeM0);
    m1Control.addListener(this, &ofApp::updateShapeM1);
    m2Control.addListener(this, &ofApp::updateShapeM2);
    m3Control.addListener(this, &ofApp::updateShapeM3);
    m4Control.addListener(this, &ofApp::updateShapeM4);
    m5Control.addListener(this, &ofApp::updateShapeM5);
    m6Control.addListener(this, &ofApp::updateShapeM6);
    m7Control.addListener(this, &ofApp::updateShapeM7);

};

//--------------------------------------------------------------
void ofApp::update(){    
};

void ofApp::draw(){
    
    ofBackground(0);
    cam.begin();
    ofRotateY(ofGetElapsedTimeMillis() * 0.01);
    ofSetColor(220, 220, 200, 100);
        harmonics.vbo.drawWireframe();
    cam.end();
    
    if(guiON){
        ofShowCursor();
        gui.draw();
    }else{
        ofHideCursor();
    }
};

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'g'){
        guiON = !guiON;
        
    }
};

//--------------------------------------------------------------
void ofApp::updateShapeM0(float& param){
    harmonics.m0 = param;
    harmonics.update();
}

//--------------------------------------------------------------
void ofApp::updateShapeM1(int& param){
    harmonics.m1 = param;
    harmonics.update();
}

//--------------------------------------------------------------
void ofApp::updateShapeM2(float& param){
    harmonics.m2 = param;
    harmonics.update();
}

//--------------------------------------------------------------
void ofApp::updateShapeM3(int& param){
    harmonics.m3 = param;
    harmonics.update();
}

//--------------------------------------------------------------
void ofApp::updateShapeM4(float& param){
    harmonics.m4 = param;
    harmonics.update();
}

//--------------------------------------------------------------
void ofApp::updateShapeM5(int& param){
    harmonics.m5 = param;
    harmonics.update();
}

//--------------------------------------------------------------
void ofApp::updateShapeM6(float& param){
    harmonics.m6 = param;
    harmonics.update();
}

//--------------------------------------------------------------
void ofApp::updateShapeM7(int& param){
    harmonics.m7 = param;
    harmonics.update();
}
