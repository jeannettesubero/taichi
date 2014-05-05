#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup() {
    
    ofBackground(0,0,0);
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    
    ofSetLogLevel(OF_LOG_VERBOSE);

    openNIDevice.setup();
    openNIDevice.addImageGenerator();
    openNIDevice.addDepthGenerator();
    openNIDevice.setRegister(true);
    openNIDevice.setMirror(true);
    openNIDevice.addUserGenerator();
    openNIDevice.setMaxNumUsers(2);
    openNIDevice.start();
    
    // set properties for all user masks and point clouds
    //openNIDevice.setUseMaskPixelsAllUsers(true); // if you just want pixels, use this set to true
    openNIDevice.setUseMaskTextureAllUsers(true); // this turns on mask pixels internally AND creates mask textures efficiently
    openNIDevice.setUsePointCloudsAllUsers(true);
    openNIDevice.setPointCloudDrawSizeAllUsers(2); // size of each 'point' in the point cloud
    openNIDevice.setPointCloudResolutionAllUsers(2); // resolution of the mesh created for the point cloud eg., this will use every second depth pixel
    
    // you can alternatively create a 'base' user class
//    ofxOpenNIUser user;
//    user.setUseMaskTexture(true);
//    user.setUsePointCloud(true);
//    user.setPointCloudDrawSize(2);
//    user.setPointCloudResolution(2);
//    openNIDevice.setBaseUserClass(user);
      
//    verdana.loadFont(ofToDataPath("verdana.ttf"), 24);
    

    

    fire.loadImage("fire.png");
    
    ice.loadImage("ice.png");
    
    energyBall.loadImage("energyball.png");
    
    
    
    exercise01.loadImage("exercise01.png");
    exerciseList.push_back(exercise01);
    
    exercise02.loadImage("exercise02.png");
    exerciseList.push_back(exercise02);

    exercise03.loadImage("exercise03.png");
    exerciseList.push_back(exercise03);

    exercise04.loadImage("exercise04.png");
    exerciseList.push_back(exercise04);

    exercise05.loadImage("exercise05.png");
    exerciseList.push_back(exercise05);
    
    freestyle.loadImage("freestyle.png");
    exerciseList.push_back(freestyle);
}

//--------------------------------------------------------------
void testApp::update(){
    openNIDevice.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofPushMatrix();
    
    openNIDevice.drawSkeletons(0,0, ofGetWidth(), ofGetHeight());

    //draw exercises

    //exercise01
    if (rightHand.y > 0 && rightHand.y <60 && leftHand.y > 0 && leftHand.y < 60 && exerciseCounter == 0) {
        exerciseCounter++;
    }
    
    //exercise02
    else if(rightHand.x > 400 && rightHand.x <ofGetWidth() && leftHand.x > 400 && leftHand.x < ofGetWidth() && exerciseCounter ==1){
        exerciseCounter++;
    }
  
    //exercise03
    else if(rightHand.x < 220 && rightHand.x > 0 && leftHand.x < 220 && leftHand.x > 0 && exerciseCounter ==2){
        exerciseCounter++;
    }
    
    //exercise04
    else if(leftHand.x > 260-10 && leftHand.x < 260 +10 &&
            leftHand.y > 260-10 && leftHand.y < 260+10 &&
            rightHand.x > 345-10 && rightHand.x < 345+10 &&
            rightHand.y > 60-10 && rightHand.y < 60+10 &&
            exerciseCounter ==3){
        exerciseCounter++;
    }
    
    //exercise05
    else if(leftHand.x > 300-10 && leftHand.x < 300 +10 &&
            leftHand.y > 70-10 && leftHand.y < 70+10 &&
            rightHand.x > 375-10 && rightHand.x < 375+10 &&
            rightHand.y > 260-10 && rightHand.y < 260+10 &&
            exerciseCounter ==4){
        exerciseCounter++;
    }
    
    
    exerciseList[exerciseCounter].draw(0,0,ofGetWidth(),ofGetHeight());
        
    

    ofPopMatrix();
//    
    ofPushMatrix();
    // use a blend mode so we can see 'through' the mask(s)
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    
    // get number of current users
    int numUsers = openNIDevice.getNumTrackedUsers();
    
    // iterate through users
    for (int i = 0; i < numUsers; i++){
        
        // get a reference to this user
        ofxOpenNIUser & user = openNIDevice.getTrackedUser(i);
        
        // draw the mask texture for this user
//        user.drawMask();
        
        
        //nori edit
        // if you want x-coordinate leftHand.x
        ofPushMatrix();
        ofScale(1.6,1.6,1); //super hacky by michael.

        leftHand = user.getJoint(JOINT_LEFT_HAND).getProjectivePosition();
        rightHand = user.getJoint(JOINT_RIGHT_HAND).getProjectivePosition();
        centerHand = (leftHand + rightHand) /2;




//        openNIDevice.drawSkeletons();

//        ofSetColor(0,150,255);
//        ofCircle(leftHand.x, leftHand.y, 10);

//        ofSetColor(255,0,150);
//        ofCircle(rightHand.x, rightHand.y, 10);
        
        ice.draw(rightHand.x-20,rightHand.y-20,40,40);
        fire.draw(leftHand.x-20,leftHand.y-20,40,40);



        
        
        squareDistance = ((rightHand - leftHand).x*(rightHand - leftHand).x + (rightHand - leftHand).y*(rightHand - leftHand).y);
        
        if (squareDistance < 100*100 && squareDistance > 40*40) {
            //ofSetColor(255, 255, 255);
            //ofCircle(centerHand, 20);
            energyBall.draw(centerHand.x-25, centerHand.y-25, 50,50);
        }

        
        
//        for (int i=0; i<pointsOnLine.size()-1 ; i++) {
//            float sqdist = (centerHand - pointsOnLine[i]).x*(centerHand - pointsOnLine[i]).x+(centerHand - pointsOnLine[i]).y*(centerHand - pointsOnLine[i]).y;
//            if (sqdist < 10) {
////                pointsOnLine[i+1] = pointsOnLine[i];
//            }else{
//                ofSetColor(255);
//                for(int j=0; j<pointsOnLine.size()-1; j++){
//                    ofLine(pointsOnLine[j],pointsOnLine[j+1]);
//                }
//            }
//        }

        ofPopMatrix();
        

        // you can also access the pixel and texture references individually:
        
        // TEXTURE REFERENCE
        //ofTexture & tex = user.getMaskTextureReference();
        // do something with texture...
        
        // PIXEL REFERENCE
        //ofPixels & pix = user.getMaskPixels();
        // do something with the pixels...
        
        // and point clouds:
        
        ofPushMatrix();
        // move it a bit more central
     //   ofTranslate(320, 240, 10);
        user.drawPointCloud();
        
        // you can also access the mesh:
        
        // MESH REFERENCE
        //ofMesh & mesh = user.getPointCloud();
        // do something with the point cloud mesh
        
        ofPopMatrix();
        
    }
    
    
    ofDisableBlendMode();
    ofPopMatrix();

}

//--------------------------------------------------------------
void testApp::userEvent(ofxOpenNIUserEvent & event){

}

//--------------------------------------------------------------
void testApp::exit(){
    openNIDevice.stop();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}