#ifndef _TEST_APP
#define _TEST_APP

#include "ofxOpenNI.h"
#include "ofMain.h"

class testApp : public ofBaseApp{

public:
    
	void setup();
	void update();
	void draw();
    void exit();
    
	void keyPressed  (int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);

    void userEvent(ofxOpenNIUserEvent & event);
    
	ofxOpenNI openNIDevice;
    
    ofTrueTypeFont verdana;
    
    ofVec2f leftHand;
    ofVec2f rightHand;
    ofVec2f centerHand;
    
    float squareDistance;
    

    
    ofImage fire;
    ofImage ice;
    ofImage energyBall;
    
    vector<ofImage> exerciseList;
    ofImage exercise01;
    ofImage exercise02;
    ofImage exercise03;
    ofImage exercise04;
    ofImage exercise05;
    ofImage freestyle;
    
    int exerciseCounter = 0;
    

    
};

#endif
