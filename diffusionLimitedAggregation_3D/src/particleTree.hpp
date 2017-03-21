//
//  particleTree.hpp
//  diffusionLimitedAggregation_3D
//
//  Created by Edmund Oetgen on 18/03/2017.
//
//

/*
 CLASS FOR MANAGING THE 'TREE' OF STUCK PARTICLES(ADDING PARTICLIES, CALCULATING BOUNDING SPHERE ETC
 */

#pragma once
#include "ofMain.h"
#include "stickyParticleVer1.hpp"
#include "stickyParticleVer2.hpp"

class particleTree {
    
public:
    particleTree(ofPoint origin_, float radius_ );
    void display();
    bool checkCollisionTree( std::shared_ptr<stickyParticle> p);
    void addParticle(std::shared_ptr<stickyParticle> p);
    float calculateBound();
    void clear();
   
    ofPoint origin;
    float radius;
    float prevMaxDist;
    float boundRad;
    int treeSize;
    
    vector<std::shared_ptr<stickyParticle> > tree;
 
    
};

