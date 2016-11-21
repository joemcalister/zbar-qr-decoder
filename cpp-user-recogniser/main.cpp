//
//  main.cpp
//  cpp-user-recogniser
//
//  Created by Joe on 21/11/2016.
//  Copyright © 2016 joemcalister. All rights reserved.
//

#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "CodeReader.hpp"
#include "BarcodeObject.hpp"

using namespace cv;
using namespace std;

int main( int argc, char** argv )
{
    // init code reader class
    CodeReader codeReader = CodeReader();

    // setup video capture
    VideoCapture cap(0);
    
    // this will store the camera frames
    Mat frame;
    
    // loop reading the current camera frame into the frame Mat
    while (cap.read(frame)) {
        
        // create a vector full of barcode objects from the code reader class
        vector<BarcodeObject> objects = codeReader.analyseFrame(frame);
        
        // create the annotated image using the reader class
        Mat annotated = codeReader.drawObjects(objects, frame);
        
        // display the annotated image
        imshow("Frame", annotated);
        
        // without this the camera feed will not run on macos
        if (waitKey(1) == 'q') {
            break;
        }
    }
    return 0;
}

