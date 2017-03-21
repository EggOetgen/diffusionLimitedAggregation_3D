//
//  stickyParticleVer1.hpp
//  diffusionLimitedAggregation_3D
//
//  Created by Edmund Oetgen on 19/03/2017.
//
//
#pragma once
#include "stickyParticle.hpp"


class stickyParticleVer1 : public stickyParticle {
    
public:
    stickyParticleVer1(ofPoint origin, float maxDist, float radius_ );
    void display();
   // void calculateInitPos();
   
           
    
   // int state;
       float birth;
    float w;
    
};