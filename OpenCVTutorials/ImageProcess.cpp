//
//  ImageProcess.cpp
//  OpenCVTutorials
//
//  Created by PeterLiu on 1/11/16.
//  Copyright © 2016 PeterLiu. All rights reserved.
//

#include "ImageProcess.hpp"

// Load image file and process
Mat loadImageFile(String path)
{
    // Load the source file
    Mat source = imread(path);
    if (source.empty()) {
        cout << "Source image file is empty!" << endl;
    }
    return source;
}

// Process the image function---gray , denoise and filter
Mat processImage(Mat source)
{
    if (source.empty()) {
        cout<< "soure file is empty!" << endl;
        return source;
    }
    
    int grayThreshold = 100;
    
    Mat gray;
    
    // GaussianBlur
    GaussianBlur(source, gray, Size(GAUSSIANKERNAL, GAUSSIANKERNAL), GAUSSIANTHRESHOLD);
    
    // Gray the image file
    cvtColor(gray, gray, CV_BGR2GRAY);
    threshold(gray, gray, grayThreshold, 255, CV_THRESH_BINARY);
    
    return gray;
}

