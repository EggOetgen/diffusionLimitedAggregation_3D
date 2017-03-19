/*
 This program implements a diffusion limited aggregation algorithm to generate cool shapes, use buttons 1-4 to change stuff. If it starts to lag try pressing space. Enjoy
 
 8-]
 */


#pragma once

#include "ofMain.h"
#include "Particle.hpp"
#include "randParticle.hpp"
#include "stickyParticle.hpp"
#include "stickyParticleVer1.hpp"
#include "particleTree.hpp"
class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    //    Particle *p = new Particle(ofPoint(0,0,0), ofPoint(1,2,0), ofPoint(0,0,0), 1);
    
    vector<std::unique_ptr<stickyParticle> > points;
    
    //std::unique_ptr<particleTree> pointTree(new particleTree(ofPoint(0,0,0), 5.0));
    particleTree *pointTree= new particleTree(ofPoint(0,0,0), 5.0);
    
    float w = (float)ofGetWidth();
    float h = (float)ofGetHeight();
    float maxDist;
    
    ofLight light;
    //  ofCamera cam;
    ofEasyCam cam;
    float a =0;
    float dist, rad;
    int pointSize;
    int s;
    bool grow, drawPoints, drawBound, rotate, add, go;
};
