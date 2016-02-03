//
//  MainProcess.cpp
//  OpenCVTutorials
//
//  Created by PeterLiu on 1/19/16.
//  Copyright © 2016 PeterLiu. All rights reserved.
//

#include "MainProcess.hpp"

int _displayorder = 0;

Point2 *edgePoints;

Point2 *skeletonPoints;

int skeletonLen;

int *edgeColor;

int _width = 0;

int _height = 0;

// Get the length of skeleton
int getSkeletonLength(String){
    
    return 1;
}

// Get all the points of skeleton
Point2 *getSkeletonPoints(String){
    
    Point2 *points;
    
    return points;
}

void draw(){
    if (_displayorder == skeletonLen) {
        return;
    }
    
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    
    //    GLfloat x = tracepoints[_displayorder].x / _width;
    //    GLfloat y = 1.0 - tracepoints[_displayorder].y / _height;
    //    GLfloat ra = 100.0 /_height;
    //    GLfloat rb = 100.0 / _height;
    
    GLfloat x = skeletonPoints[_displayorder].x;
    GLfloat y = skeletonPoints[_displayorder].y;
    GLfloat ra = 20.0 ;
    GLfloat rb = 20.0 ;
    
    //    drawRect(x, y);
    drawEllipse(x, y, ra, rb);
    if (_displayorder < skeletonLen) {
        _displayorder++;
        //        cout << "num:" << _displayorder << endl;
    }
    glEnd();
    glFlush();
}

