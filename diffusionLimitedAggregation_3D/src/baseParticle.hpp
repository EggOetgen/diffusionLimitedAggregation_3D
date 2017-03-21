//
//  baseParticle.hpp
//  diffusionLimitedAggregation_3D
//
//  Created by Edmund Oetgen on 18/03/2017.
//
//

/*
 ABSTRACT BASE CLASS FOR PARTICLE, DOESN'T DO MUCH
 */

#pragma once
#include "ofMain.h"
class baseParticle {
    
public:
    baseParticle(ofPoint initPos_, ofPoint initVel, ofPoint initAcc, float radius_);
    virtual void walk() = 0;
    virtual void display();
    
 
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

};
