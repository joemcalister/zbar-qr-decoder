# ZBar QR Detector and Decoder
Barcode detection and decoding using OpenCV 3.0 and ZBar.

## Requirements
OpenCV 3.0,
ZBar.

## How to Install OpenCV and ZBar
OpenCV 3.0 can be found at [opencv.org](http://opencv.org).
The easiest way to install ZBar is with Brew.
Once Brew is installed simply type
```
Brew install ZBar
```

## Linker flags
-lopencv_calib3d, -lopencv_core, -lopencv_features2d, -lopencv_flann, -lopencv_highgui, -lopencv_imgproc, -lopencv_xfeatures2d, -lopencv_videoio, -lopencv_imgcodecs, -zbar
