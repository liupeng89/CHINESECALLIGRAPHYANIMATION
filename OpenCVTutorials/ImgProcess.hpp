//
//  ImgProcess.hpp
//  OpenCVTutorials
//
//  Created by PeterLiu on 10/26/15.
//  Copyright © 2015 PeterLiu. All rights reserved.
//

#ifndef ImgProcess_hpp
#define ImgProcess_hpp


#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <opencv2/features2d/features2d.hpp>

#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
using namespace std;

const int MAX_KERNAL_LENGTH = 30;

const int AMOUT = 9;

const int GASSIONKERNALX = 31;
const int GASSIONTHRESHOLD = 1.0;

const int GRAYTHRESHOLD = 100;

const int dilation_type = 0;
const int dilation_size = 2;

const int erosion_type = 0;
const int erosion_size = 3;

// 锐化算法
void Sharpen(const Mat& myImage, Mat& Result);

// 高低差值保留算法
Mat HighLowConstrastSave(Mat& source);

void process101();
void process102();
void process103();
void process104();
void process105();
void process106();
void process107();
void process108();
void process109();
void process110();
void process111();
void process112();
void process113();
void process114();
void process115();
void process116();
void process117();
void process118();
void process119();
void process120();
void process121();
void process122();
void process123();
void process124();
void process125();
void process126();
void process127();
void process128();
void process129();
void process130();
void process131();
void process132();
void process133();
void process134();
void process135();
void process136();





#endif /* ImgProcess_hpp */
