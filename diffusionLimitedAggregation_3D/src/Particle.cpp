//
//  Particle.cpp
//  diffusionLimitedAggregation_3D
//
//  Created by Edmund Oetgen on 18/03/2017.
//
//

#include "Particle.hpp"



Particle::Particle(ofPoint initPos_, ofPoint initVel, ofPoint initAcc, float radius_ ):baseParticle(initPos_, initVel, initAcc, radius_)
{
    
//    position     = initPos_;
//    velocity     = initVel;
//    acceleration = initAcc;
//    
    radius = radius_;
    mass = radius;
    
    boundU = -(winHeight/2);
    boundD =  winHeight/2;
    boundL = -(winWidth/2);
    boundR = winWidth/2;
    
    forceStrength = 100;
    c.set(0.8,0.8,0.8);
}


void Particle::walk()
{
    
    velocity += acceleration;
    checkEdges();
    position += velocity;
    acceleration.set(0,0);
}

void Particle::display()
{
    ofSetColor(255,0,0);
    ofDrawSphere(position, radius);
}

void Particle::checkEdges() {
    if (position.x > boundR) {
        position.x = boundR;
        velocity.x *= -1;
    } else if (position.x < boundL) {
        position.x = boundL;
        velocity.x *= -1;
    }
    
    else if (position.y < boundU) {
        position.y = boundU;
        velocity.y *= -1;
    } else if (position.y > boundD) {
        position.y = boundD;
        velocity.y *= -1;
    }
}

void Particle::applyForce(ofPoint force)
{
    ofPoint f = force/mass;
    acceleration += f;
}

ofPoint Particle::generateForceTowardsPoint(ofPoint target, float power)
{
    float targetMass = power;
    ofPoint f = target-position;
    float distSqr = (f.x*f.x)+(f.y*f.y)+(f.z*f.z);
    
    f.normalize();
    
    float strength = (forceStrength * mass * targetMass)/(distSqr);
    f *= strength;
    return f;
    
}

ofPoint Particle::generateForceTowardsParticle(Particle target)
{
    //    ofPoint f = target.position-position;
    //    ofPoint fSqr = f * f;
    //    //float distSqr = position.squareDistance(target.position);
    //    float distSqr = (position.x-target.position.x)*(position.x-target.position.x) + (position.y-target.position.y)*(position.y-target.position.y);
    //    ofPoint force = fSqr/distSqr;
    //
    //    float strength = (forceStrength * mass *target.mass)/distSqr;
    //    force *= 4;
    //
    //    return force;
    
    ofPoint f = target.position-position;
    float distSqr = (f.x*f.x)+(f.y*f.y)+(f.z*f.z);
    
    f.normalize();
    
    float strength = (forceStrength * mass *target.mass)/(distSqr);
    f *= strength;
    return f;
}

void Particle::attractPoint(ofPoint target, float power)
{
    applyForce(generateForceTowardsPoint(target, power));
}

void Particle::attractParticle(Particle target)
{
    applyForce(generateForceTowardsParticle(target));
}

void Particle::repelPoint(ofPoint target, float power)
{
    applyForce(-generateForceTowardsPoint(target, power));
}

void Particle::repelParticle(Particle target)
{
    applyForce(-generateForceTowardsParticle(target));
}

bool Particle::constrain(ofPoint origin , float maxDist ){
    
    float distSqr = ((position.x-origin.x)*(position.x-origin.x)) + ((position.y-origin.y)*(position.y-origin.y)) + ((position.z-origin.z)*(position.z-origin.z));
    float dist = position.squareDistance(origin);
    float maxDistSqr = maxDist * maxDist;
    
    
    if(distSqr > maxDistSqr){
        //        ofPoint f = position-origin;
        //        f.normalize();
        //        float strenght = 100;
        //       // applyForce(f);
        //        position -= f*10;
        return true;
        
    }
    return false;
}

