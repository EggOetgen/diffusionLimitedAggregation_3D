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
    void calculateInitPos();
    void checkCollision(const std::unique_ptr<stickyParticle> n);
    bool checkCollisionBool(const std::unique_ptr<stickyParticle> n) ;
    void stick();
    
    void stickyWalk();
    
    
    int state;
    float bound;
    //float birth;
    
    
};