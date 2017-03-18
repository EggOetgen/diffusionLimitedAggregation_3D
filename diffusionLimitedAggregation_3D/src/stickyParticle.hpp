//
//  stickyParticle.hpp
//  diffusionLimitedAggregation_3D
//
//  Created by Edmund Oetgen on 18/03/2017.
//
//


#pragma once
#include "randParticle.hpp"

class stickyParticle : public randParticle {
    
public:
    stickyParticle(ofPoint origin, float maxDist, float radius_ );
    void display();
    void calculateInitPos();
    void checkCollision(const stickyParticle& n);
    bool checkCollisionBool(const stickyParticle& n) const;
    void stick();
    
    void stickyWalk();
    
    
    int state;
    float bound;
    
    
};