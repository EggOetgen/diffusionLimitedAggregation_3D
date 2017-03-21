/*
 This program implements a diffusion limited aggregation algorithm to generate 'organic' shapes. Random walkers wander around the screen until they hit a 'stuck' particle, at which point they too become stuck
 
 Since the WIP i have added an abstract base class, three derived classes of sticky particle and replaced as many pointers as possible with smart pointers, as well as general performance improvements
 
 

  --- //CONTROlS//---

 --- Mouse --- will control ofEasyCam
 ---   1   --- will show random walkers 
 ---   2   --- will show the bounding sphere, where new walkers will appear
 ---   3   --- toggle rotation
 ---   4   --- will add a few particles
 ---   5   --- will pause the walkers
 --- space --- toggle contiusuly adding more particles, be CAREFUL NOT TO CRASH
 ---   c   --- Will clear all random walkers, use this if starts getting slow
 
 
 More information about DLA algorithm:-
 http://paulbourke.net/fractals/dla/
 
 8-]
 */


#pragma once

#include "ofMain.h"
//#include "Particle.hpp"
//#include "randParticle.hpp"
//#include "stickyParticle.hpp"
#include "stickyParticleVer1.hpp"
#include "stickyParticleVer2.hpp"
#include "stickyParticleVer3.hpp"
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
    
//   SMART POINTER ;)
    vector<std::shared_ptr<stickyParticle> > points;
    
    
    particleTree *pointTree= new particleTree(ofPoint(0,0,0), 20.0);
    
    float w = (float)ofGetWidth();
    float h = (float)ofGetHeight();
    float maxDist;
    
    ofLight light;
  
    ofEasyCam cam;
    float a =0;
    float dist, rad;
    int pointSize;
 
    bool grow, drawPoints, drawBound, rotate, add, go;
};
