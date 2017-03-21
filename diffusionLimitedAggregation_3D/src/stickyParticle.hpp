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
    //stickyParticle(stickyParticle const& = stickyParticle);
  virtual void display();
    void calculateInitPos();
   void checkCollision(const std::shared_ptr<stickyParticle> n);
    bool checkCollisionBool(const std::shared_ptr<stickyParticle> n) const;
void stick();
    
void walk();
    
    
    int state;
    float bound;
    
    
};