//
//  EdgeScale.cpp
//  OpenCVTutorials
//
//  Created by heermaster on 16/1/18.
//  Copyright © 2016年 PeterLiu. All rights reserved.
//

#include "EdgeScale.hpp"

Mat getScaledImg(string src){
   
    Mat source = loadImageFile(src);
    source = processImage(source);
    
    Mat eroded;
    
    source.copyTo(eroded);
    
    // Erosion kernal
    int erosion_type = MORPH_RECT;
    int erosion_size = 1;
    
    Mat kernal = getStructuringElement(erosion_type, Size( 2*erosion_size+1, 2*erosion_size+1), Point(erosion_size, erosion_size));
    
    erode(eroded, eroded, kernal);
    
    return eroded;

}

// erosion operation
Mat erosionFunc(Mat original, int erosion_size, int erosion_type){
    if (original.empty()) {
        cout << "Erosion func: the original file is empty!" << endl;
    }
    Mat eroded ;
    original.copyTo(eroded);
    
    int _type ;
    // Erosion type
    if (erosion_type == 0) {
        _type = MORPH_RECT;
    } else if(erosion_type == 1){
        _type = MORPH_CROSS;
    } else if (erosion_type == 2){
        _type = MORPH_ELLIPSE;
    }
    
    // kernal
    Mat element = getStructuringElement(_type, Size( 2*erosion_size+1, 2*erosion_size+1),Point(erosion_size, erosion_size));
    
    erode(eroded, eroded, element);
    
    return eroded;
}