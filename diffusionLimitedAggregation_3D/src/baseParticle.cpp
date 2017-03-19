//
//  baseParticle.cpp
//  diffusionLimitedAggregation_3D
//
//  Created by Edmund Oetgen on 18/03/2017.
//
//

#include "baseParticle.hpp"

baseParticle::baseParticle(ofPoint initPos_, ofPoint initVel, ofPoint initAcc, float radius_){

    position     = initPos_;
    velocity     = initVel;
    acceleration = initAcc;
    
    radius = radius_;

}