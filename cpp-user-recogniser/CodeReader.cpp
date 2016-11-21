//
//  CodeReader.cpp
//  cpp-user-recogniser
//
//  Created by Joe on 21/11/2016.
//  Copyright © 2016 joemcalister. All rights reserved.
//

#include "CodeReader.hpp"

CodeReader::CodeReader()
{
    imgScanner.set_config(ZBAR_NONE, ZBAR_CFG_ENABLE, 1);
}

vector<BarcodeObject> CodeReader::analyseFrame(Mat frame)
{
    // create grayscale version of image frame
    Mat currentFrameGrey;
    cvtColor(frame, currentFrameGrey, CV_BGR2GRAY);
    
    // get the width and height of the frame
    int width = frame.cols;
    int height = frame.rows;
    
    // get the uchar of the grayscale image
    uchar *raw = (uchar *)currentFrameGrey.data;
    Image image(width, height, "Y800", raw, width * height);
    
    // scan this image for qr codes
    imgScanner.scan(image);
    
    // create vector to return
    vector<BarcodeObject> returnObjs;
    
    // extract results
    for(Image::SymbolIterator symbolIt = image.symbol_begin(); symbolIt != image.symbol_end(); ++symbolIt) {
        
        // create a vector to store points
        vector<Point> vecP;
        
        // note that we have decoded it!
        cout << "Decoded a " << symbolIt->get_type_name() << " with the value " << symbolIt->get_data() << endl;
        
        // draw a bounding rectangle around the symbol
        int locSize = symbolIt->get_location_size();
        
        // loop through coordinates and add to the vector vecP
        for (int i=0; i<locSize; i++) {
            vecP.push_back( Point(symbolIt->get_location_x(i), symbolIt->get_location_y(i)) );
        }
    
        // create the barcode object
        BarcodeObject bObject;
        bObject.coordinates = vecP;
        bObject.content = symbolIt->get_data();
        bObject.type = symbolIt->get_type_name();
        
        // push object back
        returnObjs.push_back(bObject);
    }
    
    return returnObjs;
}


// draw the objects
Mat CodeReader::drawObjects(vector<BarcodeObject> barcodes, Mat frame)
{
    Mat newFrame = frame;
    
    for (auto &barcode:barcodes)
    {
        // create the rotated rectangle from the points collected above
        RotatedRect rect = minAreaRect(barcode.coordinates);
        
        // loop through sides and draw
        Point2f pts[4];
        rect.points(pts);
        for (int i=0; i<4; i++) {
            line(newFrame, pts[i], pts[(i+1)%4], Scalar(0,255,0), 3);
            
            // draw the decoded text next to the barcode
            if (i == 0)
            {
                putText(frame, barcode.content, Point2f(pts[i].x + 10,pts[i].y), FONT_HERSHEY_SIMPLEX, 0.8,  Scalar(0,255,0));
            }
        }
    }
    
    return newFrame;
}
