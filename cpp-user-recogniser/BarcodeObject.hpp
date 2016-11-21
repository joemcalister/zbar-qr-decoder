//
//  BarcodeObject.hpp
//  cpp-user-recogniser
//
//  Created by Joe on 21/11/2016.
//  Copyright © 2016 joemcalister. All rights reserved.
//

#ifndef BarcodeObject_hpp
#define BarcodeObject_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

class BarcodeObject
{
    public:
        string content, type;
        vector<Point>coordinates;
};

#endif /* BarcodeObject_hpp */
