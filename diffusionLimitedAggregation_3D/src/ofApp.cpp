#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(60);
    ofBackgroundGradient( ofColor( 255 ), ofColor( 100 ) );
      ofEnableDepthTest();
    
    //USED FOR TOGGLING VIEWS AND STUFF
    go = true;
    grow = drawPoints = drawBound = rotate =false;
    
    float seedRad = 5.f;
    
    
    //HOW MANY RANDOM WALKERS
    pointSize = 40;
    
    //BOUNDING SPHERE RADIUS
    maxDist = seedRad*7.;
    
    rad = seedRad;
    int dim = 10;
   
     for(int i = 0; i < pointSize; i++){
        std::shared_ptr<stickyParticle> p(new stickyParticleVer1(ofPoint(0,0,0), maxDist, rad));
        points.push_back(p);
    }
 
 
    light.setPosition(-100,-300,300);
    light.enable();
    
    //CAN LOWER THIS IF RUNNING SLOW, BUT THE HIGHER THE BETTER
    ofSetSphereResolution(20);
    //s=0;
    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
     if(go){
 
         //STUFF FOR ADDING NEW POINTS WHEN RUNNING LOW OR EXPLICITLY TOLD TO
        if(points.size()<pointSize/2 || grow){
            
            //   rad*=1.03; //IF YOU WANT THEM GRADUALY BIGGER
            //   rad*=0.999; //IF YOU WANT THEM GRADUALY SMALLER
            
            //CALCULATE BOUNDING SPHERE
            float newDist =pointTree->calculateBound();
            if(newDist>maxDist) maxDist = newDist;
            
            for(int i = 1; i < pointSize/2; i++){
                
                //DECIDE HOW MANY OF EACH PARTICLE
                int picker = ofRandom(pointSize/10);
                if(i<picker){
                    
                    std::shared_ptr<stickyParticle> part(new stickyParticleVer2(ofPoint(0,0,0), maxDist, rad));
                    std::shared_ptr<stickyParticle> part2(new stickyParticleVer3(ofPoint(0,0,0), maxDist, rad));
                    
                    points.push_back(part);
                    points.push_back(part2);
                    }
                
                else if(i>picker){
                    std::shared_ptr<stickyParticle> part(new stickyParticleVer1(ofPoint(0,0,0), maxDist, rad));
                    
                    points.push_back(part);
                }
            }
        }
        else if(add){
            for(int i = 1; i < pointSize; i++){
               
                //AS ABOVE
                float picker = ofRandomf();
                if (picker <= 0.001) {
                    std::shared_ptr<stickyParticle> part(new stickyParticleVer1(ofPoint(0,0,0), maxDist, rad));
                    points.push_back(part);
                    
                }else{
                    std::shared_ptr<stickyParticle> part(new stickyParticleVer2(ofPoint(0,0,0), maxDist, rad));
                    points.push_back(part);
                }
                add = !add;
            }
        }
    
         //STUFF FOR CONTOLING WALKERS (CHECKING COLLISIONS, MOVING ETC)
        vector<std::shared_ptr<stickyParticle>>::iterator it = points.end()-1;
        for (;it != points.begin(); --it ) {
            
            if((*it)->state ==0) (*it)->walk();
            if((*it)->state ==1){
                pointTree->addParticle(*it);
                points.erase(it);
            }
            if ((*it)->constrain(ofPoint(0,0,0), maxDist+rad*4))    points.erase(it);
            if ((pointTree->checkCollisionTree((*it))))             (*it)->stick();


        }
    }
    
    
       // cout << ofGetFrameRate() <<" " <<pointTree->tree.size() << " " <<points.size()<<endl'
 
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //GENERAL OFX STUFF
    ofEnableDepthTest();
    ofBackgroundGradient( ofColor( 255 ), ofColor( 180 ) );
    cam.begin();
    light.enable();
    
    
    if(rotate){
        ofRotateY(a);
        ofRotateZ(a);
    }
    
   
    pointTree->display();
    
    if(drawPoints){
        for(int i = 1; i <points.size(); i++){
            points[i]->display();
        }
    }
    if(drawBound){
        ofSetColor(ofFloatColor(1,1,1,0.4));
        ofDrawSphere(0, 0, maxDist);
    }
    
    a+=0.5;
    light.disable();
    cam.end();
  
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(key == '1')
        drawPoints = !drawPoints;
    else if(key == '2')
        drawBound = !drawBound;
    else if(key == ' ')
        grow = !grow;
    else if(key == '3')
        rotate = !rotate;
    else if(key == '4')
        add = !add;
    else if(key == 'c'||key =='C'){
       // if(points.size() !=0)
        points.clear();
        go = !go;
    }
    else if(key == '5')
        go = !go;
        
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
  
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
    
}
