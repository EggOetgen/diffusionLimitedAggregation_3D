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
 virtual   void display();
    void calculateInitPos();
   virtual void checkCollision(const std::unique_ptr<stickyParticle> n);
  virtual  bool checkCollisionBool(const std::unique_ptr<stickyParticle> n) const;
    virtual void stick();
    
    void stickyWalk();
    
    
    int state;
    float bound;
    
    
};