//
//  stickyParticle.cpp
//  diffusionLimitedAggregation_3D
//
//  Created by Edmund Oetgen on 18/03/2017.
//
//

#include "stickyParticle.hpp"


stickyParticle::stickyParticle(ofPoint origin,float maxDist, float radius_ ):randParticle(ofPoint(0,0,0), ofPoint(0,0,0), ofPoint(0,0,0), radius_){
    
    calculateInitPos();
    state = 0;
    bound = maxDist;
    
}

void stickyParticle::display()
{
    if(state ==0) { ofSetColor(0,120,0); ofDrawBox(position.x, position.y, position.z, radius);}
    else
        if(state ==1) { ofSetColor(110); ofDrawBox(position.x, position.y, position.z, radius);}
    
  
}

void stickyParticle::checkCollision(const std::shared_ptr<stickyParticle> n){
    
    if (n->state ==1) {
        
        
        float distSqr = ((position.x - n->position.x)*(position.x - n->position.x)) + ((position.y - n->position.y)*(position.y - n->position.y))+ ((position.z - n->position.z)*(position.z - n->position.z));
        
        float dimSqr = (radius + n->radius)*(radius + n->radius)*0.5;
        
        if (distSqr <= dimSqr) {
            state = 1;
        }
    }
}

bool stickyParticle::checkCollisionBool(const std::shared_ptr<stickyParticle> n) const{
            float distSqr = ((position.x - n->position.x)*(position.x - n->position.x)) + ((position.y - n->position.y)*(position.y - n->position.y))+ ((position.z - n->position.z)*(position.z - n->position.z));
        
        float dimSqr = ((radius + n->radius)*(radius + n->radius));
        
        if (distSqr <= dimSqr) {
            return true;
            
  
    return false;
}
}


void stickyParticle::stick(){
    
    state=1;
    
}

void stickyParticle::calculateInitPos(){
    
    float dist = bound * pow(ofRandomf(), 1/3);
    
    
    float x = ofRandom(-1,1);
    float y = ofRandom(-1,1);
    float z = ofRandom(-1,1);
    
    float molnar = 1 /
    sqrt( (x*x) + (y*y) + (z*z));
    
    x = dist * molnar * x;
    y = dist * molnar * y;
    z = dist * molnar * z;
    ofPoint p(x,y,z);
    position = p;
    
}