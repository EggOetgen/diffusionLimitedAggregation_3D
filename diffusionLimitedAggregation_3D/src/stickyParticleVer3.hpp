//
//  stickyParticleVer3.hpp
//  diffusionLimitedAggregation_3D
//
//  Created by Edmund Oetgen on 20/03/2017.
//
//

/*
 ONE OF THREE CHILDREN OF STICKY PARTICLE.
 MIXTURE OF THE OTHER TWO, ALSO CUBES
 */

#pragma once
#include "stickyParticle.hpp"


class stickyParticleVer3 : public stickyParticle {
    
public:
    stickyParticleVer3(ofPoint origin, float maxDist, float radius_ );
    void display();
    
    
        
    float birth;
    float c,a;
    
};