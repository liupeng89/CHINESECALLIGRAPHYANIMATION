//
//  MlddleLineProcess.hpp
//  OpenCVTutorials
//
//  Created by PeterLiu on 11/8/15.
//  Copyright © 2015 PeterLiu. All rights reserved.
//

#ifndef MlddleLineProcess_hpp
#define MlddleLineProcess_hpp

#include <stdio.h>
#include <GLUT/GLUT.h>

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;
using namespace std;

struct MiddleLineElement
{
    GLfloat x,y;
    GLfloat ra,rb;
};

MiddleLineElement* getMiddleLine();
void middleLine();


#endif /* MlddleLineProcess_hpp */
