//
//  stickyParticleVer1.hpp
//  diffusionLimitedAggregation_3D
//
//  Created by Edmund Oetgen on 19/03/2017.
//
//


/*
 ONE OF THREE CHILDREN OF STICKY PARTICLE. 
 RADIUS WILL GRADUALY PULSATE ACCORDING TO SINE WAVE AND WHEN IT WAS INITIALISED 
 */
#pragma once
#include "stickyParticle.hpp"


class stickyParticleVer1 : public stickyParticle {
    
public:
    stickyParticleVer1(ofPoint origin, float maxDist, float radius_ );
    void display();
    
    float birth;
    float w;
    
};