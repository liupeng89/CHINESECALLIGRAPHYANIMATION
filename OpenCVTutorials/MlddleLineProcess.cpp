//
//  MlddleLineProcess.cpp
//  OpenCVTutorials
//
//  Created by PeterLiu on 11/8/15.
//  Copyright © 2015 PeterLiu. All rights reserved.
//

#include "MlddleLineProcess.hpp"

void middleLine()
{
    int pathLen; // Path length
    
    //Read image
    Mat source = imread("/Users/peterliu/Documents/openDevelopment/one.png");
    if (source.empty()) {
        cout << "Read file error!" <<endl;
    }
    // Get the max length from left to right.
    
    int leftPointY = 0;
    int rigthPointY = 0;
    
    int rows = source.rows;
    int cols = source.cols;
    
    cout << rows << endl;
    cout << cols << endl;
    // Left start point
    for (int c = 0; c < cols; c++) {
        bool isEnd = false;
        for (int r = 0; r < rows; r++) {
            // left
            Vec3b color = source.at<Vec3b>(Point(r,c));
            // The point is black color.
            if (color[0] < 10 &&color[1] < 10 && color[2] < 10) {
                // Left point
                leftPointY = c;
                isEnd = true;
                break;
            }
            
        }
        if (isEnd) {
            break;
        }
    }
    // Right end point
    for (int c = cols-1; c > 0; c--) {
        bool isEnd = false;
        for (int r = 0; r < rows; r++) {
            //left
            Vec3b color = source.at<Vec3b>(Point(r,c));
            // The point is black color.
            if (color[0] < 10 &&color[1] < 10 && color[2] < 10) {
                // Left point
                rigthPointY = c;
                isEnd = true;
                break;
            }
        }
        if (isEnd) {
            break;
        }
    }
    
    cout << "left:" << leftPointY << endl;
    cout << "right:" << rigthPointY << endl;
    
    pathLen = rigthPointY - leftPointY;
    cout << "len:" << pathLen << endl;
    
    if (pathLen == 0) {
        return;
    }
    
    // Calculate the middle line of image.
    MiddleLineElement paths[pathLen];
    
    for (int i = leftPointY; i < rigthPointY; i++) {
        // Get the middle line.
        int minCol = 0;
        int maxCol = 0;
        for (int j = 0; j < cols; j++) {
            //
            Vec3b color = source.at<Vec3b>(Point(j,i));
            // The black point.
            if (color[0] < 10 && color[10] < 10 && color[10] < 10) {
                // min col
                minCol = j;
                break;
            }
        }
        
        //Max col
        for (int j = 0; j < cols; j++) {
            //
            Vec3b color = source.at<Vec3b>(Point(j,i));
            // The black point.
            if (color[0] < 10 && color[10] < 10 && color[10] < 10) {
                // min col
                maxCol = j;
            }
        }
        
        int middleCol = minCol + (maxCol - minCol + 1) / 2;
        paths[i-leftPointY].y = i;
        paths[i-leftPointY].x = middleCol;
        paths[i-leftPointY].ra = 5;
        paths[i-leftPointY].rb = (maxCol - minCol + 1) / 2;
        
        cout << paths[i-leftPointY].x << ":" << paths[i-leftPointY].y << "--" << paths[i-leftPointY].ra << ":" << paths[i-leftPointY].rb << endl;
        
    }
    
    // Write to file
    FILE *ofp = fopen("/Users/peterliu/Documents/openDevelopment/path.txt", "w");
    
    if (ofp == NULL) {
        cout << "Open file error!" << endl;
    }
    
    for (int i = 0; i < pathLen; i++) {
        // writh file
        fprintf(ofp, "%f %f %f %f\n",paths[i].x,paths[i].y,paths[i].ra,paths[i].rb);
    }
    fclose(ofp);

}


MiddleLineElement* getMiddleLine()
{
    
    int pathLen; // Path length
    
    //Read image
    Mat source = imread("/Users/peterliu/Documents/openDevelopment/one.png");
    if (source.empty()) {
        cout << "Read file error!" <<endl;
    }
    // Get the max length from left to right.
    
    int leftPointY = 0;
    int rigthPointY = 0;
    
    int rows = source.rows;
    int cols = source.cols;
    
    cout << rows << endl;
    cout << cols << endl;
    // Left start point
    for (int c = 0; c < cols; c++) {
        bool isEnd = false;
        for (int r = 0; r < rows; r++) {
            // left
            Vec3b color = source.at<Vec3b>(Point(r,c));
            // The point is black color.
            if (color[0] < 10 &&color[1] < 10 && color[2] < 10) {
                // Left point
                leftPointY = c;
                isEnd = true;
                break;
            }

        }
        if (isEnd) {
            break;
        }
    }
    // Right end point
    for (int c = cols-1; c > 0; c--) {
        bool isEnd = false;
        for (int r = 0; r < rows; r++) {
            //left
            Vec3b color = source.at<Vec3b>(Point(r,c));
            // The point is black color.
            if (color[0] < 10 &&color[1] < 10 && color[2] < 10) {
                // Left point
                rigthPointY = c;
                isEnd = true;
                break;
            }
        }
        if (isEnd) {
            break;
        }
    }
    
    cout << "left:" << leftPointY << endl;
    cout << "right:" << rigthPointY << endl;
    
    pathLen = rigthPointY - leftPointY + 1;
    cout << "len:" << pathLen << endl;
    
    if (pathLen == 0) {
        return NULL;
    }
    
    // Calculate the middle line of image.
    MiddleLineElement paths[pathLen];
    
    for (int i = leftPointY; i < rigthPointY; i++) {
        // Get the middle line.
        int minCol = 0;
        int maxCol = 0;
        for (int j = 0; j < cols; j++) {
            //
            Vec3b color = source.at<Vec3b>(Point(j,i));
            // The black point.
            if (color[0] < 10 && color[10] < 10 && color[10] < 10) {
                // min col
                minCol = j;
                break;
            }
        }
        
        //Max col
        for (int j = 0; j < cols; j++) {
            //
            Vec3b color = source.at<Vec3b>(Point(j,i));
            // The black point.
            if (color[0] < 10 && color[10] < 10 && color[10] < 10) {
                // min col
                maxCol = j;
            }
        }
        
        int middleCol = minCol + (maxCol - minCol + 1) / 2;
        paths[i-leftPointY].y = i;
        paths[i-leftPointY].x = middleCol;
        paths[i-leftPointY].ra = 5;
        paths[i-leftPointY].rb = (maxCol - minCol + 1) / 2;
        
        cout << paths[i-leftPointY].x << ":" << paths[i-leftPointY].y << "--" << paths[i-leftPointY].ra << ":" << paths[i-leftPointY].rb << endl;

    }
    
    return paths;
}