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
    
    
}

void stickyParticleVer1::display()
{
    if(state ==0) { ofSetColor(0,0,255); ofDrawSphere(position.x, position.y, position.z, radius);}
    else
        if(state ==1) { ofSetColor(255,0,0); ofDrawSphere(position.x, position.y, position.z, radius);}
    
    
    //    if(state ==0) { ofSetColor(120); ofDrawBox(position.x, position.y, position.z, radius);}
    //    else
    //        if(state ==1) { ofSetColor(255); ofDrawBox(position.x, position.y, position.z, radius);}
}

void stickyParticleVer1::checkCollision(const std::unique_ptr<stickyParticle> n){
    
    if (n->state ==1) {
        
        
        float distSqr = ((position.x - n->position.x)*(position.x - n->position.x)) + ((position.y - n->position.y)*(position.y - n->position.y))+ ((position.z - n->position.z)*(position.z - n->position.z));
        
        float dimSqr = (radius + n->radius)*(radius + n->radius)*0.5;
        
        if (distSqr <= dimSqr) {
            state = 1;
        }
    }
}

bool stickyParticleVer1::checkCollisionBool(const std::unique_ptr<stickyParticle> n) {
    
    if (n->state == 1) {
        
        float distSqr = ((position.x - n->position.x)*(position.x - n->position.x)) + ((position.y - n->position.y)*(position.y - n->position.y))+ ((position.z - n->position.z)*(position.z - n->position.z));
        
        float dimSqr = ((radius + n->radius)*(radius + n->radius));
        
        if (distSqr <= dimSqr) {
            return true;
        }
    }
    return false;
}


void stickyParticleVer1::stickyWalk(){
    
    if (state ==0) {
        walk();
    }
    
}

void stickyParticleVer1::stick(){
    
    state=1;
   // birth = ofGetElapsedTimef();
    
}

void stickyParticleVer1::calculateInitPos(){
    
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