//
//  ThinningProcess.hpp
//  OpenCVTutorials
//  Algorithm: Zhang-Suen algorithm
//  Created by PeterLiu on 11/3/15.
//  Copyright © 2015 PeterLiu. All rights reserved.
//

#ifndef ThinningProcess_hpp
#define ThinningProcess_hpp


#include <stdio.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;

void thinningIteration(cv::Mat& img, int iter);
void thinningImage(const cv::Mat& src, cv::Mat& dst);


#endif /* ThinningProcess_hpp */
