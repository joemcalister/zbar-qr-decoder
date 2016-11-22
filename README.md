# QR Code detection using the ZBar Library, C++ and OpenCV

### Required
- OpenCV 3.0 (2.0 may work, but not tested)
- ZBar Library
- Xcode

## How to install ZBar
The easiest way to install ZBar is via Brew on MacOS, to install ZBar via brew simply run
```
brew install zbar
```
Manual ways of installing ZBar can be found at http://zbar.sourceforge.net

### How to use
Simply run the application and hold up a QR code, a green border will be draw around it to signify detection and the decoded contents written alongside it.
