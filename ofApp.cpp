#include "ofApp.h"

using namespace cv;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    vidGrabber.setVerbose(true);
    vidGrabber.initGrabber(video_width, video_height);
    
    src_img = new Mat(video_width, video_height, CV_8UC3);
    hsv_img = new Mat(video_width, video_height, CV_8UC3);
    gray_img = new Mat(video_width, video_height, CV_8UC1);
    binary_image = new Mat(video_width, video_height, CV_8UC1);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    vidGrabber.update();
    
    // 画像が更新されていなかったら以降の処理は行わない
    if( !vidGrabber.isFrameNew() ) return;
        
    colorImage.setFromPixels(vidGrabber.getPixels());
    src_img->data = ofxCv::toCv(colorImage).data;
    
    cvtColor(*src_img, *hsv_img, CV_BGR2HSV);
    
    for(int y=0; y<video_height; y++)
    {
        for(int x=0; x<video_width; x++)
        {
            int index = y * video_width + x;
            int index3 = index * 3;
            
            if(hsv_img->data[index3] >= 0 &&
               hsv_img->data[index3] <= 30 &&
               hsv_img->data[index3+1] >= 20 &&
               hsv_img->data[index3+2] >= 20)
            {
                binary_image->data[index] = 255;
            }else{
                binary_image->data[index] = 0;
            }
        }
    }
    
//    contourfinder.findContours(*binary_image);
    
    output_image.setFromPixels(binary_image->data, video_width, video_height, OF_IMAGE_GRAYSCALE);
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    vidGrabber.draw(0, 0);
    output_image.draw(512,0);
    contourfinder.draw();
    
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
