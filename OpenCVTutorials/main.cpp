//
//  main.cpp
//  OpenCVTutorials
//
//  Created by PeterLiu on 10/12/15.
//  Copyright © 2015 PeterLiu. All rights reserved.
//
#include <string>
#include <iostream>
//#include "ImgProcess.hpp"
//#include "FitCurve.hpp"
#include "ThinningProcess.hpp"
#include <GLUT/GLUT.h>
#include <math.h>
#include "MlddleLineProcess.hpp"
using namespace std;

const int WindowWidth = 300;
const int WindowHeight = 300;

const String pathSrc = "/Users/peterliu/Documents/openDevelopment/path.txt";
//const String pathSrc = "/Users/heermaster/Documents/openDevelopment/path.txt";

int discount = 0;
const int pathLen = 260;

const int delay = 5; // Delay ms

typedef float GLfloat;
typedef int GLint;

#define sizeofa(array) sizeof array / sizeof array[0]

GLfloat gfPosX = 0.25;
GLfloat gfDeltaX = 0.005;
GLfloat fontSizeDelta = 0.001;
GLfloat fontSize = 0.00;
const float DEG2RAD = 3.14159 / 180.0;

// Paths array
struct CenterLineElement paths[241];
CenterLineElement *centerPath;

void DrawCircle(float cx, float cy, float r, int num_segments);
void DrawEllipse(CenterLineElement element);
void DrawEllipse();
void Timer(int iUnused);
void Initialize();

void drawEllipse(float dx, float dy, float xradius, float yradius);
void drawEllipse(float dx, float dy, float xradius, float yradius, float alpha);
void initPath();



/*
    Draw the ellipse object.
 */
void Draw() {
    
    if (discount == pathLen) {
        return;
    }

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    
//    drawEllipse(paths[discount].x, paths[discount].y, paths[discount].ra, paths[discount].rb, paths[discount].alpha);
    drawEllipse(paths[discount].x, paths[discount].y, paths[discount].ra, paths[discount].rb);
    if (discount < pathLen) {
        discount++;
    }
    
    cout << discount << endl;
    cout << paths[discount].x << ":" << paths[discount].y << ":" << paths[discount].ra << ":" << paths[discount].rb << ":" << paths[discount].alpha << endl;
    
    //Test for drawing the general ellipse
//    drawEllipse(0.25, 0.3, 0.005, 0.02, 0.4);
//    drawEllipse(0.45, 0.3, 0.005, 0.02);
    
    glEnd();
    glFlush();
}

/* Draw the ellipse */
void drawEllipse(float dx, float dy, float xradius, float yradius)
{
    for (float i = 0.0; i < 360.0; i+=0.1) {
        float degInRad = i * DEG2RAD;
        glVertex2f(cos(degInRad)*xradius + dx, sin(degInRad)*yradius + dy);
    }
    
}
/*Draw the general ellipse*/
// Ellipse rotation
// alphe = a * pai / 180
void drawEllipse(float dx, float dy, float xradius, float yradius, float alpha)
{
    for (float i = 0.0; i < 360.0; i+=0.1) {
        float degInRad = i * DEG2RAD;
        float orignx = cos(degInRad)*xradius + dx;
        float origny = sin(degInRad)*yradius + dy;
        /*
            rotation formula 
            x' = x * cos(a) - y * sin(a)
            y' = x * sin(a) + y * cos(a)
         */
        float x = orignx * cos(alpha) - origny * sin(alpha);
        float y = orignx * sin(alpha) + origny * cos(alpha);
        
        glVertex2f(x, y); // Ellipse rotation
    }
}

/* Init the paths array */
void initPath()
{
    
    int index = 0;
    /* Method one: */
    // Load path information.
    
    // Load image
    middleLine();
    
    FILE *fr = fopen(pathSrc.c_str(), "r");
    
    float pointx, pointy, ra, rb, alpha;
    // Path information convertion
    while (fscanf(fr, "%f %f %f %f %f", &pointx, &pointy, &ra, &rb, &alpha) == 5) {
        cout << pointx << ":" << pointy << ":"  << ra << ":"  << rb << endl;
        paths[index].x = pointx / WindowWidth;
        paths[index].y = 1 - pointy / WindowHeight;
        
        paths[index].ra = ra / 1000.0;
        paths[index].rb = rb / 300.0;
        paths[index].alpha = alpha;
        index++;
    }
//
    /* Method two: */
//    CenterLineElement *centerPathLine = initCenterPath();
//    index = 0;
//    CenterLineElement tmp = *(centerPathLine + index);
//    while (tmp.x >=0 && tmp.x < 300 && tmp.y >=0 && tmp.y < 300) {
//        //
//        paths[index].x = tmp.x / 300.0;
//        paths[index].y = 1 - tmp.y / 300.0;
//        
//        paths[index].ra = tmp.ra / 300.0;
//        paths[index].rb = tmp.rb / 300.0;
//        paths[index].alpha = tmp.alpha;
//        index++;
//        tmp = *(centerPathLine + index);
//    }
}



/*Timer function*/
void Timer(int iUnused)
{
    glutPostRedisplay();
    glutTimerFunc(delay, Timer, 0);

}

/* Initialize */
void Initialize() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
   
    // Init the paths
    initPath();
    
}

