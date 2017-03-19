//
//  particleTree.hpp
//  diffusionLimitedAggregation_3D
//
//  Created by Edmund Oetgen on 18/03/2017.
//
//

#pragma once
#include "ofMain.h"
#include "stickyParticle.hpp"
#include "stickyParticleVer1.hpp"

class particleTree {
    
public:
    particleTree(ofPoint origin_, float radius_ );
    void display();
    void update();
    bool checkCollisionTree( std::unique_ptr<stickyParticle> p);
    void addParticle(std::unique_ptr<stickyParticle> p);
    float calculateBound();
    void clear();
    void add();
    
    ofPoint origin;
    float radius;
    int prevTreeSize;
    float prevMaxDist;
    float boundRad;
    int treeSize;
    
    vector<std::unique_ptr<stickyParticle> > tree;
    ofVboMesh mesh;
    bool m;
    
};

