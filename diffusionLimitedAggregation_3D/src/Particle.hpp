//
//  Particle.hpp
//  diffusionLimitedAggregation_3D
//
//  Created by Edmund Oetgen on 18/03/2017.
//
//

#pragma once
#include "baseParticle.hpp"

class Particle :baseParticle{
    
public:
    Particle(ofPoint initPos_, ofPoint initVel, ofPoint initAcc, float radius_);
    void walk();
 virtual   void display();
    
    void checkEdges();
    bool constrain(ofPoint origin, float maxDist);
    void applyForce(ofPoint force);
    
    ofPoint generateForceTowardsPoint(ofPoint target, float power);
    ofPoint generateForceTowardsParticle(Particle target);
    
    void attractPoint(ofPoint target, float power);
    void attractParticle(Particle target);
    void repelPoint(ofPoint target, float power);
    void repelParticle(Particle target);
    
    
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