int main(int argc, char** argv) {

    /* OpenGL Animation */
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WindowWidth, WindowHeight);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Chinese Animation");
    Initialize();
    glutDisplayFunc(Draw);
    Timer(0);
    glutMainLoop();
    
//    // Thinning function
//    Mat source = imread("/Users/peterliu/Documents/openDevelopment/one.jpg");
//    if (source.empty()) {
//        cout<< "Load image error!" << endl;
//    }
//    
//    imshow("source", source);
//    
//    // Gray the image
//    cvtColor(source, source, CV_BGR2GRAY);
//    threshold(source, source, 128, 255, CV_THRESH_BINARY);
//    Mat source_copy;
//    source.copyTo(source_copy);
//    // Change color
//    bitwise_not(source, source);
//    Mat thinning;
//    
//    thinningImage(source, thinning);
//    
//    // Get the center line coordinates.
//    int thin_rows = thinning.rows;
//    int thin_cols = thinning.cols;
//    
//    CenterLineElement centerPaths[thin_cols];
//    int pathIndex = 0;
//    
//    for (int x = 0; x < thin_cols; x++) {
//        for (int y = 0; y < thin_rows; y++) {
//            //
//            Scalar color = thinning.at<uchar>(Point(x,y));
//            if (color.val[0] > 254) {
//                // Save the coordinates.
//                centerPaths[pathIndex].x = x;
//                centerPaths[pathIndex].y = y;
//                // ra and rb
//                // alpha
//                pathIndex++;
//            }
//        }
//    }
//    
//    /* Calculate the center line length. */
//    int centerLength = 0;
//    
//    for (int i = 0; i < thin_cols; i++) {
//        // print the center line coordinations
//        if (centerPaths[i].x <= 1.0 || centerPaths[i].x > 300) {
//            break;
//        }
//        centerLength++;
//    }
//    cout<< "Length:" << centerLength << endl;
//    
//    
//    /* Calculate the alpha */
//    for (int index = 0; index < centerLength; index++) {
//        if (index == 0 || index == centerLength-1) {
//            centerPaths[index].alpha = 0.0;
//        }else {
//            if (centerPaths[index].x - centerPaths[index-1].x != 0) {
//                centerPaths[index].alpha = atan((centerPaths[index].y - centerPaths[index-1].y)/(centerPaths[index].x - centerPaths[index-1].x));
//            }
//        }
//    }
//    
//    //Start point and end point, to keep the continuity.
//    centerPaths[0].alpha = centerPaths[1].alpha;
//    centerPaths[centerLength-1].alpha = centerPaths[centerLength - 2].alpha;
//    
//    // Remove noises too small == 0
//    for (int i = 0; i < centerLength; i++) {
//        if (centerPaths[i].alpha < 0.01) {
//            centerPaths[i].alpha = 0.0;
//        }
//    }
//    
//    /* Calculate the Ra and Rb. */
//    
//    for (int i = 1; i < centerLength; i++) {
//        //
//        int x_o = centerPaths[i].x;
//        int y_o = centerPaths[i].y;
//        int offset = 1;
//        // Positive
//        int x = x_o + offset;
//        int y;
//        if (centerPaths[i].alpha != 0.0) {
//            y = (x_o - x) / tan(centerPaths[i].alpha) + y_o;
//        }else {
//            y = y_o + offset;
//        }
//        Scalar color = source_copy.at<uchar>(Point(x, y));
//        while (color.val[0] < 254) {
//            x += offset;
//            if (centerPaths[i].alpha != 0.0) {
//                y = (x_o - x) / tan(centerPaths[i].alpha) + y_o;
//            }else{
//                y += offset;
//            }
//            color = source_copy.at<uchar>(Point(x, y));
//        }
//        int _x1 = x;
//        int _y1 = y;
//        
//        //Negative
//        x = x_o - offset;
//        if (centerPaths[i].alpha != 0.0) {
//            y = (x_o - x) / tan(centerPaths[i].alpha) + y_o;
//        }else {
//            y = y_o + offset;
//        }
//        
//        color = source_copy.at<uchar>(Point(x,y));
//        while (color.val[0] < 254) {
//            x -= offset;
//            if (centerPaths[i].alpha != 0.0) {
//                y = (x_o - x) / tan(centerPaths[i].alpha) + y_o;
//            }else{
//                // Vertical coordinate
//                y -= offset;
//            }
//            color = source_copy.at<uchar>(Point(x, y));
//        }
//        
//        int _x2 = x;
//        int _y2 = y;
//        
//        float tmpRb1 = sqrt((_y1 - y_o)*(_y1 - y_o) + (_x1 - x_o) * (_x1 - x_o));
//        float tmpRb2 = sqrt((y_o - _y2) * (y_o - _y2) + (x_o - _x2) * (x_o - _x2));
//        // Average of temp rb
//        float rb = ( tmpRb1 + tmpRb2 ) / 2;
//        
//        centerPaths[i].rb = rb;
//        centerPaths[i].ra = 5.0;
//    }
//    
//    // start point ra rb;
//    
//    for (int i = 0; i < centerLength; i++) {
//        // print the center line coordinations
//        cout << "(" << centerPaths[i].x << "," << centerPaths[i].y << ")" << "- " << centerPaths[i].alpha << "--" << centerPaths[i].rb <<endl;
//    }
//    
//    
//    imshow("Thinning ", thinning);
//    
//    waitKey(0);
    
    return 0;

}




