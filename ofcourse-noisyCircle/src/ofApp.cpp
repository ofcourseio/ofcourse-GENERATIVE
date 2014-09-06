#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundAuto(false);
    ofSetCircleResolution(100);
    ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    x = ofGetWidth() * ofNoise(x0, 30);
    y = ofGetHeight() * ofNoise(y0, 40);
    sizex = 250 * ofNoise(sizex0, 10);
    sizey = 250 * ofNoise(sizey0, 15);
    r = 255 * ofNoise(r0, 20);
    g = 255 * ofNoise(g0, 50);
    b = 255 * ofNoise(b0, 60);
    
    x0 += 0.01;
    y0 += 0.01;
    sizex0 += 0.01;
    sizey0 += 0.01;
    r0 += 0.01;
    g0 += 0.01;
    b0 += 0.01;
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(r, g, b);
    ofEllipse(x, y, sizex, sizey);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
