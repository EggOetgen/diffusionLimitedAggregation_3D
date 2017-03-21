//
//  randParticle.cpp
//  diffusionLimitedAggregation_3D
//
//  Created by Edmund Oetgen on 18/03/2017.
//
//

#include "randParticle.hpp"


randParticle::randParticle(ofPoint initPos_, ofPoint initVel, ofPoint initAcc, float radius_ ):Particle(initPos_, initVel, initAcc, radius_){
    
}

void randParticle::walk() {
    
    
    velocity.set(ofRandom(-1,1)*radius, ofRandom(-1,1)*radius, ofRandom(-1, 1)*radius);
    velocity += acceleration;
 
    position += velocity;
    
    acceleration.set(0,0,0);;
    
    
}