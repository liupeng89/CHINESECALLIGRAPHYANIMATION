//
//  main.cpp
//  OpenCVTutorials
//
//  Created by PeterLiu on 10/12/15.
//  Copyright © 2015 PeterLiu. All rights reserved.
//
#include <string>
#include <time.h>
#include <iostream>
//#include "ImgProcess.hpp"
//#include "FitCurve.hpp"
//#include "ThinningProcess.hpp"
//#include <GLUT/GLUT.h>
//#include <math.h>
//#include "MlddleLineProcess.hpp"
//#include "ImageProcess.hpp"
//#include "EdgeDetection.hpp"
#include "Demo.hpp"
using namespace std;

//const int WindowWidth = 300;
//const int WindowHeight = 300;
//
//const String pathSrc = "/Users/peterliu/Documents/openDevelopment/path.txt";
////const String pathSrc = "/Users/heermaster/Documents/openDevelopment/path.txt";
//
//
//int discount = 0;
//const int pathLen = 260;
//
//const int delay = 5; // Delay ms
//
//typedef float GLfloat;
//typedef int GLint;
//
//#define sizeofa(array) sizeof array / sizeof array[0]
//
//GLfloat gfPosX = 0.25;
//GLfloat gfDeltaX = 0.005;
//GLfloat fontSizeDelta = 0.001;
//GLfloat fontSize = 0.00;
//const float DEG2RAD = 3.14159 / 180.0;
//
//// Paths array
//struct CenterLineElement paths[241];
//CenterLineElement *centerPath;
//
//void imageProcess(); // The opencv function: the image process;
//
//void animation(int, char**); // The opengl function: the graphic drawing;
//
//void DrawCircle(float cx, float cy, float r, int num_segments);
//void DrawEllipse(CenterLineElement element);
//void DrawEllipse();
//void Timer(int iUnused);
//void Initialize();
//
//void drawEllipse(float dx, float dy, float xradius, float yradius);
//void drawEllipse(float dx, float dy, float xradius, float yradius, float alpha);
//void initPath();
//
//
//
///*
//    Draw the ellipse object.
// */
//void Draw() {
//    
//    if (discount == pathLen) {
//        return;
//    }
//
//    glColor3f(0.0, 0.0, 0.0);
//    glBegin(GL_TRIANGLE_FAN);
//    
////    drawEllipse(paths[discount].x, paths[discount].y, paths[discount].ra, paths[discount].rb, paths[discount].alpha);
//    drawEllipse(paths[discount].x, paths[discount].y, paths[discount].ra, paths[discount].rb);
//    if (discount < pathLen) {
//        discount++;
//    }
//    
//    cout << discount << endl;
//    cout << paths[discount].x << ":" << paths[discount].y << ":" << paths[discount].ra << ":" << paths[discount].rb << ":" << paths[discount].alpha << endl;
//    
//    //Test for drawing the general ellipse
////    drawEllipse(0.25, 0.3, 0.005, 0.02, 0.4);
////    drawEllipse(0.45, 0.3, 0.005, 0.02);
//    
//    glEnd();
//    glFlush();
//}
//
///* Draw the ellipse */
//void drawEllipse(float dx, float dy, float xradius, float yradius)
//{
//    for (float i = 0.0; i < 360.0; i+=0.1) {
//        float degInRad = i * DEG2RAD;
//        float _x = cos(degInRad)*xradius + dx;
//        float _y = sin(degInRad)*yradius + dy;
//        // The contraited conditions
//        
//        glVertex2f(_x, _y);
//    }
//    
//}
///*Draw the general ellipse*/
//// Ellipse rotation
//// alphe = a * pai / 180
//void drawEllipse(float dx, float dy, float xradius, float yradius, float alpha)
//{
//    for (float i = 0.0; i < 360.0; i+=0.1) {
//        float degInRad = i * DEG2RAD;
//        float orignx = cos(degInRad)*xradius + dx;
//        float origny = sin(degInRad)*yradius + dy;
//        /*
//            rotation formula 
//            x' = x * cos(a) - y * sin(a)
//            y' = x * sin(a) + y * cos(a)
//         */
//        float x = orignx * cos(alpha) - origny * sin(alpha);
//        float y = orignx * sin(alpha) + origny * cos(alpha);
//        
//        glVertex2f(x, y); // Ellipse rotation
//    }
//}
//
///* Init the paths array */
//void initPath()
//{
//    
//    int index = 0;
//    /* Method one: */
//    // Load path information.
//    
//    // Load image
//    middleLine();
//    
//    FILE *fr = fopen(pathSrc.c_str(), "r");
//    
//    float pointx, pointy, ra, rb, alpha;
//    // Path information convertion
//    while (fscanf(fr, "%f %f %f %f %f", &pointx, &pointy, &ra, &rb, &alpha) == 5) {
//        cout << pointx << ":" << pointy << ":"  << ra << ":"  << rb << endl;
//        paths[index].x = pointx / WindowWidth;
//        paths[index].y = 1 - pointy / WindowHeight;
//        
//        paths[index].ra = ra / 1000.0;
//        paths[index].rb = rb / 300.0;
//        paths[index].alpha = alpha;
//        index++;
//    }
////
//    /* Method two: */
////    CenterLineElement *centerPathLine = initCenterPath();
////    index = 0;
////    CenterLineElement tmp = *(centerPathLine + index);
////    while (tmp.x >=0 && tmp.x < 300 && tmp.y >=0 && tmp.y < 300) {
////        //
////        paths[index].x = tmp.x / 300.0;
////        paths[index].y = 1 - tmp.y / 300.0;
////        
////        paths[index].ra = tmp.ra / 300.0;
////        paths[index].rb = tmp.rb / 300.0;
////        paths[index].alpha = tmp.alpha;
////        index++;
////        tmp = *(centerPathLine + index);
////    }
//}
//
//
//
///*Timer function*/
//void Timer(int iUnused)
//{
//    glutPostRedisplay();
//    glutTimerFunc(delay, Timer, 0);
//
//}
//
///* Initialize */
//void Initialize() {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
//   
//    // Init the paths
//    initPath();
//    
//}
//
// The image process function
//void imageProcess()
//{
//    Mat source, gray, edge;
//    source = loadImageFile(sourceImagePath);
//    gray = processImage(source);
//    edge = edgeDetection(gray);
//    
//    imshow("source", source);
//    imshow("gray", gray);
//    imshow("edge", edge);
//    
////    saveEdgeData(edge);
//    saveEdgeDataToFile(edge);
//    
////    waitKey(0);
//    source.release();
//    gray.release();
//    edge.release();
//}

