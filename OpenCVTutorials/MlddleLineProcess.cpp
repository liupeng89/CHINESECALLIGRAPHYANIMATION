//
//  MlddleLineProcess.cpp
//  OpenCVTutorials
//
//  Created by PeterLiu on 11/8/15.
//  Copyright © 2015 PeterLiu. All rights reserved.
//

#include "MlddleLineProcess.hpp"


/* Middle line or Center line */
void middleLine()
{
    int pathLen; // Path length
    
    //Read image
    Mat source = loadImageFile(imageSrc);
    
    // Gray the image
    cvtColor(source, source, CV_BGR2GRAY);
    threshold(source, source, 128, 255, CV_THRESH_BINARY);
    
    // Thinning function
    Mat thinning;
    thinningImage(source, thinning);
    imshow("source", source);
    imshow("Thinning ", thinning);
    
    cout << source.channels() << endl;
    // Get the max length from left to right.
    
    int leftPointX = 0;
    int rigthPointX = 0;
    
    int rows = source.rows;
    int cols = source.cols;
    
    cout << rows << endl;
    cout << cols << endl;
    // Left start point
    for (int r = 0; r < rows; r++) {
        bool isEnd = false;
        for (int c = 0; c < cols; c++) {
            // left
            Scalar color = source.at<uchar>(c,r);
            if (color.val[0] < 254) {
                leftPointX = r;
                isEnd = true;
                break;
            }
        }
        if (isEnd) {
            break;
        }
    }
    
    // Right end point
    for (int r = rows-1; r >0 ; r--) {
        bool isEnd = false;
        for (int c = 0; c < cols; c++) {
            //Right
            Scalar color = source.at<uchar>(c,r);
            if (color.val[0] < 254) {
                rigthPointX = r;
                isEnd = true;
                break;
            }
        }
        if (isEnd) {
            break;
        }
    }
        
    cout << "left:" << leftPointX << endl;
    cout << "right:" << rigthPointX << endl;
    
    pathLen = rigthPointX - leftPointX;
    cout << "len:" << pathLen << endl;
    
    if (pathLen == 0) {
        return;
    }
    
    // Calculate the middle line of image.
    CenterLineElement paths[pathLen];
    
    for (int x = leftPointX; x < rigthPointX; x++) {
        // Get the middle line.
        int minCol = 0;
        int maxCol = 0;
        for (int y = 0; y < rows; y++) {
            //
            Scalar color = source.at<uchar>(y,x);
            // The black point.
            if (color.val[0] < 254) {
                // min col
                minCol = y;
                break;
            }
        }
        
        //Max col
        for (int y = minCol+1; y < rows; y++) {
            //
            Scalar color = source.at<uchar>(y,x);
            // The black point.
            if (color.val[0] >= 254) {
                // min col
                maxCol = y-1;
                break;
            }
        }
        //Path element
        int middleCol = minCol + (maxCol - minCol + 1) / 2;
        paths[x-leftPointX].y = x;
        paths[x-leftPointX].x = middleCol;
        paths[x-leftPointX].ra = ellipseRA;
        paths[x-leftPointX].rb = (maxCol - minCol + 1) / 2;
        
        // Calculate the alpha value
        if (x == leftPointX || x == rigthPointX-1) {
            paths[x-leftPointX].alpha = 0;
        }else {
            paths[x-leftPointX].alpha = atan((x - paths[x-leftPointX-1].y)/(middleCol - paths[x-leftPointX-1].x));
        }
        
        cout << paths[x-leftPointX].x << ":" << paths[x-leftPointX].y << "--" << paths[x-leftPointX].ra << ":" << paths[x-leftPointX].rb << endl;
        
    }
    //Modify the start and end alpha
    paths[0].alpha = paths[1].alpha;
    paths[rigthPointX-leftPointX-1].alpha = paths[rigthPointX-leftPointX-2].alpha;
    
    // Write to file
    FILE *ofp = fopen(pathTxt.c_str(), "w");
    
    if (ofp == NULL) {
        cout << "Open file error!" << endl;
    }
    
    for (int i = 0; i < pathLen; i++) {
        // writh file
        fprintf(ofp, "%f %f %f %f %f\n",paths[i].y,paths[i].x,paths[i].ra,paths[i].rb,paths[i].alpha);
    }
    fclose(ofp);

}

/* Load image file*/
Mat loadImageFile(String path)
{
    Mat source = imread(path);
    
    if (source.empty()) {
        cout << "Load file error!" << endl;
    }
    return source;
}




/* Get the middle line path. */
CenterLineElement* getMiddleLine()
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
    CenterLineElement paths[pathLen];
    
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