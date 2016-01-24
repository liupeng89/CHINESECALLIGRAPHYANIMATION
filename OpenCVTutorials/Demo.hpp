//
//  Demo.hpp
//  OpenCVTutorials
//
//  Created by PeterLiu on 1/13/16.
//  Copyright © 2016 PeterLiu. All rights reserved.
//

#ifndef Demo_hpp
#define Demo_hpp

#include <iostream>
#include <string>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "EdgeDetection.hpp"
#include "ThinningProcess.hpp"
#include "GraphicStructure.hpp"
#include "EnvmConfig.h"
using namespace cv;
using namespace std;

extern struct CAPoint *edgepoints;
extern struct CAPoint *tracepoints;

//int *imgVertex;

//extern int imgVertex[90000];
extern int *imgVertex;

const float DEG2RAD = 3.14159 / 180.0;

const int _delay = 5; //Delay 5ms

Mat imageprocess(string);

void init();

int *getImgColorVert();

CAPoint *getEdgePoints();
CAPoint *getTracePoints();

void getEdge();
void getTrace();

void demo();

bool raycasting(GLfloat,GLfloat,CAPoint[] , int);

void draw();

void drawEllipse(GLfloat,GLfloat,GLfloat,GLfloat);

void drawRect(GLfloat, GLfloat);

void Timer(int);

void demo(int, char**); // The opengl function: the graphic drawing;



#endif /* Demo_hpp */
