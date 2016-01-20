//
//  Test01.cpp
//  OpenCVTutorials
//
//  Created by PeterLiu on 1/19/16.
//  Copyright © 2016 PeterLiu. All rights reserved.
//

#include "Test01.hpp"

void test(){
    Mat src = loadImageFile("/Users/peterliu/Documents/openDevelopment/one.png");
    src = processImage(src);
    
    Mat edge = erosionFunc(src, 2, 0);
    
    src = edgeDetection(src);
    edge = edgeDetection(edge);
    
    // Get all points coordinate of edge ,to Bezier curve fitting.
    int _w = src.cols;
    int _h = src.rows;
    
    Point2 *scaledEdgePoints; // All edge points of scaled edge.
    
    int edgenum = 0;
    
    for (int x = 0; x < _w; x++) {
        for (int y = 0; y < _h; y++) {
            Scalar color = edge.at<uchar>(y, x);
            if (color.val[0] == 255) {
                edgenum++;
            }
        }
    }
    cout << "The edge point number is:" << edgenum << endl;
    
    scaledEdgePoints = (Point2 *) malloc(edgenum * sizeof(Point2));
    if (scaledEdgePoints == NULL) {
        cout << " The scaled pointer is null";
    }
    
    int index = 0;
    for (int x = 0; x < _w; x++) {
        for (int y = 0; y < _h; y++) {
            Scalar color = edge.at<uchar>(y, x);
            if (color.val[0] == 255) {
                scaledEdgePoints[index].x = x;
                scaledEdgePoints[index].y = y;
                index++;
            }
            
        }
    }
    
    // Check the scaled edge points
//    for (int i = 0; i < edgenum; i++) {
//        cout << scaledEdgePoints[i].x << " " << scaledEdgePoints[i].y << endl;
//    }
    cout << "===Bezier Curve Fitting Function===" << endl;
    FitCurve(scaledEdgePoints, edgenum, 0.1);
    
    
    imshow("Erosion ", edge);
    imshow("src", src);
    waitKey(0);
    
    src.release();
    edge.release();
    free(scaledEdgePoints);
}