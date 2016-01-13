//
//  EdgeDetection.hpp
//  OpenCVTutorials
//
//  Created by PeterLiu on 1/11/16.
//  Copyright © 2016 PeterLiu. All rights reserved.
//

#ifndef EdgeDetection_hpp
#define EdgeDetection_hpp

#include <iostream>
#include <string>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;
using namespace std;

const string edgeDataFilePath = "/Users/peterliu/Documents/openDevelopment/edgeData.txt";

//void edgeDetection(Mat); // Edge detection

Mat edgeDetection(Mat);

void saveEdgeData(Mat);

void saveEdgeDataToFile(Mat);
void saveEdgeDataToFile(Mat, string);

#endif /* EdgeDetection_hpp */
