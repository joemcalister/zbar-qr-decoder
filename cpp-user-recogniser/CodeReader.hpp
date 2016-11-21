//
//  CodeReader.hpp
//  cpp-user-recogniser
//
//  Created by Joe on 21/11/2016.
//  Copyright © 2016 joemcalister. All rights reserved.
//

#ifndef CodeReader_hpp
#define CodeReader_hpp

#include <stdio.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <zbar.h>
#include <iostream>
#include <string>
#include "BarcodeObject.hpp"

using namespace cv;
using namespace std;
using namespace zbar;

class CodeReader
{
    private:
        ImageScanner imgScanner;
    public:
        CodeReader();
        vector<BarcodeObject> analyseFrame(Mat frame);
        Mat drawObjects(vector<BarcodeObject> barcodes, Mat frame);
};

#endif /* CodeReader_hpp */
