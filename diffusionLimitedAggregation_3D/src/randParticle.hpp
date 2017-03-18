//
//  randParticle.hpp
//  diffusionLimitedAggregation_3D
//
//  Created by Edmund Oetgen on 18/03/2017.
//
//

#pragma once
#include "Particle.hpp"

class randParticle : public Particle {
    
public:
    randParticle(ofPoint initPos_, ofPoint initVel, ofPoint initAcc, float radius_ );
    void walk();
};