//
//  stickyParticleVer2.hpp
//  diffusionLimitedAggregation_3D
//
//  Created by Edmund Oetgen on 20/03/2017.
//
//

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