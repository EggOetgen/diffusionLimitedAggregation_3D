#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(60);
    ofBackgroundGradient( ofColor( 25 ), ofColor( 0 ) );
    //ofSetBackgroundColor(0);
    ofEnableDepthTest();
    
     go = true;
    grow =drawPoints = drawBound = rotate =false;
    
    float seedRad = 5.f;
    
    
    // pointTree = new particleTree(ofPoint(0,0,0), 5.0);
    
    // maxDist = seedRad * 4.0;
    
    pointSize = 40;
    maxDist = seedRad*7.;
    rad = seedRad;
    int dim = 10;
    float size = 3;
    float spacing = TWO_PI /dim;
    for(int i = 0; i < pointSize; i++){
        std::shared_ptr<stickyParticle> p(new stickyParticleVer1(ofPoint(0,0,0), maxDist, rad));
        points.push_back(p);
    }
    // }
    cam.setNearClip(1);
    cam.setFarClip(-100);
    cam.setPosition(0,0,10);
    cam.setTarget(ofVec3f(0,0,0));
    light.setPosition(-100,-300,300);
    light.enable();
    
    ofSetSphereResolution(20);
    s=0;
    // ofSetBackgroundAuto(false);
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
     if(go){
  //  for(int p = 0; p < 20; p++){
        
        
        //  if(int(a)%20 ==0 && points.size()<pointSize/2){
        if(points.size()<pointSize/2 || grow){
            
            //                if(int(a)%200 ==0){
            //                    maxDist +=rad*2;
            //                }
            //   rad*=1.03;
             float newDist =pointTree->calculateBound();
            if(newDist>maxDist) maxDist = newDist;
            for(int i = 1; i < pointSize/2; i++){
                int picker = ofRandom(pointSize/10);
                
                if(i<picker){
                std::shared_ptr<stickyParticle> part(new stickyParticleVer2(ofPoint(0,0,0), maxDist, rad));
                    std::shared_ptr<stickyParticle> part2(new stickyParticleVer3(ofPoint(0,0,0), maxDist, rad));
                    points.push_back(part2);

                points.push_back(part);
                } else if(i>picker){
                     std::shared_ptr<stickyParticle> part(new stickyParticleVer1(ofPoint(0,0,0), maxDist, rad));
                        points.push_back(part);
                }
               
                
            
                
            }
            
        }
        else if(add){
            for(int i = 1; i < pointSize; i++){
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
    
    
        
    
        
        vector<std::shared_ptr<stickyParticle>>::iterator it = points.end()-1;
        for (;it != points.begin(); --it ) {
            
            if((*it)->state ==0) (*it)->walk();
        else
            if((*it)->state ==1){
                pointTree->addParticle(*it);
                points.erase(it);
               // it->reset();
                
            }
            if ((*it)->constrain(ofPoint(0,0,0), maxDist+rad*4)) {
                points.erase(it);
                
            }
         

            if ((pointTree->checkCollisionTree((*it)))){(*it)->stick();}

            

        
            
        }
    }
    
        //   pointTree->update();
        // pointTree->add();
        
        cout << ofGetFrameRate() <<" " <<pointTree->tree.size() << " " <<points.size() << " " << maxDist<<endl;
   // }
    //  }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofEnableDepthTest();
    ofBackgroundGradient( ofColor( 255 ), ofColor( 100 ) );
    //ofBackgroundGradient( ofColor( 50 ), ofColor( 0 ) );
    
    // if (go) {
    
    
    stringstream s;
    s << "Speed: " << ofGetFrameRate();
    ofSetColor(0);
    ofDrawBitmapString(s.str(), -w/2,-h/2+20
                       );
    
    //ofTranslate(w/2,h/2);
    ofRotateX(20);
    
    cam.begin();
    light.enable();
    //light.setPosition(points[0].position);
    
    if(rotate){
        ofRotateY(a);
        ofRotateZ(a);
    }
    
    //    for(int i = 1; i <tree.size(); i++){
    //        tree[i].display();
    //
    //    }
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
    // ofDisableLighting();
    cam.end();
    //    if(ofGetFrameNum() ==2)
    //        exit();
    
    //}
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
    else if(key == 'c'){
        if(points.size() !=0)
        points.clear();
        go = !go;
    }
    else if(key == '5'){
        pointTree->m =!pointTree->m;
        //
    } else if(key == '6')
        go = !go;
    // pointTree->clear();
    
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
    
    pointTree->add();
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
