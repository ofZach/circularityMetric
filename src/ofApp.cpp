#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    img.loadImage("bwface.jpg");
    imgCv.allocate(img.getWidth(), img.getHeight());
    imgCv.setFromPixels(img.getPixelsRef());
    imgCv.threshold(127);
    finder.findContours(imgCv, 10, 1000000, 10, false);
    
   

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    img.draw(0,0);
    finder.draw(0,0);
    
    for (int i = 0; i < finder.nBlobs; i++){
        
        ofxCvBlob blob = finder.blobs[i];
        float area = blob.area;
        float length = blob.length;
        
        float circ = (4*M_PI*area)/(length*length);
        ofDrawBitmapStringHighlight(ofToString(circ), blob.centroid);
    }
    
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