////The animation function
//void animation(int argc, char** argv)
//{
//    /* OpenGl Setting */
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(WindowWidth, WindowHeight);
//    glutInitWindowPosition(200, 200);
//    glutCreateWindow("Chinese Animation");
//    Initialize();
//    glutDisplayFunc(Draw);
//    Timer(0);
//    glutMainLoop();
//
//}

/*
    THIS IS A CHINESE CALLIGRAPHY ANIMATION PROJECT.
*/
int main(int argc, char** argv) {
    
    /* The OpenCV function */
    // 1. Edge detection to get the edge data;
    // 2. The stroke model;
    // 3. The trace of stroke;
//    clock_t t1, t2;
//    t1 = clock();
////    imageProcess();
////    middleLine();
//
//    string image = "/Users/peterliu/Documents/openDevelopment/trace.png";
//    Mat src = imread(image);
//    cvtColor(src, src, CV_BGR2GRAY, 1);
//    cout << "the channel:" << src.channels() << endl;
//    
//    imshow("Src", src);
//    // Change black to white
//    bitwise_not(src, src);
//
//    
//    Mat thinning ;
//    thinningImage(src, thinning);
//    bitwise_not(thinning, thinning);
//    imshow("Thinning ", thinning);
//    waitKey(0);
//    
//    t2 = clock();
//    
//    float diff = (float) (t2 - t1) / CLOCKS_PER_SEC * 1000;
//    cout << "Running time:" << diff << "ms" << endl;
    
    /* The OpenGl function */
//    animation(argc, argv);
    
    demo(argc, argv);
    
    return 0;

}




