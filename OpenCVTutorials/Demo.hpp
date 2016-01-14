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
using namespace cv;
using namespace std;


const string source = "/Users/peterliu/Documents/openDevelopment/one.png";
const string edgedatafile = "/Users/peterliu/Documents/openDevelopment/edgeData.txt";
const string thinningdatafile = "/Users/peterliu/Documents/openDevelopment/thinningData.txt";

const float DEG2RAD = 3.14159 / 180.0;





const int _delay = 500; //Delay 5ms


Mat imageprocess(string);

void init();

void demo();

bool raycasting(GLfloat,GLfloat,CAPoint[] , int);

void draw();

void drawEllipse(GLfloat,GLfloat,GLfloat,GLfloat);

void Timer(int);

void demo(int, char**); // The opengl function: the graphic drawing;



#endif /* Demo_hpp */
