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
    
    //Sorted the edge points
    Point2 *sortedPoints = sortPoints(scaledEdgePoints, edgenum);
    
    
    
    // Modify the error point  0<= x1-x0 <=1 and 0<= y1-y0<=1
//    for (int i = 1; i < edgenum; i++) {
//        //
//        if ((0<= abs(sortedPoints[i-1].x-sortedPoints[i].x) && 1>= abs(sortedPoints[i-1].x - sortedPoints[i].x))&&(0<= abs(sortedPoints[i-1].y-sortedPoints[i].y) && 1>= abs(sortedPoints[i-1].y - sortedPoints[i].y))) {
//            
//        }else{
//            sortedPoints[i].x = sortedPoints[i-1].x;
//            sortedPoints[i].y = sortedPoints[i-1].y;
//        }
//    }
    
    for (int i = 0; i < edgenum; i++) {
        cout << sortedPoints[i].x << " " << sortedPoints[i].y  << endl;
    }
    
    // Check the scaled edge points
//    for (int i = 0; i < edgenum; i++) {
//        cout << scaledEdgePoints[i].x << " " << scaledEdgePoints[i].y << endl;
//    }
    cout << "===Bezier Curve Fitting Function===" << endl;
    
    
//    FitCurve(sortedPoints, edgenum, 4.0);
//
//    
//    imshow("Erosion ", edge);
//    imshow("src", src);
    
    Point2 d[7] = {	/*  Digitized points */
        { 0.0, 0.0 },
        { 0.0, 0.5 },
        { 1.1, 1.4 },
        { 2.1, 1.6 },
        { 3.2, 1.1 },
        { 4.0, 0.2 },
        { 4.0, 0.0 },
    };
    double error = 4.0;
    FitCurve(d, 7, error);
    
    waitKey(0);
    
    src.release();
    edge.release();
    free(scaledEdgePoints);
}