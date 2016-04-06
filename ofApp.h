#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "ofxCv.h"
//#include "ofxNetwork.h"

static const int video_width = 640;
static const int video_height = 480;

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofVideoGrabber vidGrabber;
    ofxCvColorImage colorImage;
    ofxCv::ContourFinder contourfinder;
    
    cv::Mat* src_img;//ビデオ映像
    cv::Mat* hsv_img;//HSV変換映像
    cv::Mat* detection_img;//特定色検出映像
    cv::Mat* gray_img;//グレースケール映像
    cv::Mat* binary_image;//２値化映像
    
    ofImage output_image;
    
};