//
//  stickyParticleVer1.cpp
//  diffusionLimitedAggregation_3D
//
//  Created by Edmund Oetgen on 19/03/2017.
//
//

#include "stickyParticleVer1.hpp"

stickyParticleVer1::stickyParticleVer1(ofPoint origin,float maxDist, float radius_ ):stickyParticle(origin, maxDist, radius_){
    
    calculateInitPos();
    state = 0;
    bound = maxDist;
    birth = ofGetFrameNum();
    
}

void stickyParticleVer1::display()
{
    w = sin((ofGetFrameNum()-birth)/50)/2+1;
   // radius *=w;
    if(state ==0) { ofSetColor(255); ofDrawBox(position.x, position.y, position.z, radius);}
  //  else
        if(state ==1) {
            ofSetColor(140,200); ofDrawSphere(position.x, position.y, position.z, radius*w);}
    
   }





