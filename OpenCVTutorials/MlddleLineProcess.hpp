//
//  MlddleLineProcess.hpp
//  OpenCVTutorials
//
//  Created by PeterLiu on 11/8/15.
//  Copyright © 2015 PeterLiu. All rights reserved.
//

#ifndef MlddleLineProcess_hpp
#define MlddleLineProcess_hpp

#include <string>
#include <stdio.h>
#include <GLUT/GLUT.h>

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "ThinningProcess.hpp"
using namespace cv;
using namespace std;

const float ellipseRA = 5.0;

const String imageSrc = "/Users/peterliu/Documents/openDevelopment/one.jpg";
const String pathTxt = "/Users/peterliu/Documents/openDevelopment/path.txt";

//const String imageSrc = "/Users/heermaster/Documents/openDevelopment/one.jpg";
//const String pathTxt = "/Users/heermaster/Documents/openDevelopment/path.txt";

struct CenterLineElement
{
    GLfloat x,y;
    GLfloat ra,rb;
    GLfloat alpha;
};

CenterLineElement* getMiddleLine();
void middleLine();

Mat loadImageFile(String);
Mat preprocessImage(Mat);
CenterLineElement* initCenterPath();



#endif /* MlddleLineProcess_hpp */
