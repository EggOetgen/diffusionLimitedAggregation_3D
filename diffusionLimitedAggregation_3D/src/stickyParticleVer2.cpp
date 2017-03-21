//
//  stickyParticleVer2.cpp
//  diffusionLimitedAggregation_3D
//
//  Created by Edmund Oetgen on 20/03/2017.
//
//

#include "stickyParticleVer2.hpp"

stickyParticleVer2::stickyParticleVer2(ofPoint origin,float maxDist, float radius_ ):stickyParticle(origin, maxDist, radius_){
    
    calculateInitPos();
    state = 0;
    bound = maxDist;
    birth = ofGetFrameNum();
    float scale = ofRandom(2,4);
    radius *=scale;
    
}

void stickyParticleVer2::display()
{
    c = abs(sin((ofGetFrameNum()-birth)/100));
    a = abs(sin((ofGetFrameNum()-birth)/1000));
    
    if(state ==0) { ofSetColor(0); ofDrawBox(position.x, position.y, position.z, radius);}
    
    if(state ==1) {
        ofSetColor(ofFloatColor(c,a)); ofDrawSphere(position.x, position.y, position.z, radius);}
    
}

