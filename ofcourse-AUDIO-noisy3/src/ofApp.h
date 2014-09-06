#pragma once

//include the header files of your addons here.
#include "ofMain.h"
#include "ofxAudioUnit.h"
#include "ofxBpm.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();
    
    void play(); //a custom event that we added for ofxBpm

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofxAudioUnitSampler sampler;  //our "keyboard"
    ofxAudioUnitFilePlayer player; //our "mp3 player"
    ofxAudioUnitMixer mixer; // our ... "mixer"
    ofxAudioUnitOutput output; //our speaker
    
    ofxBpm bpm; //for timing
    int beat; // a variable to keep track of the current beat
    
    
    float time;
    float time2;
    
    float x0, y0, x1, y1, x2, y2, x3, y3;
    float nx0, ny0, nx1, ny1, nx2, ny2, nx3, ny3;
    
    float change;
    
    bool toClear;
		
};
