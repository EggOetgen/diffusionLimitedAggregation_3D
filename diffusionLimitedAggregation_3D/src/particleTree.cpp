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
    
    stickyParticle seed(origin, 1, radius);
    seed.state = 1;
    prevTreeSize = boundRad = prevMaxDist = 0;
    
    m = true;
    treeSize = 0;
    tree.push_back(seed);
    mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
    
}
void particleTree::update(){
    
    for(int i =0; i < mesh.getNumVertices();i++){
        ofPoint p = mesh.getVertex(i);
        float offsetX = ofMap((ofNoise(ofGetFrameNum()*124, ofGetFrameNum()*124, ofGetFrameNum()*124)), 0, 1, -1,1);
        float offsetY= ofMap((ofNoise(ofGetFrameNum(), ofGetFrameNum(), ofGetFrameNum())), 0, 1, -1,1);
        float offsetZ = ofMap((ofNoise(ofGetFrameNum()*642, ofGetFrameNum()*642, ofGetFrameNum()*642)), 0, 1, -1,1);
        p.x+=offsetX;
        p.y+=offsetY;
        p.z+=offsetZ;
        mesh.setVertex(i, p);
        
    }
    
}
void particleTree::display(){
    // if(m){
    vector<stickyParticle>::iterator it = tree.begin();
    for (;it != tree.end(); ++it ) {
        (*it).display();
        
        //   }
    }
    ofSetColor(100,0,60,80);
    //mesh.draw();
}

bool particleTree::checkCollisionTree(const stickyParticle& p){
    
    vector<stickyParticle>::iterator it = tree.begin();
    for (;it != tree.end(); ++it ) {
        if(p.checkCollisionBool(*it))
            return true;
    }
    return false;
    
}

void particleTree::addParticle(const stickyParticle& p){
    
    tree.push_back(p);
    treeSize = tree.size();
    
}

float particleTree::calculateBound(){
    
    float maxDist = 0;
    vector<stickyParticle>::iterator it = tree.begin();
    for (;it != tree.end(); ++it ) {
        float distSqr = (*it).position.squareDistance(origin);
        if (distSqr > maxDist) {
            maxDist = distSqr;
        }
    }
    if (maxDist > prevMaxDist) {
        prevMaxDist = maxDist;
        boundRad = sqrt(maxDist);
    }
    // cout << maxDist << " " << prevMaxDist << " " << boundRad <<endl;
    return boundRad;
}


void particleTree::clear(){
    
    tree.clear();
    
}

void particleTree::add(){
    //  vector<stickyParticle>::iterator it = tree.begin();
    for (int i =treeSize;i<tree.size(); i++ ) {
        mesh.addVertex(tree[i].position);
        mesh.addIndex(i);
        //  mesh.addIndex(i-1);
        
    }
    treeSize = tree.size();
}