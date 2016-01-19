//
//  EdgeScale.hpp
//  OpenCVTutorials
//
//  Created by heermaster on 16/1/18.
//  Copyright © 2016年 PeterLiu. All rights reserved.
//

#ifndef EdgeScale_hpp
#define EdgeScale_hpp

#include <stdio.h>
#include "GraphicStructure.cpp"
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "ImageProcess.hpp"
using namespace cv;
using namespace std;

// Erosion operation
Mat getScaledImg(string);

Mat erosionFunc(Mat, int, int);

//Point *getScaleEdgePoints(Mat);

#endif /* EdgeScale_hpp */
