//
//  stickyParticleVer3.cpp
//  diffusionLimitedAggregation_3D
//
//  Created by Edmund Oetgen on 20/03/2017.
//
//

#include "stickyParticleVer3.hpp"

stickyParticleVer3::stickyParticleVer3(ofPoint origin,float maxDist, float radius_ ):stickyParticle(origin, maxDist, radius_){
    
    calculateInitPos();
    state = 0;
    bound = maxDist;
    birth = ofGetFrameNum();
    float scale = ofRandom(2,4);
    radius *=scale;
    
}

void stickyParticleVer3::display()
{
    c = abs(sin((ofGetFrameNum()-birth)/100));
    a = abs(sin((ofGetFrameNum()-birth)/1000));
    // radius *=w;
    if(state ==0) { ofSetColor(0); ofDrawBox(position.x, position.y, position.z, radius);}
    //  else
    if(state ==1) {
        ofSetColor(ofFloatColor(c,a)); ofDrawBox(position.x, position.y, position.z, radius*c*a);}
    
}



