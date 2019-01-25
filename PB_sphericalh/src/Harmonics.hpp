//
//  Harmonics.hpp
//  PB_01
//
//  Created by Pierre Tardif on 23/01/2019.
//

#ifndef Harmonics_hpp
#define Harmonics_hpp

#include <stdio.h>
#include "ofMain.h"

class Harmonics{
    
    public :
    
    float precision = 0.05;
    float size = 100.0;
    
    // formula parameters
    float m0 = 3.9;
    float m1 = 12.0;
    float m2 = 0.9;
    float m3 = 0.7;
    float m4 = 0.3;
    float m5 = 1.0;
    float m6 = 0.5;
    float m7 = 0.3;
    
    
    
    ofVboMesh vbo;
    
    Harmonics(){
    
    };
    
    void setup();
    void update();
    void draw();
    
    void updateVbo(ofVboMesh* vbo, std::vector < float > factors);
    void updateOneVertex(float r, float theta, float phi, float size, int* indexVertex, ofVboMesh* vbo);
    
};

#endif /* Harmonics_hpp */
