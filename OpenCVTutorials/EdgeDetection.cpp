//
//  EdgeDetection.cpp
//  OpenCVTutorials
//
//  Created by PeterLiu on 1/11/16.
//  Copyright © 2016 PeterLiu. All rights reserved.
//

#include "EdgeDetection.hpp"

// Edge detection function
Mat edgeDetection(Mat source)
{
    if (source.empty()) {
        cout << "The source file is empty!" << endl;
        return source;
    }
    
    Mat edge;
    // Canny edge detection algorithm
    Canny(source, edge, 3, 3);
    return edge;
}

//Save the edge data to file
void saveEdgeData(Mat source)
{
    if (source.empty()) {
        cout << "The source is empty!" << endl;
        return;
    }
    cout << "save the edge point coordinate" << endl;
    // source is not null
    // Get the coordinate of point on edge and save to file.
    int _width = source.cols;
    int _height = source.rows;
    
    for (int x = 0; x < _height; x++) {
        for (int y = 0; y < _width; y++) {
            Scalar color = source.at<char>(y, x);
            if (color.val[0] != 0) {
                cout << "x:" << x << "," << "y:" << y << endl;
            }
        }
    }
    
}