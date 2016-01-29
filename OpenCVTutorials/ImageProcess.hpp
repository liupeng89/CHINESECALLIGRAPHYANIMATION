//
//  ImageProcess.hpp
//  OpenCVTutorials
//
//  Created by PeterLiu on 1/11/16.
//  Copyright © 2016 PeterLiu. All rights reserved.
//

#ifndef ImageProcess_hpp
#define ImageProcess_hpp

#include <iostream>
#include <string>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;
using namespace std;

/* The OpenCV image process function */

const String sourceImagePath = "/Users/peterliu/Documents/openDevelopment/one.jpg";

const String edgeDataPath = "/Users/peterliu/Documents/openDevelopment/one_edge_data.txt";

const int GAUSSIANKERNAL = 3;
const int GAUSSIANTHRESHOLD = 0.5;


// Edge detection function

Mat loadImageFile(String);

Mat processImage(Mat); // Process image---gray, denoise and filter.

void saveImageFile(Mat,String); // Save the mat data to the image file.


#endif /* ImageProcess_hpp */
