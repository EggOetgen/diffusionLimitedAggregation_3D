//
//  baseParticle.hpp
//  diffusionLimitedAggregation_3D
//
//  Created by Edmund Oetgen on 18/03/2017.
//
//


#pragma once
#include "ofMain.h"
class baseParticle {
    
public:
    virtual void walk() = 0;
    virtual void display()=0;
    
    virtual void checkEdges()= 0;
    
    
    ofPoint initPos;
    ofPoint position;
    ofPoint velocity;
    ofPoint acceleration;
    
    int winWidth = ofGetWidth();
    int winHeight = ofGetHeight();
    int boundU, boundD, boundL, boundR;
    
    
    float radius;
    float mass;
    float forceStrength;
    ofFloatColor c;
};