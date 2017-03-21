//
//  stickyParticleVer2.hpp
//  diffusionLimitedAggregation_3D
//
//  Created by Edmund Oetgen on 20/03/2017.
//
//


/*
 ONE OF THREE CHILDREN OF STICKY PARTICLE.
 COLOR WILL GRADUALY PULSATE ACCORDING TO SINE WAVE AND WHEN IT WAS INITIALISED
 */
#pragma once
#include "stickyParticle.hpp"


class stickyParticleVer2 : public stickyParticle {
    
public:
    stickyParticleVer2(ofPoint origin, float maxDist, float radius_ );
    void display();
   
    
    void stick();
    
    
    float birth;
    float c,a;
    
};