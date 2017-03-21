//
//  particleTree.cpp
//  diffusionLimitedAggregation_3D
//
//  Created by Edmund Oetgen on 18/03/2017.
//
//


#include "particleTree.hpp"
particleTree::particleTree(ofPoint origin_, float radius_ ){
    
    radius = radius_;
    origin = origin_;
    
    //SET UP THE FIRST PARTICLE
    std::shared_ptr<stickyParticle> seed (new stickyParticleVer2(origin, 1, radius));
    seed->stick();
    
    
 
    treeSize = 0;
    tree.push_back(seed);
    
}

void particleTree::display(){
  
    vector<std::shared_ptr<stickyParticle>>::iterator it = tree.begin();
    for (;it != tree.end(); ++it ) {
        (*it)->display();
       
    }
 
}

bool particleTree::checkCollisionTree( std::shared_ptr<stickyParticle> p){
    
    vector<std::shared_ptr<stickyParticle>>::iterator it = tree.begin();
    for (;it != tree.end(); ++it ) {
               if(p->checkCollisionBool(*it))
            return true;
        
    }
    return false;
    
}

void particleTree::addParticle(std::shared_ptr<stickyParticle> p){
    
    tree.push_back(p);
    treeSize = tree.size();
    
}


//SETS RADIUS OF BOUDING SPHERE EQUAL TO PARTICLE IN TREE FURTHEST FROM ORIGIN
float particleTree::calculateBound(){
    
    float maxDist = 0;
    vector<std::shared_ptr<stickyParticle>>::iterator it = tree.begin();
    for (;it != tree.end(); ++it ) {
        float distSqr = (*it)->position.squareDistance(origin);
        if (distSqr > maxDist) {
            maxDist = distSqr;
        }
    }
    if (maxDist > prevMaxDist) {
        prevMaxDist = maxDist;
        boundRad = sqrt(maxDist);
    }
       return boundRad;
}


void particleTree::clear(){
    
    tree.clear();
    
}

