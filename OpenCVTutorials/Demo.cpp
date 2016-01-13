//
//  Demo.cpp
//  OpenCVTutorials
//
//  Created by PeterLiu on 1/13/16.
//  Copyright © 2016 PeterLiu. All rights reserved.
//

#include "Demo.hpp"

Mat imageprocess(string source){
    Mat src;
    
    // Load image file.
    src = imread(source);
    if (src.empty()) {
        cout << "The image file is empty!" << endl;
        return src;
    }
    
    // Gray
    cvtColor(src, src, CV_BGR2GRAY, 1);
    
    return src;
}

// Demo operation
void demo(){
    // 1. Image process
    Mat src = imageprocess(source);
    imshow("src", src);
    int _width = src.cols;
    int _height = src.rows;
    
    // 2. Edge detection
    Mat edge ;
    src.copyTo(edge);
    edge = edgeDetection(edge);
    saveEdgeDataToFile(edge, edgedatafile);
    imshow("edge", edge);
    
    // 3. Trace Line detection
    Mat thinning;
    src.copyTo(thinning);
    bitwise_not(thinning, thinning);
    
    thinningImage(thinning, thinning);
    
    // Save the trace data to file
    FILE *ofp = fopen(thinningdatafile.c_str(), "w");
    if (ofp == NULL) {
        cout << "Thinning data file open failed!"<< endl;
    }
    
    for (int x = 0; x < _width; x++) {
        for (int y = 0; y < _height; y++) {
            // save the data.
            Scalar color = thinning.at<char>(y, x);
            if (color.val[0] != 0) {
                // white point save
                fprintf(ofp, "%d %d\n", x, y);
            }
            
        }
    }
    
    fclose(ofp);
    
    imshow("thinning", thinning);
    
    waitKey(0);
    
    
    src.release();
    edge.release();
    thinning.release();

    
    // 4. Animation
}