#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundAuto(false);
    ofSetCurveResolution(500);
    ofBackground(255);

    
    //use auval -a in the terminal to find our the three 4 character indentifiers for you audio units.
    sampler = ofxAudioUnitSampler('aumu', 'dls ', 'appl');
    sampler.setProgram(0); //choose the instrument or patch

    //set the filename of the sound file. Don't forget the ofToDataPath if your sound is in the bin/data folder
    player.setFile(ofToDataPath("18618__ross63moose__glasschimes-for-freesound.wav"));
    
    
    
    mixer.setInputBusCount(2); // add two tracks to my mixer
    player.connectTo(mixer, 0); // connect my "mp3 player" to the first input
    sampler.connectTo(mixer, 1); //connect my "keyboard" to the second input
    mixer.connectTo(output); // connent the mixer to my "speaker"
    output.start(); // turn on my speaker
    
    player.play(); //press play on my "mp3 player"
    
    
    bpm.setBpm(120); //set the beat per minute the our play event is triggered
    
    ofAddListener(bpm.beatEvent, this, &ofApp::play); //add our play event to ofApp
    
    beat = 0; //start at beat 1 (computers start counting at zero...)
    bpm.start(); //start timing!
    
    
}

//--------------------------------------------------------------
void ofApp::update(){

    
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
    if (toClear) {
        //ofBackground(255);
        ofSetColor(255, 140);
        ofFill();
        ofRect(0, 0, ofGetWidth(), ofGetHeight());
        
        
        toClear = false;
        change = ofRandom(0.01);
    }
    ofSetColor(0, 50);
    ofNoFill();
    ofBezier(x0, y0, x1, y1, x2, y2, x3, y3);

}

//--------------------------------------------------------------
void ofApp::play(){
    //play a different note on each beat
    if (beat == 0 || beat == 2) sampler.midiNoteOn(60, 127);
    if (beat == 1) sampler.midiNoteOn(62, 127);
    if (beat == 2) sampler.midiNoteOn(65, 127);
    if (beat == 3) sampler.midiNoteOn(67, 127);
    
    //go to next beat
    beat = beat + 1;
    if ( beat > 3 ) beat = 0;
    cout << "beat = " << beat << endl;
    
    toClear = true;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    //press 'p' to play our track 'P' to stop our track
    if (key == 'p') player.play();
    else if (key == 'P') player.stop();
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    //change the volume of track 1 (zero...) when th
    mixer.setInputVolume(ofMap(y, 0, ofGetHeight(), 0.0, 1.0), 0);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    //choose an instrument based on the x position of the mouse[
    //int instrument = ofMap(x, 0, ofGetWidth(), 0, 20);
    int instrument = ofMap(ofNoise(time2, 10), 0, 1, 0, 20);
    sampler.setProgram(instrument);
    
    //play middle c on our "keyboard"
    sampler.midiNoteOn(60, 100);
    
    time2 += 0.1;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    //release the middle c key
    sampler.midiNoteOff(60, 0);
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
