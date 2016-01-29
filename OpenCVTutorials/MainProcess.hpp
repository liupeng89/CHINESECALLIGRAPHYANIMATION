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


using namespace cv;
using namespace std;

void process(int, char**); // The opengl function: the graphic drawing;

#endif /* MainProcess_hpp */
