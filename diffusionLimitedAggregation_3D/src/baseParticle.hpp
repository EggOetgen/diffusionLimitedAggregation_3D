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
    baseParticle(ofPoint initPos_, ofPoint initVel, ofPoint initAcc, float radius_);
    virtual void walk() = 0;
    virtual void display();
    
    virtual void checkEdges()= 0;
//    virtual void checkCollision()= 0;
//    virtual void checkCollisionBool()= 0;

    
    
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
