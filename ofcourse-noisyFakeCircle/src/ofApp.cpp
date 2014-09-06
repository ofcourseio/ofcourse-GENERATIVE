#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    ofSetBackgroundAuto(false);
}

//--------------------------------------------------------------
void ofApp::update(){

    time += 0.01;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofNoFill();
    ofSetColor(0, 50);
    
    float noiseFactor = ofGetMouseX() / 200.0;
    float noiseMargin = ofGetMouseY();
    
    float cx = ofGetWidth() / 2;
    float cy = ofGetHeight() / 2;
    
    float baseRadius = 200;
    
    int n = 100;
    
    ofBeginShape();
    for (int i=0; i<n; i++) {
        
        float angle = ofMap(i, 0, n, 0, TWO_PI);
        
        float noiseRadius = noiseMargin * ofNoise(noiseFactor * angle, time);
        float rad = baseRadius + noiseRadius;
        
        float x = cx + rad * cos(angle);
        float y = cy + rad * sin(angle);
        
        ofVertex(x, y);
    }
    ofEndShape(close);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key==' ') {
        setup();
    }
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
