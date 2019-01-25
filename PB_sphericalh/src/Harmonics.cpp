//
//  Harmonics.cpp
//  PB_01
//
//  Created by Pierre Tardif on 23/01/2019.
//

#include "Harmonics.hpp"

void Harmonics::setup(){
    m0 = 1.0;
    m1 = 1.0;
    m2 = 1.0;
    m3 = 1.0;
    m4 = 1.0;
    m5 = 1.0;
    m6 = 1.0;
    m7 = 1.0;
    
    
    // ==== shape ==== //
    std::vector < ofVec3f > vPoints;
    std::vector < ofVec3f > vPointsNext;
    
    for( float u = - M_PI; u < M_PI; u += precision){
        for( float v = - M_PI; v < M_PI; v += precision){
            
            
            
            
            float phi = u;
            float theta = v;
            float r = pow(sin(m0 * phi), m1) +   pow(cos(m2 * phi), m3) +   pow(sin(m4 * theta), m5) +   pow(cos(m6 * theta), m7);
            
            float xPos = r * cos(theta) * sin(phi) * size;
            float zPos = r * sin(theta) * sin(phi) * size;
            float yPos = r * cos(phi) * size;
            
            ofVec3f point = {xPos, yPos, zPos};
            vPoints.push_back(point);
            
            
            
            phi = u + precision;
            theta = v;
            r = pow(sin(m0 * phi), m1) +   pow(cos(m2 * phi), m3) +   pow(sin(m4 * theta), m5) +   pow(cos(m6 * theta), m7);
            
            xPos = r * cos(theta) * sin(phi) * size;
            zPos = r * sin(theta) * sin(phi) * size;
            yPos = r * cos(phi) * size;
            point = {xPos, yPos, zPos};
            vPointsNext.push_back(point);
            
            
        }
    }
    
    
    int indexvertex = 0;
    
    
    vbo.setMode(OF_PRIMITIVE_TRIANGLES);
    for(int i =0; i < vPoints.size()-1; i ++){
        
        ofVec3f pos = vPoints[i];
        
        vbo.addVertex(pos);
        vbo.addIndex(indexvertex);
        indexvertex ++;
        
        
        pos = vPoints[i+1];
        vbo.addVertex(pos);
        vbo.addIndex(indexvertex);
        indexvertex ++;
        
        pos = vPointsNext[i];
        vbo.addVertex(pos);
        vbo.addIndex(indexvertex);
        indexvertex ++;
        
        
        pos = vPointsNext[i];
        vbo.addVertex(pos);
        vbo.addIndex(indexvertex);
        indexvertex ++;
        
        pos = vPoints[i+1];
        vbo.addVertex(pos);
        vbo.addIndex(indexvertex);
        indexvertex ++;
        
        pos = vPointsNext[i+1];
        vbo.addVertex(pos);
        vbo.addIndex(indexvertex);
        indexvertex ++;
        
    }
    
    
}

//--------------------------------------------------------------
void Harmonics::update(){
    std::vector < float > factors = {m0, m1, m2, m3, m4, m5,m6,m7};
    
    updateVbo(&vbo, factors);
}

//--------------------------------------------------------------
void Harmonics::draw(){
    
}

//--------------------------------------------------------------
void Harmonics::updateVbo(ofVboMesh* vbo, std::vector < float > factors){
    
    int indexVertex = 0;
    
    for( float u = - M_PI; u <= M_PI; u += precision){
        for( float v = - M_PI; v <= M_PI; v += precision){
            
            float m2 = factors[0];
            float m3 = factors[1];
            float m4 = factors[2];
            float m5 = factors[3];
            float m6 = factors[4];
            float m7 = factors[5];
            
            float phi = u;
            float theta = v;
            
            float r = pow(sin(m0 * phi), m1) +   pow(cos(m2 * phi), m3) +   pow(sin(m4 * theta), m5) +   pow(cos(m6 * theta), m7);
            updateOneVertex(r,theta, phi, size, &indexVertex, vbo);
            
            phi = u;
            theta = v + precision;
            
            r = pow(sin(m0 * phi), m1) +   pow(cos(m2 * phi), m3) +   pow(sin(m4 * theta), m5) +   pow(cos(m6 * theta), m7);
            updateOneVertex(r,theta, phi, size, &indexVertex, vbo);
            
            phi = u + precision;
            theta = v;
            
            r = pow(sin(m0 * phi), m1) +   pow(cos(m2 * phi), m3) +   pow(sin(m4 * theta), m5) +   pow(cos(m6 * theta), m7);
            updateOneVertex(r,theta, phi, size, &indexVertex, vbo);
            
            phi = u + precision;
            theta = v;
            
            r = pow(sin(m0 * phi), m1) +   pow(cos(m2 * phi), m3) +   pow(sin(m4 * theta), m5) +   pow(cos(m6 * theta), m7);
            updateOneVertex(r,theta, phi, size, &indexVertex, vbo);
            
            phi = u;
            theta = v + precision;
            
            r = pow(sin(m0 * phi), m1) +   pow(cos(m2 * phi), m3) +   pow(sin(m4 * theta), m5) +   pow(cos(m6 * theta), m7);
            updateOneVertex(r,theta, phi, size, &indexVertex, vbo);
            
            phi = u + precision;
            theta = v + precision;
            
            r = pow(sin(m0 * phi), m1) +   pow(cos(m2 * phi), m3) +   pow(sin(m4 * theta), m5) +   pow(cos(m6 * theta), m7);
            updateOneVertex(r,theta, phi, size, &indexVertex, vbo);
        }
    }
}

//--------------------------------------------------------------
void Harmonics::updateOneVertex(float r, float theta, float phi, float size, int* indexVertex, ofVboMesh* vbo){
    
    float xPos = r * cos(theta) * sin(phi) * size;
    float zPos = r * sin(theta) * sin(phi) * size ;
    float yPos = r * cos(phi) * size + r * size;
    
    ofVec3f point = {xPos, yPos, zPos};
    
    vbo->setVertex(*indexVertex, point);
    *indexVertex += 1;
    
}
