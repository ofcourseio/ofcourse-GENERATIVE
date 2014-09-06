#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundAuto(false);
    ofSetCurveResolution(500);
    ofBackground(255);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    change = 0.00001 * ofGetMouseX();
    
    /*
    x0 = ofRandom(ofGetWidth());
    x1 = ofRandom(ofGetWidth());
    x2 = ofRandom(ofGetWidth());
    x3 = ofRandom(ofGetWidth());
    y0 = ofRandom(ofGetHeight());
    y1 = ofRandom(ofGetHeight());
    y2 = ofRandom(ofGetHeight());
    y3 = ofRandom(ofGetHeight());
    */
    
    x0 = ofGetWidth() * ofNoise(nx0, 10);
    x1 = ofGetWidth() * ofNoise(nx1, 20);
    x2 = ofGetWidth() * ofNoise(nx2, 30);
    x3 = ofGetWidth() * ofNoise(nx3, 40);
    y0 = ofGetWidth() * ofNoise(ny0, 50);
    y1 = ofGetWidth() * ofNoise(ny1, 60);
    y2 = ofGetWidth() * ofNoise(ny2, 70);
    y3 = ofGetWidth() * ofNoise(ny3, 80);
    
    nx0 += change;
    nx1 += change;
    nx2 += change;
    nx3 += change;
    ny0 += change;
    ny1 += change;
    ny2 += change;
    ny3 += change;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0, 50);
    ofNoFill();
    ofBezier(x0, y0, x1, y1, x2, y2, x3, y3);
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