/////////////////////////////////////////////////////////////////////////////
// Draw the ellipse function.
void drawEllipse(GLfloat x,GLfloat y,GLfloat ra,GLfloat rb){
    for (GLfloat i = 0.0; i < 360.0; i+= 10.0) {
        GLfloat degInRad = i * DEG2RAD;
        GLfloat _x = floor(cos(degInRad) * ra + x);
        GLfloat _y = floor(sin(degInRad) * rb + y);
        //Check the coordiante
        
        int vertindex = (int)_x * _height + _y;
        if (edgeColor[vertindex] == 1) {
            glVertex2f(_x / _width, 1- _y/_height);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
void Timer(int){
    glutPostRedisplay();
    glutTimerFunc(_delay, Timer, 0);
}


//The main process function
void process(int argc, char **argv ) {
    
    /*
        1. Get the original image from system.
     */
    Mat src = loadImageFile(source);
    
    /*
        2. Process the image, filter and smooth.
     */
    
    src = processImage(src);
    imshow("Src", src);
    
    int width = src.cols;
    int height = src.rows;
    
//    int *edgeColor = (int *)malloc(width * height * sizeof(int));
//    
//    for (int x = 0; x < width; x++) {
//        for (int y = 0; y < height; y++) {
//            //
//            Scalar color = src.at<uchar>(y, x);
//            if (color.val[0] > 100) {
//                // White
//                edgeColor[x * height + y] = 0;
//            } else {
//                // Black
//                edgeColor[x * height + y] = 1;
//            }
//        }
//    }
//    
//    for (int i = 0; i < width * height; i++) {
//        cout << edgeColor[i] << endl;
//    }
    
    /*
        3. Get the skeleton of image.
     */
    
    Mat skeleton;
    src.copyTo(skeleton);
    bitwise_not(skeleton, skeleton);
    
    thinningImage(skeleton, skeleton);
    imshow("Thinning", skeleton);
    
    /*
        4. Add the skeleton to the original image.
     */
    

    int count = 0;
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            // Add the points of skeleton to the original image.
            Scalar color = skeleton.at<uchar>(y,x);
            if (color.val[0] != 0) {
                // The point at skeleton
                src.at<uchar>(y, x) = 255;
                count++;
            }
        }
    }
    
    imshow("Add Skeletion", src);
    cout << "count:" << count << endl;
    
    /*
        5. Convert the image to SVG.
     */
    
    saveImageFile(src, imageWithSkeletion);
    
    
    /*
        6. Modify the skeleton to fit the daily using by hand.
     */
    
    /*
        7. Covert the SVG data of skeletion to two-demantional coordinates.
     */
//    string pathdata = "m 57.752048,95.058877 c f -15.770056,1.368959 -14.91777,3.850501 1.172969,3.415252 2.956941,4.496142 4.112754,5.269142 1.155814,0.773 6.582788,2.66803 8.391682,2.78795 1.808894,0.11992 6.516476,-3.78243 9.379534,-4.71667 C 103.32388,92.077311 145.62632,91.401333 182.24479,90.78927 l 47.86454,0.67415 9.43808,-2.808949 c 11.5623,4.366148 14.58581,7.820893 19.94355,17.134609 -1.35356,5.61311 -4.40728,8.89499 -8.87628,7.07856 -2.38642,-6.93931 -5.54367,-9.2876 -12.64028,-11.51671";
    
//    int skeletionLength = 0;
//    Point2 *skeletionPoints ;
//    
//    // SVG --> 2D points
//    skeletionLength = getSkeletonLength(pathdata);
//    
//    skeletionPoints = getSkeletonPoints(pathdata);
//    
//    if (skeletionLength == 0 || skeletionPoints == NULL) {
//        return;
//    }
    
    /*
        8. Animation based on the edge data and skeleton data.
     */
    
    // 8.1 Get the edge of image.
    Mat imgWithSkeleton = imread(imageWithSkeletionModified);
    imshow("modified ", imgWithSkeleton);
    imgWithSkeleton = processImage(imgWithSkeleton);
    
    imshow("The modified image", imgWithSkeleton);
    cout << "color" << ((Scalar)imgWithSkeleton.at<uchar>(0,0)).val[0]<< endl;
    // The start point of skeleton is (58, 95)
    // Get the start point
    int x0 = 71;
    int y0 = 118;
    Point2 *start = (Point2 *)malloc(sizeof(Point2));
    start->x = x0;
    start->y = y0;
    
    Mat imgModified = imread(imageModified);
    imgModified = processImage(imgModified);
    imshow("imgmodified", imgModified);
    _width = imgModified.cols;
    _height = imgModified.rows;
    
    edgeColor = (int *)malloc(_width * _height * sizeof(int));
    
    for (int x = 0; x < _width; x++) {
        for (int y = 0; y < _height; y++) {
                //
            Scalar color = imgModified.at<uchar>(y, x);
            if (color.val[0] == 255) {
                // White
                edgeColor[x * _height + y] = 0;
            } else {
                // Black
                edgeColor[x * _height + y] = 1;
            }
        }
    }
    
    cout << "0: " << edgeColor[0] << " " << edgeColor[_width * _height - 1] << endl;
    
    // Skeleton length
    skeletonLen = 0;
    
    for (int x = 0; x < _width; x++) {
        for (int y = 0; y < _height; y++) {
            //
            Scalar color = imgWithSkeleton.at<uchar>(y, x);
            if (color.val[0] == 255 && edgeColor[x * _height + y] == 1) {
                //
                skeletonLen++;
            }
        }
    }
    
    cout << "Trace Length " << skeletonLen << endl;
    
    // 8.2 Get the points of skeleton.
    skeletonPoints = (Point2 *)malloc(skeletonLen * sizeof(Point2));
    
    if (skeletonPoints == NULL) {
        return;
    }
    
    int index = 0;
    for (int x = 0; x < _width; x++) {
        for (int y = 0; y < _height; y++) {
            //
            Scalar color = imgWithSkeleton.at<uchar>(y, x);
            if (color.val[0] == 255 && edgeColor[x * _height + y] == 1) {
                //
                skeletonPoints[index].x = x;
                skeletonPoints[index].y = y;
                index++;
            }
        }
    }
    // Sorted the skeleton point
    skeletonPoints = sortPoints(skeletonPoints, skeletonLen);
    skeletonPoints[skeletonLen-1].x = skeletonPoints[skeletonLen-2].x;
    skeletonPoints[skeletonLen-1].y = skeletonPoints[skeletonLen-2].y;
    
    // Fix the error points
    for (int i = 0; i < skeletonLen; i++) {
        cout << "x " << skeletonPoints[i].x << " " << skeletonPoints[i].y << endl;
    }
    
    
    // 8.3 Animation
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(_width, _height);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Chinese Animation");
    
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    
    glutDisplayFunc(draw);
    Timer(0);
    glutMainLoop();
    
    
    // Clean
    waitKey(0);
    src.release();
    skeleton.release();
    imgWithSkeleton.release();
    imgModified.release();
    
//    free(skeletionPoints);
}