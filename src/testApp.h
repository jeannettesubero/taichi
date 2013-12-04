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
    
    vector<ofImage> imageList;
    int imageCounter = 0;
    
    deque<ofVec2f> leftHandPrevPositions;
    deque<ofVec2f> rightHandPrevPositions;
    
    deque<ofVec2f> pointsOnLine;

    bool clear = true;
    
};

#endif
