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
using namespace cv;
using namespace std;


const string source = "/Users/peterliu/Documents/openDevelopment/one.png";
const string edgedatafile = "/Users/peterliu/Documents/openDevelopment/edgeData.txt";
const string thinningdatafile = "/Users/peterliu/Documents/openDevelopment/thinningData.txt";

Mat imageprocess(string);

void demo();



#endif /* Demo_hpp */
