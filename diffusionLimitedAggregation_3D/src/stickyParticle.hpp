//
//  stickyParticle.hpp
//  diffusionLimitedAggregation_3D
//
//  Created by Edmund Oetgen on 18/03/2017.
//
//

/*
 ABSTRACT BASE CLASS FOR 'STICKY PARTICLES'
 ADDED FUNCTIONALITY TO DETECT IF COLLIDED WITH ANOTHER PARTICLE, AND STATES TO STORE INFORMATION ABOUT PARTICLE
 
 USES BOX MULLER ALGORITHM TO PLACE POINTS RANDOMLY ON SURFACE OF A SPHERE
 https://en.wikipedia.org/wiki/Box–Muller_transform

 */

#pragma once
#include "randParticle.hpp"

class stickyParticle : public randParticle {
    
public:
    stickyParticle(ofPoint origin, float maxDist, float radius_ );
    //stickyParticle(stickyParticle const& = stickyParticle);
    void calculateInitPos();
    void checkCollision(const std::shared_ptr<stickyParticle> n);
    bool checkCollisionBool(const std::shared_ptr<stickyParticle> n) const;
    void stick();
    
    virtual void display() = 0;

    int state;
    float bound;
    
    
};