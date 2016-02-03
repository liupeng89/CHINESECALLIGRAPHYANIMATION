//
//  MainProcess.hpp
//  OpenCVTutorials
//
//  Created by PeterLiu on 1/19/16.
//  Copyright © 2016 PeterLiu. All rights reserved.
//

#ifndef MainProcess_hpp
#define MainProcess_hpp

#include <iostream>

#include "ImageProcess.hpp"
#include "ThinningProcess.hpp"
#include "EdgeDetection.hpp"
#include "InPolygon.hpp"
#include "EnvmConfig.h"
#include "FitCurve.hpp"
#include <GLUT/GLUT.h>

using namespace cv;
using namespace std;

const int _delay = 50;

const float DEG2RAD = 3.14159 / 180.0;


void process(int, char**); // The opengl function: the graphic drawing;

int getSkeletonLength(String);

Point2 *getSkeletonPoints(String);

void draw();

void drawEllipse(GLfloat,GLfloat,GLfloat,GLfloat);

void drawRect(GLfloat, GLfloat);

void Timer(int);

#endif /* MainProcess_hpp */
