//
//  ImgProcess.cpp
//  OpenCVTutorials
//
//  Created by PeterLiu on 10/26/15.
//  Copyright © 2015 PeterLiu. All rights reserved.
//

#include "ImgProcess.hpp"


// Images process functions

void process101(){
    
    int converthreshold = 128;
    
    //Read source file
    Mat src = imread("/Users/peterliu/Documents/openDevelopment/SF-Image/101.jpg");
    
    if(src.empty()){
        cout << "no image files" << endl;
    }
    imshow("source", src);
    Mat gray, gray_ga, edge;
    
    // Gray without gaussian filter
    cvtColor(src, gray, CV_BGR2GRAY);
    threshold(gray, gray, converthreshold, 255, CV_THRESH_BINARY);
    bitwise_not(gray, gray);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/101-gray.jpg", gray);
    imshow("Gray", gray);
    
    
    // Gray with gaussian filter
    src.copyTo(gray_ga);
    //    for(int i = 1; i <MAX_KERNAL_LENGTH; i += 2){
    //        GaussianBlur(gray_ga, gray_ga, Size(i,i), GASSIONTHRESHOLD);
    //    }
    GaussianBlur(gray_ga, gray_ga, Size(GASSIONKERNALX,GASSIONKERNALX), GASSIONTHRESHOLD);
    //    GaussianBlur(gray_ga, gray_ga, Size(GASSIONKERNALX,GASSIONKERNALX), GASSIONTHRESHOLD);
    
    cvtColor(gray_ga, gray_ga, CV_BGR2GRAY);
    threshold(gray_ga, gray_ga, converthreshold, 255, CV_THRESH_BINARY);
    bitwise_not(gray_ga, gray_ga);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/101-gray-ga.jpg", gray_ga);
    imshow("Gray_ga", gray_ga);
    
    Canny(gray_ga, edge, 3, 3);
    imshow("Edge", edge);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/101-gray-border.jpg", edge);
    
    
    waitKey(0);
}

// 102 jgp
void process102(){
    
    int converthreshold = 100;
    
    //Read source file
    Mat src = imread("/Users/peterliu/Documents/openDevelopment/SF-Image/102.png");
    
    if(src.empty()){
        cout << "no image files" << endl;
    }
    // Red color ,
    
    imshow("source", src);
    Mat gray, gray_ga, edge;
    
    // Gray without gaussian filter
    cvtColor(src, gray, CV_BGR2GRAY);
    imshow("g", gray);
    threshold(gray, gray, converthreshold, 255, CV_THRESH_BINARY);
//    bitwise_not(gray, gray);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/102-gray.png", gray);
    imshow("Gray", gray);
    
    
    // Gray with gaussian filter
    src.copyTo(gray_ga);
    //    for(int i = 1; i <MAX_KERNAL_LENGTH; i += 2){
    //        GaussianBlur(gray_ga, gray_ga, Size(i,i), GASSIONTHRESHOLD);
    //    }
    GaussianBlur(gray_ga, gray_ga, Size(GASSIONKERNALX,GASSIONKERNALX), GASSIONTHRESHOLD);
    //    GaussianBlur(gray_ga, gray_ga, Size(GASSIONKERNALX,GASSIONKERNALX), GASSIONTHRESHOLD);
    
    cvtColor(gray_ga, gray_ga, CV_BGR2GRAY);
    threshold(gray_ga, gray_ga, converthreshold, 255, CV_THRESH_BINARY);
//    bitwise_not(gray_ga, gray_ga);
    
    
    imshow("Gray_ga", gray_ga);
    //    // Dilation
    //
    Mat dilation_element = getStructuringElement(dilation_type, Size(2*dilation_size + 1, 2*dilation_size + 1));
    dilate(gray_ga, gray_ga, dilation_element);
    
    imshow("gray_dilate", gray_ga);
    //    imwrite("/Users/peterliu/Documents/openDevelopment/gray_dilate.bmp", gray);
    //
    //
    //    //Erosion
    //
    Mat erosion_element = getStructuringElement(erosion_type, Size(2*erosion_size + 1, 2*erosion_size + 1));
    erode(gray_ga, gray_ga, erosion_element);
    
    imshow("gray_erosion", gray_ga);
    //    imwrite("/Users/peterliu/Documents/openDevelopment/gray_erosion.bmp", gray);
    
    
    
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/102-gray-ga.png", gray_ga);
    
    Canny(gray_ga, edge, 3, 3);
    imshow("Edge", edge);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/102-gray-border.png", edge);
    
    waitKey(0);
}
void process103(){
    
    int converthreshold = 128;
    
    //Read source file
    Mat src = imread("/Users/peterliu/Documents/openDevelopment/SF-Image/103.jpg");
    
    if(src.empty()){
        cout << "no image files" << endl;
    }
    imshow("source", src);
    Mat gray, gray_ga, edge;
    
    // Gray without gaussian filter
    cvtColor(src, gray, CV_BGR2GRAY);
    threshold(gray, gray, converthreshold, 255, CV_THRESH_BINARY);
//    bitwise_not(gray, gray);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/103-gray.jpg", gray);
    imshow("Gray", gray);
    
    
    // Gray with gaussian filter
    src.copyTo(gray_ga);
    //    for(int i = 1; i <MAX_KERNAL_LENGTH; i += 2){
    //        GaussianBlur(gray_ga, gray_ga, Size(i,i), GASSIONTHRESHOLD);
    //    }
    GaussianBlur(gray_ga, gray_ga, Size(GASSIONKERNALX,GASSIONKERNALX), GASSIONTHRESHOLD);
    //    GaussianBlur(gray_ga, gray_ga, Size(GASSIONKERNALX,GASSIONKERNALX), GASSIONTHRESHOLD);
    
    cvtColor(gray_ga, gray_ga, CV_BGR2GRAY);
    threshold(gray_ga, gray_ga, converthreshold, 255, CV_THRESH_BINARY);
//    bitwise_not(gray_ga, gray_ga);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/103-gray-ga.jpg", gray_ga);
    imshow("Gray_ga", gray_ga);
    
    Canny(gray_ga, edge, 3, 3);
    imshow("Edge", edge);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/103-gray-border.jpg", edge);
    waitKey(0);
}

// 104 process
void process104(){
    int converthreshold = 110;
    
    //Read source file
    Mat src = imread("/Users/peterliu/Documents/openDevelopment/SF-Image/104.jpg");
    
    if(src.empty()){
        cout << "no image files" << endl;
    }
    imshow("source", src);
    Mat gray, gray_ga, edge;
    
    // Gray without gaussian filter
    cvtColor(src, gray, CV_BGR2GRAY);
    threshold(gray, gray, converthreshold, 255, CV_THRESH_BINARY);
    bitwise_not(gray, gray);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/104-gray.jpg", gray);
    imshow("Gray", gray);
    
    
    // Gray with gaussian filter
    src.copyTo(gray_ga);
    //    for(int i = 1; i <MAX_KERNAL_LENGTH; i += 2){
    //        GaussianBlur(gray_ga, gray_ga, Size(i,i), GASSIONTHRESHOLD);
    //    }
    GaussianBlur(gray_ga, gray_ga, Size(GASSIONKERNALX,GASSIONKERNALX), GASSIONTHRESHOLD);
    //    GaussianBlur(gray_ga, gray_ga, Size(GASSIONKERNALX,GASSIONKERNALX), GASSIONTHRESHOLD);
    
    cvtColor(gray_ga, gray_ga, CV_BGR2GRAY);
    threshold(gray_ga, gray_ga, converthreshold, 255, CV_THRESH_BINARY);
    bitwise_not(gray_ga, gray_ga);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/104-gray-ga.jpg", gray_ga);
    imshow("Gray_ga", gray_ga);
    
    Canny(gray_ga, edge, 3, 3);
    imshow("Edge", edge);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/104-gray-border.jpg", edge);
    waitKey(0);
}
void process105(){
    waitKey(0);
}

// 106 process
void process106(){
    int converthreshold = 64;
    
    //Read source file
    Mat src = imread("/Users/peterliu/Documents/openDevelopment/SF-Image/106.jpg");
    
    if(src.empty()){
        cout << "no image files" << endl;
    }
    imshow("source", src);
    Mat gray, gray_ga, edge;
    
    // Gray without gaussian filter
    cvtColor(src, gray, CV_BGR2GRAY);
    threshold(gray, gray, converthreshold, 255, CV_THRESH_BINARY);
    bitwise_not(gray, gray);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/106-gray.jpg", gray);
    imshow("Gray", gray);
    
    
    // Gray with gaussian filter
    src.copyTo(gray_ga);
    //    for(int i = 1; i <MAX_KERNAL_LENGTH; i += 2){
    //        GaussianBlur(gray_ga, gray_ga, Size(i,i), GASSIONTHRESHOLD);
    //    }
    GaussianBlur(gray_ga, gray_ga, Size(GASSIONKERNALX,GASSIONKERNALX), GASSIONTHRESHOLD);
    //    GaussianBlur(gray_ga, gray_ga, Size(GASSIONKERNALX,GASSIONKERNALX), GASSIONTHRESHOLD);
    
    cvtColor(gray_ga, gray_ga, CV_BGR2GRAY);
    threshold(gray_ga, gray_ga, converthreshold, 255, CV_THRESH_BINARY);
    bitwise_not(gray_ga, gray_ga);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/106-gray-ga.jpg", gray_ga);
    imshow("Gray_ga", gray_ga);
    
    Canny(gray_ga, edge, 3, 3);
    imshow("Edge", edge);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/106-gray-border.jpg", edge);
    waitKey(0);
}
void process107(){
    waitKey(0);
}

// 108 processed!
void process108(){
    int converthreshold = 180;
    
    //Read source file
    Mat src = imread("/Users/peterliu/Documents/openDevelopment/SF-Image/108.png");
    
    if(src.empty()){
        cout << "no image files" << endl;
    }
    imshow("source", src);
    
    // Remove the yellow and bule lines
    for (int y = 0; y < src.cols; y++) {
        for (int x = 0; x < src.rows; x++) {
            //
        }
    }
    
    Mat gray, gray_ga, edge;
    
    // Gray without gaussian filter
    cvtColor(src, gray, CV_BGR2GRAY);
    threshold(gray, gray, converthreshold, 255, CV_THRESH_BINARY);
    imshow("g", gray);
    bitwise_not(gray, gray);
    
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/108-gray.png", gray);
    imshow("Gray", gray);
    
    
    // Gray with gaussian filter
    src.copyTo(gray_ga);
    //    for(int i = 1; i <MAX_KERNAL_LENGTH; i += 2){
    //        GaussianBlur(gray_ga, gray_ga, Size(i,i), GASSIONTHRESHOLD);
    //    }
    GaussianBlur(gray_ga, gray_ga, Size(GASSIONKERNALX,GASSIONKERNALX), GASSIONTHRESHOLD);
    //    GaussianBlur(gray_ga, gray_ga, Size(GASSIONKERNALX,GASSIONKERNALX), GASSIONTHRESHOLD);
    
    cvtColor(gray_ga, gray_ga, CV_BGR2GRAY);
    threshold(gray_ga, gray_ga, converthreshold, 255, CV_THRESH_BINARY);
    bitwise_not(gray_ga, gray_ga);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/108-gray-ga.png", gray_ga);
    imshow("Gray_ga", gray_ga);
    
    Canny(gray_ga, edge, 3, 3);
    imshow("Edge", edge);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/108-gray-border.png", edge);
    waitKey(0);
}

// 109 processed!
void process109(){
    int converthreshold = 80;
    
    //Read source file
    Mat src = imread("/Users/peterliu/Documents/openDevelopment/SF-Image/109.jpg");
    
    if(src.empty()){
        cout << "no image files" << endl;
    }
    imshow("source", src);
    Mat gray, gray_ga, edge;
    
    // Gray without gaussian filter
    cvtColor(src, gray, CV_BGR2GRAY);
    threshold(gray, gray, converthreshold, 255, CV_THRESH_BINARY);
//    bitwise_not(gray, gray);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/109-gray.jpg", gray);
    imshow("Gray", gray);
    
    
    // Gray with gaussian filter
    src.copyTo(gray_ga);
    //    for(int i = 1; i <MAX_KERNAL_LENGTH; i += 2){
    //        GaussianBlur(gray_ga, gray_ga, Size(i,i), GASSIONTHRESHOLD);
    //    }
    GaussianBlur(gray_ga, gray_ga, Size(GASSIONKERNALX,GASSIONKERNALX), GASSIONTHRESHOLD);
    //    GaussianBlur(gray_ga, gray_ga, Size(GASSIONKERNALX,GASSIONKERNALX), GASSIONTHRESHOLD);
    
    cvtColor(gray_ga, gray_ga, CV_BGR2GRAY);
    threshold(gray_ga, gray_ga, converthreshold, 255, CV_THRESH_BINARY);
//    bitwise_not(gray_ga, gray_ga);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/109-gray-ga.jpg", gray_ga);
    imshow("Gray_ga", gray_ga);
    
    Canny(gray_ga, edge, 3, 3);
    imshow("Edge", edge);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/109-gray-border.jpg", edge);
    waitKey(0);
}

// 110 processed
void process110(){
    int converthreshold = 80;
    
    //Read source file
    Mat src = imread("/Users/peterliu/Documents/openDevelopment/SF-Image/110.jpg");
    
    if(src.empty()){
        cout << "no image files" << endl;
    }
    imshow("source", src);
    Mat gray, gray_ga, edge;
    
    // Gray without gaussian filter
    cvtColor(src, gray, CV_BGR2GRAY);
    threshold(gray, gray, converthreshold, 255, CV_THRESH_BINARY);
//    bitwise_not(gray, gray);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/110-gray.jpg", gray);
    imshow("Gray", gray);
    
    
    // Gray with gaussian filter
    src.copyTo(gray_ga);
    //    for(int i = 1; i <MAX_KERNAL_LENGTH; i += 2){
    //        GaussianBlur(gray_ga, gray_ga, Size(i,i), GASSIONTHRESHOLD);
    //    }
    GaussianBlur(gray_ga, gray_ga, Size(GASSIONKERNALX,GASSIONKERNALX), GASSIONTHRESHOLD);
    //    GaussianBlur(gray_ga, gray_ga, Size(GASSIONKERNALX,GASSIONKERNALX), GASSIONTHRESHOLD);
    
    cvtColor(gray_ga, gray_ga, CV_BGR2GRAY);
    threshold(gray_ga, gray_ga, converthreshold, 255, CV_THRESH_BINARY);
//    bitwise_not(gray_ga, gray_ga);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/110-gray-ga.jpg", gray_ga);
    imshow("Gray_ga", gray_ga);
    
    Canny(gray_ga, edge, 3, 3);
    imshow("Edge", edge);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/110-gray-border.jpg", edge);
    waitKey(0);
}

// 111 processed!
void process111(){
    int converthreshold = 128;
    
    //Read source file
    Mat src = imread("/Users/peterliu/Documents/openDevelopment/SF-Image/111.jpg");
    
    if(src.empty()){
        cout << "no image files" << endl;
    }
    imshow("source", src);
    Mat gray, gray_ga, edge;
    
    // Gray without gaussian filter
    cvtColor(src, gray, CV_BGR2GRAY);
    threshold(gray, gray, converthreshold, 255, CV_THRESH_BINARY);
    //    bitwise_not(gray, gray);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/111-gray.jpg", gray);
    imshow("Gray", gray);
    
    
    // Gray with gaussian filter
    src.copyTo(gray_ga);
    //    for(int i = 1; i <MAX_KERNAL_LENGTH; i += 2){
    //        GaussianBlur(gray_ga, gray_ga, Size(i,i), GASSIONTHRESHOLD);
    //    }
    GaussianBlur(gray_ga, gray_ga, Size(GASSIONKERNALX,GASSIONKERNALX), GASSIONTHRESHOLD);
    //    GaussianBlur(gray_ga, gray_ga, Size(GASSIONKERNALX,GASSIONKERNALX), GASSIONTHRESHOLD);
    
    cvtColor(gray_ga, gray_ga, CV_BGR2GRAY);
    threshold(gray_ga, gray_ga, converthreshold, 255, CV_THRESH_BINARY);
    //    bitwise_not(gray_ga, gray_ga);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/111-gray-ga.jpg", gray_ga);
    imshow("Gray_ga", gray_ga);
    
    Canny(gray_ga, edge, 3, 3);
    imshow("Edge", edge);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/111-gray-border.jpg", edge);
    waitKey(0);
}

// 112 processed!
void process112(){
    int converthreshold = 128;
    
    //Read source file
    Mat src = imread("/Users/peterliu/Documents/openDevelopment/SF-Image/112.jpg");
    
    if(src.empty()){
        cout << "no image files" << endl;
    }
    imshow("source", src);
    Mat gray, gray_ga, edge;
    
    // Gray without gaussian filter
    cvtColor(src, gray, CV_BGR2GRAY);
    threshold(gray, gray, converthreshold, 255, CV_THRESH_BINARY);
    bitwise_not(gray, gray);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/112-gray.jpg", gray);
    imshow("Gray", gray);
    
    
    // Gray with gaussian filter
    src.copyTo(gray_ga);
    //    for(int i = 1; i <MAX_KERNAL_LENGTH; i += 2){
    //        GaussianBlur(gray_ga, gray_ga, Size(i,i), GASSIONTHRESHOLD);
    //    }
    GaussianBlur(gray_ga, gray_ga, Size(GASSIONKERNALX,GASSIONKERNALX), GASSIONTHRESHOLD);
    //    GaussianBlur(gray_ga, gray_ga, Size(GASSIONKERNALX,GASSIONKERNALX), GASSIONTHRESHOLD);
    
    cvtColor(gray_ga, gray_ga, CV_BGR2GRAY);
    threshold(gray_ga, gray_ga, converthreshold, 255, CV_THRESH_BINARY);
    bitwise_not(gray_ga, gray_ga);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/112-gray-ga.jpg", gray_ga);
    imshow("Gray_ga", gray_ga);
    
    Canny(gray_ga, edge, 3, 3);
    imshow("Edge", edge);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/112-gray-border.jpg", edge);
    waitKey(0);
}

// 113 processed!
void process113(){
    int converthreshold = 200;
    
    //Read source file
    Mat src = imread("/Users/peterliu/Documents/openDevelopment/SF-Image/113.jpg");
    
    if(src.empty()){
        cout << "no image files" << endl;
    }
    imshow("source", src);
    Mat gray, gray_ga, edge;
    
    // Gray without gaussian filter
    cvtColor(src, gray, CV_BGR2GRAY);
    threshold(gray, gray, converthreshold, 255, CV_THRESH_BINARY);
    //    bitwise_not(gray, gray);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/113-gray.jpg", gray);
    imshow("Gray", gray);
    
    
    // Gray with gaussian filter
    src.copyTo(gray_ga);
    //    for(int i = 1; i <MAX_KERNAL_LENGTH; i += 2){
    //        GaussianBlur(gray_ga, gray_ga, Size(i,i), GASSIONTHRESHOLD);
    //    }
    GaussianBlur(gray_ga, gray_ga, Size(GASSIONKERNALX,GASSIONKERNALX), GASSIONTHRESHOLD);
    //    GaussianBlur(gray_ga, gray_ga, Size(GASSIONKERNALX,GASSIONKERNALX), GASSIONTHRESHOLD);
    
    cvtColor(gray_ga, gray_ga, CV_BGR2GRAY);
    threshold(gray_ga, gray_ga, converthreshold, 255, CV_THRESH_BINARY);
    //    bitwise_not(gray_ga, gray_ga);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/113-gray-ga.jpg", gray_ga);
    imshow("Gray_ga", gray_ga);
    
    Canny(gray_ga, edge, 3, 3);
    imshow("Edge", edge);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/113-gray-border.jpg", edge);
    waitKey(0);
}

//114 processed
void process114(){
    int converthreshold = 200;
    
    //Read source file
    Mat src = imread("/Users/peterliu/Documents/openDevelopment/SF-Image/114.jpg");
    
    if(src.empty()){
        cout << "no image files" << endl;
    }
    imshow("source", src);
    Mat gray, gray_ga, edge;
    
    // Gray without gaussian filter
    cvtColor(src, gray, CV_BGR2GRAY);
    threshold(gray, gray, converthreshold, 255, CV_THRESH_BINARY);
    //    bitwise_not(gray, gray);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/114-gray.jpg", gray);
    imshow("Gray", gray);
    
    
    // Gray with gaussian filter
    src.copyTo(gray_ga);
    //    for(int i = 1; i <MAX_KERNAL_LENGTH; i += 2){
    //        GaussianBlur(gray_ga, gray_ga, Size(i,i), GASSIONTHRESHOLD);
    //    }
    GaussianBlur(gray_ga, gray_ga, Size(GASSIONKERNALX,GASSIONKERNALX), GASSIONTHRESHOLD);
    //    GaussianBlur(gray_ga, gray_ga, Size(GASSIONKERNALX,GASSIONKERNALX), GASSIONTHRESHOLD);
    
    cvtColor(gray_ga, gray_ga, CV_BGR2GRAY);
    threshold(gray_ga, gray_ga, converthreshold, 255, CV_THRESH_BINARY);
    //    bitwise_not(gray_ga, gray_ga);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/114-gray-ga.jpg", gray_ga);
    imshow("Gray_ga", gray_ga);
    
    Canny(gray_ga, edge, 3, 3);
    imshow("Edge", edge);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/114-gray-border.jpg", edge);
    waitKey(0);
}

// 115 processed
void process115(){
    int converthreshold = 150;
    
    //Read source file
    Mat src = imread("/Users/peterliu/Documents/openDevelopment/SF-Image/115.jpg");
    
    if(src.empty()){
        cout << "no image files" << endl;
    }
    imshow("source", src);
    Mat gray, gray_ga, edge;
    
    // Gray without gaussian filter
    cvtColor(src, gray, CV_BGR2GRAY);
    threshold(gray, gray, converthreshold, 255, CV_THRESH_BINARY);
    //    bitwise_not(gray, gray);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/115-gray.jpg", gray);
    imshow("Gray", gray);
    
    
    // Gray with gaussian filter
    src.copyTo(gray_ga);
    //    for(int i = 1; i <MAX_KERNAL_LENGTH; i += 2){
    //        GaussianBlur(gray_ga, gray_ga, Size(i,i), GASSIONTHRESHOLD);
    //    }
    
    //    GaussianBlur(gray_ga, gray_ga, Size(GASSIONKERNALX,GASSIONKERNALX), GASSIONTHRESHOLD);
    
    cvtColor(gray_ga, gray_ga, CV_BGR2GRAY);
    GaussianBlur(gray_ga, gray_ga, Size(GASSIONKERNALX,GASSIONKERNALX), GASSIONTHRESHOLD);
    threshold(gray_ga, gray_ga, converthreshold, 255, CV_THRESH_BINARY);
    
    
    //    bitwise_not(gray_ga, gray_ga);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/115-gray-ga.jpg", gray_ga);
    imshow("Gray_ga", gray_ga);
    
    Canny(gray_ga, edge, 3, 3);
    imshow("Edge", edge);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/115-gray-border.jpg", edge);
    waitKey(0);
}

// 116 processed
void process116(){
    int converthreshold = 140;
    
    //Read source file
    Mat src = imread("/Users/peterliu/Documents/openDevelopment/SF-Image/116.jpg");
    
    if(src.empty()){
        cout << "no image files" << endl;
    }
    imshow("source", src);
    Mat gray, gray_ga, edge;
    
    // Gray without gaussian filter
    cvtColor(src, gray, CV_BGR2GRAY);
    imshow("g", gray);
    threshold(gray, gray, converthreshold, 255, CV_THRESH_BINARY);
    bitwise_not(gray, gray);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/116-gray.jpg", gray);
    imshow("Gray", gray);
    
    
    // Gray with gaussian filter
    src.copyTo(gray_ga);
    //    for(int i = 1; i <MAX_KERNAL_LENGTH; i += 2){
    //        GaussianBlur(gray_ga, gray_ga, Size(i,i), GASSIONTHRESHOLD);
    //    }
    GaussianBlur(gray_ga, gray_ga, Size(GASSIONKERNALX,GASSIONKERNALX), GASSIONTHRESHOLD);
    //    GaussianBlur(gray_ga, gray_ga, Size(GASSIONKERNALX,GASSIONKERNALX), GASSIONTHRESHOLD);
    
    cvtColor(gray_ga, gray_ga, CV_BGR2GRAY);
    threshold(gray_ga, gray_ga, converthreshold, 255, CV_THRESH_BINARY);
    bitwise_not(gray_ga, gray_ga);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/116-gray-ga.jpg", gray_ga);
    imshow("Gray_ga", gray_ga);
    
    Canny(gray_ga, edge, 3, 3);
    imshow("Edge", edge);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/116-gray-border.jpg", edge);
    waitKey(0);
}

// 117 processed
void process117(){
    int converthreshold = 136;
    
    //Read source file
    Mat src = imread("/Users/peterliu/Documents/openDevelopment/SF-Image/117.jpg");
    
    if(src.empty()){
        cout << "no image files" << endl;
    }
    imshow("source", src);
    Mat gray, gray_ga, edge;
    
    // Gray without gaussian filter
    cvtColor(src, gray, CV_BGR2GRAY);
    threshold(gray, gray, converthreshold, 255, CV_THRESH_BINARY);
    //    bitwise_not(gray, gray);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/117-gray.jpg", gray);
    imshow("Gray", gray);
    
    
    // Gray with gaussian filter
    src.copyTo(gray_ga);
    //    for(int i = 1; i <MAX_KERNAL_LENGTH; i += 2){
    //        GaussianBlur(gray_ga, gray_ga, Size(i,i), GASSIONTHRESHOLD);
    //    }
    
    //    GaussianBlur(gray_ga, gray_ga, Size(GASSIONKERNALX,GASSIONKERNALX), GASSIONTHRESHOLD);
    
    cvtColor(gray_ga, gray_ga, CV_BGR2GRAY);
    //    GaussianBlur(gray_ga, gray_ga, Size(GASSIONKERNALX,GASSIONKERNALX), GASSIONTHRESHOLD);
    threshold(gray_ga, gray_ga, converthreshold, 255, CV_THRESH_BINARY);
    //    bitwise_not(gray_ga, gray_ga);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/117-gray-ga.jpg", gray_ga);
    imshow("Gray_ga", gray_ga);
    
    Canny(gray_ga, edge, 3, 3);
    imshow("Edge", edge);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/117-gray-border.jpg", edge);
    waitKey(0);
}

// 118 processed
void process118(){
    int converthreshold = 180;
    
    //Read source file
    Mat src = imread("/Users/peterliu/Documents/openDevelopment/SF-Image/118.jpg");
    
    if(src.empty()){
        cout << "no image files" << endl;
    }
    imshow("source", src);
    Mat gray, gray_ga, edge;
    
    // Gray without gaussian filter
    cvtColor(src, gray, CV_BGR2GRAY);
    threshold(gray, gray, converthreshold, 255, CV_THRESH_BINARY);
    bitwise_not(gray, gray);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/118-gray.jpg", gray);
    imshow("Gray", gray);
    
    
    // Gray with gaussian filter
    src.copyTo(gray_ga);
    //    for(int i = 1; i <MAX_KERNAL_LENGTH; i += 2){
    //        GaussianBlur(gray_ga, gray_ga, Size(i,i), GASSIONTHRESHOLD);
    //    }
    GaussianBlur(gray_ga, gray_ga, Size(GASSIONKERNALX,GASSIONKERNALX), GASSIONTHRESHOLD);
    //    GaussianBlur(gray_ga, gray_ga, Size(GASSIONKERNALX,GASSIONKERNALX), GASSIONTHRESHOLD);
    
    cvtColor(gray_ga, gray_ga, CV_BGR2GRAY);
    threshold(gray_ga, gray_ga, converthreshold, 255, CV_THRESH_BINARY);
    bitwise_not(gray_ga, gray_ga);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/118-gray-ga.jpg", gray_ga);
    imshow("Gray_ga", gray_ga);
    
    Canny(gray_ga, edge, 3, 3);
    imshow("Edge", edge);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/118-gray-border.jpg", edge);
    waitKey(0);
}

// 119 processed
void process119(){
    int converthreshold = 160;
    
    //Read source file
    Mat src = imread("/Users/peterliu/Documents/openDevelopment/SF-Image/119.jpg");
    
    if(src.empty()){
        cout << "no image files" << endl;
    }
    imshow("source", src);
    Mat gray, gray_ga, edge;
    
    // Gray without gaussian filter
    cvtColor(src, gray, CV_BGR2GRAY);
    threshold(gray, gray, converthreshold, 255, CV_THRESH_BINARY);
    //    bitwise_not(gray, gray);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/119-gray.jpg", gray);
    imshow("Gray", gray);
    
    
    // Gray with gaussian filter
    src.copyTo(gray_ga);
    //    for(int i = 1; i <MAX_KERNAL_LENGTH; i += 2){
    //        GaussianBlur(gray_ga, gray_ga, Size(i,i), GASSIONTHRESHOLD);
    //    }
    GaussianBlur(gray_ga, gray_ga, Size(GASSIONKERNALX,GASSIONKERNALX), GASSIONTHRESHOLD);
    //    GaussianBlur(gray_ga, gray_ga, Size(GASSIONKERNALX,GASSIONKERNALX), GASSIONTHRESHOLD);
    
    cvtColor(gray_ga, gray_ga, CV_BGR2GRAY);
    threshold(gray_ga, gray_ga, converthreshold, 255, CV_THRESH_BINARY);
    //    bitwise_not(gray_ga, gray_ga);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/119-gray-ga.jpg", gray_ga);
    imshow("Gray_ga", gray_ga);
    
    Canny(gray_ga, edge, 3, 3);
    imshow("Edge", edge);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/119-gray-border.jpg", edge);
    waitKey(0);
}

// 120 processed
void process120(){
    int converthreshold = 128;
    
    //Read source file
    Mat src = imread("/Users/peterliu/Documents/openDevelopment/SF-Image/120.jpg");
    
    if(src.empty()){
        cout << "no image files" << endl;
    }
    imshow("source", src);
    Mat gray, gray_ga, edge;
    
    // Gray without gaussian filter
    cvtColor(src, gray, CV_BGR2GRAY);
    threshold(gray, gray, converthreshold, 255, CV_THRESH_BINARY);
    //    bitwise_not(gray, gray);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/120-gray.jpg", gray);
    imshow("Gray", gray);
    
    
    // Gray with gaussian filter
    src.copyTo(gray_ga);
    //    for(int i = 1; i <MAX_KERNAL_LENGTH; i += 2){
    //        GaussianBlur(gray_ga, gray_ga, Size(i,i), GASSIONTHRESHOLD);
    //    }
    GaussianBlur(gray_ga, gray_ga, Size(GASSIONKERNALX,GASSIONKERNALX), GASSIONTHRESHOLD);
    //    GaussianBlur(gray_ga, gray_ga, Size(GASSIONKERNALX,GASSIONKERNALX), GASSIONTHRESHOLD);
    
    cvtColor(gray_ga, gray_ga, CV_BGR2GRAY);
    threshold(gray_ga, gray_ga, converthreshold, 255, CV_THRESH_BINARY);
    //    bitwise_not(gray_ga, gray_ga);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/120-gray-ga.jpg", gray_ga);
    imshow("Gray_ga", gray_ga);
    
    Canny(gray_ga, edge, 3, 3);
    imshow("Edge", edge);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/120-gray-border.jpg", edge);
    
    waitKey(0);
}

// 121 processed
void process121(){
    int converthreshold = 160;
    
    //Read source file
    Mat src = imread("/Users/peterliu/Documents/openDevelopment/SF-Image/121.jpg");
    
    if(src.empty()){
        cout << "no image files" << endl;
    }
    imshow("source", src);
    Mat gray, gray_ga, edge;
    
    // Gray without gaussian filter
    cvtColor(src, gray, CV_BGR2GRAY);
    threshold(gray, gray, converthreshold, 255, CV_THRESH_BINARY);
    //    bitwise_not(gray, gray);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/121-gray.jpg", gray);
    imshow("Gray", gray);
    
    
    // Gray with gaussian filter
    src.copyTo(gray_ga);
    //    for(int i = 1; i <MAX_KERNAL_LENGTH; i += 2){
    //        GaussianBlur(gray_ga, gray_ga, Size(i,i), GASSIONTHRESHOLD);
    //    }
    GaussianBlur(gray_ga, gray_ga, Size(3,3), GASSIONTHRESHOLD);
    //    GaussianBlur(gray_ga, gray_ga, Size(GASSIONKERNALX,GASSIONKERNALX), GASSIONTHRESHOLD);
    
    cvtColor(gray_ga, gray_ga, CV_BGR2GRAY);
    threshold(gray_ga, gray_ga, converthreshold, 255, CV_THRESH_BINARY);
    //    bitwise_not(gray_ga, gray_ga);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/121-gray-ga.jpg", gray_ga);
    imshow("Gray_ga", gray_ga);
    
    Canny(gray_ga, edge, 3, 3);
    imshow("Edge", edge);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/121-gray-border.jpg", edge);
    waitKey(0);
}

// 122 processed
void process122(){
    int converthreshold = 160;
    
    //Read source file
    Mat src = imread("/Users/peterliu/Documents/openDevelopment/SF-Image/122.jpg");
    
    if(src.empty()){
        cout << "no image files" << endl;
    }
    imshow("source", src);
    Mat gray, gray_ga, edge;
    
    // Gray without gaussian filter
    cvtColor(src, gray, CV_BGR2GRAY);
    threshold(gray, gray, converthreshold, 255, CV_THRESH_BINARY);
    //    bitwise_not(gray, gray);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/122-gray.jpg", gray);
    imshow("Gray", gray);
    
    
    // Gray with gaussian filter
    src.copyTo(gray_ga);
    //    for(int i = 1; i <MAX_KERNAL_LENGTH; i += 2){
    //        GaussianBlur(gray_ga, gray_ga, Size(i,i), GASSIONTHRESHOLD);
    //    }
    GaussianBlur(gray_ga, gray_ga, Size(3,3), GASSIONTHRESHOLD);
    //    GaussianBlur(gray_ga, gray_ga, Size(GASSIONKERNALX,GASSIONKERNALX), GASSIONTHRESHOLD);
    
    cvtColor(gray_ga, gray_ga, CV_BGR2GRAY);
    threshold(gray_ga, gray_ga, converthreshold, 255, CV_THRESH_BINARY);
    //    bitwise_not(gray_ga, gray_ga);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/122-gray-ga.jpg", gray_ga);
    imshow("Gray_ga", gray_ga);
    
    Canny(gray_ga, edge, 3, 3);
    imshow("Edge", edge);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/122-gray-border.jpg", edge);
    waitKey(0);
}

// 123 processed
void process123(){
    int converthreshold = 160;
    
    //Read source file
    Mat src = imread("/Users/peterliu/Documents/openDevelopment/SF-Image/123.jpg");
    
    if(src.empty()){
        cout << "no image files" << endl;
    }
    imshow("source", src);
    Mat gray, gray_ga, edge;
    
    // Gray without gaussian filter
    cvtColor(src, gray, CV_BGR2GRAY);
    threshold(gray, gray, converthreshold, 255, CV_THRESH_BINARY);
    //    bitwise_not(gray, gray);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/123-gray.jpg", gray);
    imshow("Gray", gray);
    
    
    // Gray with gaussian filter
    src.copyTo(gray_ga);
    //    for(int i = 1; i <MAX_KERNAL_LENGTH; i += 2){
    //        GaussianBlur(gray_ga, gray_ga, Size(i,i), GASSIONTHRESHOLD);
    //    }
    GaussianBlur(gray_ga, gray_ga, Size(3,3), GASSIONTHRESHOLD);
    //    GaussianBlur(gray_ga, gray_ga, Size(GASSIONKERNALX,GASSIONKERNALX), GASSIONTHRESHOLD);
    
    cvtColor(gray_ga, gray_ga, CV_BGR2GRAY);
    threshold(gray_ga, gray_ga, converthreshold, 255, CV_THRESH_BINARY);
    //    bitwise_not(gray_ga, gray_ga);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/123-gray-ga.jpg", gray_ga);
    imshow("Gray_ga", gray_ga);
    
    Canny(gray_ga, edge, 3, 3);
    imshow("Edge", edge);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/123-gray-border.jpg", edge);
    waitKey(0);
}

// 124 processed
void process124(){
    int converthreshold = 160;
    
    //Read source file
    Mat src = imread("/Users/peterliu/Documents/openDevelopment/SF-Image/124.jpg");
    
    if(src.empty()){
        cout << "no image files" << endl;
    }
    imshow("source", src);
    Mat gray, gray_ga, edge;
    
    // Gray without gaussian filter
    cvtColor(src, gray, CV_BGR2GRAY);
    threshold(gray, gray, converthreshold, 255, CV_THRESH_BINARY);
    //    bitwise_not(gray, gray);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/124-gray.jpg", gray);
    imshow("Gray", gray);
    
    
    // Gray with gaussian filter
    src.copyTo(gray_ga);
    //    for(int i = 1; i <MAX_KERNAL_LENGTH; i += 2){
    //        GaussianBlur(gray_ga, gray_ga, Size(i,i), GASSIONTHRESHOLD);
    //    }
    GaussianBlur(gray_ga, gray_ga, Size(3,3), GASSIONTHRESHOLD);
    //    GaussianBlur(gray_ga, gray_ga, Size(GASSIONKERNALX,GASSIONKERNALX), GASSIONTHRESHOLD);
    
    cvtColor(gray_ga, gray_ga, CV_BGR2GRAY);
    threshold(gray_ga, gray_ga, converthreshold, 255, CV_THRESH_BINARY);
    //    bitwise_not(gray_ga, gray_ga);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/124-gray-ga.jpg", gray_ga);
    imshow("Gray_ga", gray_ga);
    
    Canny(gray_ga, edge, 3, 3);
    imshow("Edge", edge);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/124-gray-border.jpg", edge);
    waitKey(0);
}

// 125 processed
void process125(){
    int converthreshold = 128;
    
    //Read source file
    Mat src = imread("/Users/peterliu/Documents/openDevelopment/SF-Image/125.png");
    
    if(src.empty()){
        cout << "no image files" << endl;
    }
    imshow("source", src);
    Mat gray, gray_ga, edge;
    
    // Gray without gaussian filter
    cvtColor(src, gray, CV_BGR2GRAY);
    threshold(gray, gray, converthreshold, 255, CV_THRESH_BINARY);
    //    bitwise_not(gray, gray);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/125-gray.png", gray);
    imshow("Gray", gray);
    
    
    // Gray with gaussian filter
    src.copyTo(gray_ga);
    //    for(int i = 1; i <MAX_KERNAL_LENGTH; i += 2){
    //        GaussianBlur(gray_ga, gray_ga, Size(i,i), GASSIONTHRESHOLD);
    //    }
    GaussianBlur(gray_ga, gray_ga, Size(GASSIONKERNALX,GASSIONKERNALX), GASSIONTHRESHOLD);
    //    GaussianBlur(gray_ga, gray_ga, Size(GASSIONKERNALX,GASSIONKERNALX), GASSIONTHRESHOLD);
    
    cvtColor(gray_ga, gray_ga, CV_BGR2GRAY);
    threshold(gray_ga, gray_ga, converthreshold, 255, CV_THRESH_BINARY);
    //    bitwise_not(gray_ga, gray_ga);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/125-gray-ga.png", gray_ga);
    imshow("Gray_ga", gray_ga);
    
    Canny(gray_ga, edge, 3, 3);
    imshow("Edge", edge);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/125-gray-border.png", edge);
    waitKey(0);
}

// 126 processed
void process126(){
    int converthreshold = 128;
    
    //Read source file
    Mat src = imread("/Users/peterliu/Documents/openDevelopment/SF-Image/126.jpg");
    
    if(src.empty()){
        cout << "no image files" << endl;
    }
    imshow("source", src);
    Mat gray, gray_ga, edge;
    
    // Gray without gaussian filter
    cvtColor(src, gray, CV_BGR2GRAY);
    threshold(gray, gray, converthreshold, 255, CV_THRESH_BINARY);
    bitwise_not(gray, gray);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/126-gray.jpg", gray);
    imshow("Gray", gray);
    
    
    // Gray with gaussian filter
    src.copyTo(gray_ga);
    //    for(int i = 1; i <MAX_KERNAL_LENGTH; i += 2){
    //        GaussianBlur(gray_ga, gray_ga, Size(i,i), GASSIONTHRESHOLD);
    //    }
    GaussianBlur(gray_ga, gray_ga, Size(GASSIONKERNALX,GASSIONKERNALX), GASSIONTHRESHOLD);
    //    GaussianBlur(gray_ga, gray_ga, Size(GASSIONKERNALX,GASSIONKERNALX), GASSIONTHRESHOLD);
    
    cvtColor(gray_ga, gray_ga, CV_BGR2GRAY);
    threshold(gray_ga, gray_ga, converthreshold, 255, CV_THRESH_BINARY);
    bitwise_not(gray_ga, gray_ga);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/126-gray-ga.jpg", gray_ga);
    imshow("Gray_ga", gray_ga);
    
    Canny(gray_ga, edge, 3, 3);
    imshow("Edge", edge);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/126-gray-border.jpg", edge);
    waitKey(0);
}

// 127 processed
void process127(){
    int converthreshold = 128;
    
    //Read source file
    Mat src = imread("/Users/peterliu/Documents/openDevelopment/SF-Image/127.jpg");
    
    if(src.empty()){
        cout << "no image files" << endl;
    }
    imshow("source", src);
    Mat gray, gray_ga, edge;
    
    // Gray without gaussian filter
    cvtColor(src, gray, CV_BGR2GRAY);
    threshold(gray, gray, converthreshold, 255, CV_THRESH_BINARY);
    //    bitwise_not(gray, gray);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/127-gray.jpg", gray);
    imshow("Gray", gray);
    
    
    // Gray with gaussian filter
    src.copyTo(gray_ga);
    //    for(int i = 1; i <MAX_KERNAL_LENGTH; i += 2){
    //        GaussianBlur(gray_ga, gray_ga, Size(i,i), GASSIONTHRESHOLD);
    //    }
    GaussianBlur(gray_ga, gray_ga, Size(GASSIONKERNALX,GASSIONKERNALX), GASSIONTHRESHOLD);
    //    GaussianBlur(gray_ga, gray_ga, Size(GASSIONKERNALX,GASSIONKERNALX), GASSIONTHRESHOLD);
    
    cvtColor(gray_ga, gray_ga, CV_BGR2GRAY);
    threshold(gray_ga, gray_ga, converthreshold, 255, CV_THRESH_BINARY);
    //    bitwise_not(gray_ga, gray_ga);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/127-gray-ga.jpg", gray_ga);
    imshow("Gray_ga", gray_ga);
    
    Canny(gray_ga, edge, 3, 3);
    imshow("Edge", edge);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/127-gray-border.jpg", edge);
    waitKey(0);
}

// 128 processed
void process128(){
    int converthreshold = 128;
    
    //Read source file
    Mat src = imread("/Users/peterliu/Documents/openDevelopment/SF-Image/128.JPG");
    
    if(src.empty()){
        cout << "no image files" << endl;
    }
    imshow("source", src);
    Mat gray, gray_ga, edge;
    
    // Gray without gaussian filter
    cvtColor(src, gray, CV_BGR2GRAY);
    threshold(gray, gray, converthreshold, 255, CV_THRESH_BINARY);
    bitwise_not(gray, gray);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/128-gray.JPG", gray);
    imshow("Gray", gray);
    
    
    // Gray with gaussian filter
    src.copyTo(gray_ga);
    //    for(int i = 1; i <MAX_KERNAL_LENGTH; i += 2){
    //        GaussianBlur(gray_ga, gray_ga, Size(i,i), GASSIONTHRESHOLD);
    //    }
    GaussianBlur(gray_ga, gray_ga, Size(GASSIONKERNALX,GASSIONKERNALX), GASSIONTHRESHOLD);
    //    GaussianBlur(gray_ga, gray_ga, Size(GASSIONKERNALX,GASSIONKERNALX), GASSIONTHRESHOLD);
    
    cvtColor(gray_ga, gray_ga, CV_BGR2GRAY);
    threshold(gray_ga, gray_ga, converthreshold, 255, CV_THRESH_BINARY);
    bitwise_not(gray_ga, gray_ga);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/128-gray-ga.JPG", gray_ga);
    imshow("Gray_ga", gray_ga);
    
    Canny(gray_ga, edge, 3, 3);
    imshow("Edge", edge);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/128-gray-border.JPG", edge);
    waitKey(0);
}

// 129 processed
void process129(){
    int converthreshold = 160;
    
    //Read source file
    Mat src = imread("/Users/peterliu/Documents/openDevelopment/SF-Image/129.jpg");
    
    if(src.empty()){
        cout << "no image files" << endl;
    }
    imshow("source", src);
    Mat gray, gray_ga, edge;
    
    // Gray without gaussian filter
    cvtColor(src, gray, CV_BGR2GRAY);
    threshold(gray, gray, converthreshold, 255, CV_THRESH_BINARY);
    //    bitwise_not(gray, gray);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/129-gray.jpg", gray);
    imshow("Gray", gray);
    
    
    // Gray with gaussian filter
    src.copyTo(gray_ga);
    //    for(int i = 1; i <MAX_KERNAL_LENGTH; i += 2){
    //        GaussianBlur(gray_ga, gray_ga, Size(i,i), GASSIONTHRESHOLD);
    //    }
    GaussianBlur(gray_ga, gray_ga, Size(3,3), GASSIONTHRESHOLD);
    //    GaussianBlur(gray_ga, gray_ga, Size(GASSIONKERNALX,GASSIONKERNALX), GASSIONTHRESHOLD);
    
    cvtColor(gray_ga, gray_ga, CV_BGR2GRAY);
    GaussianBlur(gray_ga, gray_ga, Size(3,3), GASSIONTHRESHOLD);
    
    threshold(gray_ga, gray_ga, converthreshold, 255, CV_THRESH_BINARY);
    //    bitwise_not(gray_ga, gray_ga);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/129-gray-ga.jpg", gray_ga);
    imshow("Gray_ga", gray_ga);
    
    Canny(gray_ga, edge, 3, 3);
    imshow("Edge", edge);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/129-gray-border.jpg", edge);
    waitKey(0);
}

// 130 processed
void process130(){
    int converthreshold = 110;
    
    //Read source file
    Mat src = imread("/Users/peterliu/Documents/openDevelopment/SF-Image/130.jpg");
    
    if(src.empty()){
        cout << "no image files" << endl;
    }
    imshow("source", src);
    Mat gray, gray_ga, edge;
    
    // Gray without gaussian filter
    cvtColor(src, gray, CV_BGR2GRAY);
    threshold(gray, gray, converthreshold, 255, CV_THRESH_BINARY);
    bitwise_not(gray, gray);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/130-gray.jpg", gray);
    imshow("Gray", gray);
    
    
    // Gray with gaussian filter
    src.copyTo(gray_ga);
    //    for(int i = 1; i <MAX_KERNAL_LENGTH; i += 2){
    //        GaussianBlur(gray_ga, gray_ga, Size(i,i), GASSIONTHRESHOLD);
    //    }
    GaussianBlur(gray_ga, gray_ga, Size(GASSIONKERNALX,GASSIONKERNALX), GASSIONTHRESHOLD);
    //    GaussianBlur(gray_ga, gray_ga, Size(GASSIONKERNALX,GASSIONKERNALX), GASSIONTHRESHOLD);
    
    cvtColor(gray_ga, gray_ga, CV_BGR2GRAY);
    GaussianBlur(gray_ga, gray_ga, Size(GASSIONKERNALX,GASSIONKERNALX), GASSIONTHRESHOLD);
    threshold(gray_ga, gray_ga, converthreshold, 255, CV_THRESH_BINARY);
    bitwise_not(gray_ga, gray_ga);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/130-gray-ga.jpg", gray_ga);
    imshow("Gray_ga", gray_ga);
    
    Canny(gray_ga, edge, 3, 3);
    imshow("Edge", edge);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/130-gray-border.jpg", edge);
    waitKey(0);
}

// 131 processed
void process131(){
    int converthreshold = 128;
    
    //Read source file
    Mat src = imread("/Users/peterliu/Documents/openDevelopment/SF-Image/131.jpg");
    
    if(src.empty()){
        cout << "no image files" << endl;
    }
    imshow("source", src);
    Mat gray, gray_ga, edge;
    
    // Gray without gaussian filter
    cvtColor(src, gray, CV_BGR2GRAY);
    threshold(gray, gray, converthreshold, 255, CV_THRESH_BINARY);
    bitwise_not(gray, gray);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/131-gray.jpg", gray);
    imshow("Gray", gray);
    
    
    // Gray with gaussian filter
    src.copyTo(gray_ga);
    //    for(int i = 1; i <MAX_KERNAL_LENGTH; i += 2){
    //        GaussianBlur(gray_ga, gray_ga, Size(i,i), GASSIONTHRESHOLD);
    //    }
    GaussianBlur(gray_ga, gray_ga, Size(GASSIONKERNALX,GASSIONKERNALX), GASSIONTHRESHOLD);
    //    GaussianBlur(gray_ga, gray_ga, Size(GASSIONKERNALX,GASSIONKERNALX), GASSIONTHRESHOLD);
    
    cvtColor(gray_ga, gray_ga, CV_BGR2GRAY);
    threshold(gray_ga, gray_ga, converthreshold, 255, CV_THRESH_BINARY);
    bitwise_not(gray_ga, gray_ga);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/131-gray-ga.jpg", gray_ga);
    imshow("Gray_ga", gray_ga);
    
    Canny(gray_ga, edge, 3, 3);
    imshow("Edge", edge);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/131-gray-border.jpg", edge);
    waitKey(0);
}

// 132 processed
void process132(){
    int converthreshold = 146;
    
    //Read source file
    Mat src = imread("/Users/peterliu/Documents/openDevelopment/SF-Image/132.jpg");
    
    if(src.empty()){
        cout << "no image files" << endl;
    }
    imshow("source", src);
    Mat gray, gray_ga, edge;
    
    // Gray without gaussian filter
    cvtColor(src, gray, CV_BGR2GRAY);
    threshold(gray, gray, converthreshold, 255, CV_THRESH_BINARY);
    bitwise_not(gray, gray);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/132-gray.jpg", gray);
    imshow("Gray", gray);
    
    
    // Gray with gaussian filter
    src.copyTo(gray_ga);
    //    for(int i = 1; i <MAX_KERNAL_LENGTH; i += 2){
    //        GaussianBlur(gray_ga, gray_ga, Size(i,i), GASSIONTHRESHOLD);
    //    }
    GaussianBlur(gray_ga, gray_ga, Size(GASSIONKERNALX,GASSIONKERNALX), GASSIONTHRESHOLD);
    //    GaussianBlur(gray_ga, gray_ga, Size(GASSIONKERNALX,GASSIONKERNALX), GASSIONTHRESHOLD);
    
    cvtColor(gray_ga, gray_ga, CV_BGR2GRAY);
    threshold(gray_ga, gray_ga, converthreshold, 255, CV_THRESH_BINARY);
    bitwise_not(gray_ga, gray_ga);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/132-gray-ga.jpg", gray_ga);
    imshow("Gray_ga", gray_ga);
    
    Canny(gray_ga, edge, 3, 3);
    imshow("Edge", edge);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/132-gray-border.jpg", edge);
    waitKey(0);
}

void process133(){
    int converthreshold = 128;
    
    //Read source file
    Mat src = imread("/Users/peterliu/Documents/openDevelopment/SF-Image/132.jpg");
    
    if(src.empty()){
        cout << "no image files" << endl;
    }
    imshow("source", src);
    Mat gray, gray_ga, edge;
    
    // Gray without gaussian filter
    cvtColor(src, gray, CV_BGR2GRAY);
    threshold(gray, gray, converthreshold, 255, CV_THRESH_BINARY);
    bitwise_not(gray, gray);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/132-gray.jpg", gray);
    imshow("Gray", gray);
    
    
    // Gray with gaussian filter
    src.copyTo(gray_ga);
    //    for(int i = 1; i <MAX_KERNAL_LENGTH; i += 2){
    //        GaussianBlur(gray_ga, gray_ga, Size(i,i), GASSIONTHRESHOLD);
    //    }
    GaussianBlur(gray_ga, gray_ga, Size(GASSIONKERNALX,GASSIONKERNALX), GASSIONTHRESHOLD);
    //    GaussianBlur(gray_ga, gray_ga, Size(GASSIONKERNALX,GASSIONKERNALX), GASSIONTHRESHOLD);
    
    cvtColor(gray_ga, gray_ga, CV_BGR2GRAY);
    threshold(gray_ga, gray_ga, converthreshold, 255, CV_THRESH_BINARY);
    bitwise_not(gray_ga, gray_ga);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/132-gray-ga.jpg", gray_ga);
    imshow("Gray_ga", gray_ga);
    
    Canny(gray_ga, edge, 3, 3);
    imshow("Edge", edge);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/132-gray-border.jpg", edge);
    waitKey(0);
}

// 134 processed
void process134(){
    int converthreshold = 128;
    
    //Read source file
    Mat src = imread("/Users/peterliu/Documents/openDevelopment/SF-Image/134.jpg");
    
    if(src.empty()){
        cout << "no image files" << endl;
    }
    imshow("source", src);
    Mat gray, gray_ga, edge;
    
    // Gray without gaussian filter
    cvtColor(src, gray, CV_BGR2GRAY);
    threshold(gray, gray, converthreshold, 255, CV_THRESH_BINARY);
    bitwise_not(gray, gray);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/134-gray.jpg", gray);
    imshow("Gray", gray);
    
    
    // Gray with gaussian filter
    src.copyTo(gray_ga);
    //    for(int i = 1; i <MAX_KERNAL_LENGTH; i += 2){
    //        GaussianBlur(gray_ga, gray_ga, Size(i,i), GASSIONTHRESHOLD);
    //    }
    GaussianBlur(gray_ga, gray_ga, Size(GASSIONKERNALX,GASSIONKERNALX), GASSIONTHRESHOLD);
    //    GaussianBlur(gray_ga, gray_ga, Size(GASSIONKERNALX,GASSIONKERNALX), GASSIONTHRESHOLD);
    
    cvtColor(gray_ga, gray_ga, CV_BGR2GRAY);
    threshold(gray_ga, gray_ga, converthreshold, 255, CV_THRESH_BINARY);
    bitwise_not(gray_ga, gray_ga);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/134-gray-ga.jpg", gray_ga);
    imshow("Gray_ga", gray_ga);
    
    Canny(gray_ga, edge, 3, 3);
    imshow("Edge", edge);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/134-gray-border.jpg", edge);
    waitKey(0);
}


// 135 processed
void process135(){
    int converthreshold = 180;
    
    //Read source file
    Mat src = imread("/Users/peterliu/Documents/openDevelopment/SF-Image/135.jpg");
    
    if(src.empty()){
        cout << "no image files" << endl;
    }
    imshow("source", src);
    Mat gray, gray_ga, edge;
    
    // Gray without gaussian filter
    cvtColor(src, gray, CV_BGR2GRAY);
    threshold(gray, gray, converthreshold, 255, CV_THRESH_BINARY);
    bitwise_not(gray, gray);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/135-gray.jpg", gray);
    imshow("Gray", gray);
    
    
    // Gray with gaussian filter
    src.copyTo(gray_ga);
    //    for(int i = 1; i <MAX_KERNAL_LENGTH; i += 2){
    //        GaussianBlur(gray_ga, gray_ga, Size(i,i), GASSIONTHRESHOLD);
    //    }
    GaussianBlur(gray_ga, gray_ga, Size(GASSIONKERNALX,GASSIONKERNALX), GASSIONTHRESHOLD);
    //    GaussianBlur(gray_ga, gray_ga, Size(GASSIONKERNALX,GASSIONKERNALX), GASSIONTHRESHOLD);
    
    cvtColor(gray_ga, gray_ga, CV_BGR2GRAY);
    threshold(gray_ga, gray_ga, converthreshold, 255, CV_THRESH_BINARY);
    bitwise_not(gray_ga, gray_ga);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/135-gray-ga.jpg", gray_ga);
    imshow("Gray_ga", gray_ga);
    
    Canny(gray_ga, edge, 3, 3);
    imshow("Edge", edge);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/135-gray-border.jpg", edge);
    waitKey(0);
}

// 136 processed
void process136(){
    int converthreshold = 120;
    
    //Read source file
    Mat src = imread("/Users/peterliu/Documents/openDevelopment/SF-Image/136.jpg");
    
    if(src.empty()){
        cout << "no image files" << endl;
    }
    imshow("source", src);
    Mat gray, gray_ga, edge;
    
    // Gray without gaussian filter
    cvtColor(src, gray, CV_BGR2GRAY);
    threshold(gray, gray, converthreshold, 255, CV_THRESH_BINARY);
    //    bitwise_not(gray, gray);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/136-gray.jpg", gray);
    imshow("Gray", gray);
    
    
    // Gray with gaussian filter
    src.copyTo(gray_ga);
    //    for(int i = 1; i <MAX_KERNAL_LENGTH; i += 2){
    //        GaussianBlur(gray_ga, gray_ga, Size(i,i), GASSIONTHRESHOLD);
    //    }
    GaussianBlur(gray_ga, gray_ga, Size(GASSIONKERNALX,GASSIONKERNALX), GASSIONTHRESHOLD);
    //    GaussianBlur(gray_ga, gray_ga, Size(GASSIONKERNALX,GASSIONKERNALX), GASSIONTHRESHOLD);
    
    cvtColor(gray_ga, gray_ga, CV_BGR2GRAY);
    threshold(gray_ga, gray_ga, converthreshold, 255, CV_THRESH_BINARY);
    //    bitwise_not(gray_ga, gray_ga);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/136-gray-ga.jpg", gray_ga);
    imshow("Gray_ga", gray_ga);
    
    Canny(gray_ga, edge, 3, 3);
    imshow("Edge", edge);
    imwrite("/Users/peterliu/Documents/openDevelopment/processed/136-gray-border.jpg", edge);
    waitKey(0);
}

// 锐化算法
void Sharpen(const Mat& myImage, Mat& Result)
{
    CV_Assert(myImage.depth() == CV_8U);  // accept only uchar images
    
    Result.create(myImage.size(), myImage.type());
    const int nChannels = myImage.channels();
    
    for(int j = 1; j < myImage.rows - 1; ++j)
    {
        const uchar* previous = myImage.ptr<uchar>(j - 1);
        const uchar* current  = myImage.ptr<uchar>(j    );
        const uchar* next     = myImage.ptr<uchar>(j + 1);
        
        uchar* output = Result.ptr<uchar>(j);
        
        for(int i = nChannels; i < nChannels * (myImage.cols - 1); ++i)
        {
            *output++ = saturate_cast<uchar>(5 * current[i]
                                             -current[i - nChannels] - current[i + nChannels] - previous[i] - next[i]);
        }
    }
    
    Result.row(0).setTo(Scalar(0));
    Result.row(Result.rows - 1).setTo(Scalar(0));
    Result.col(0).setTo(Scalar(0));
    Result.col(Result.cols - 1).setTo(Scalar(0));
}


// 高低差值保留算法: 增强图像 ＝ 模糊图像 ＋ Amout ＊ （原始图像 － 高斯模糊图像）
Mat HighLowConstrastSave(Mat& source){
    
    Mat result, gaussian;
    
    // init the result
    source.copyTo(result);
    
    //Gaussian Filter
    GaussianBlur(source, gaussian, Size(GASSIONKERNALX,GASSIONKERNALX), GASSIONTHRESHOLD);
    
    int source_Width = source.rows;
    int source_Height = source.cols;
    
    for(int y = 0; y < source_Height; y++){
        for (int x = 0; x < source_Width; x++) {
            result.at<Vec3d>(y,x) = gaussian.at<Vec3d>(y,x) + AMOUT * (source.at<Vec3d>(y,x) - gaussian.at<Vec3d>(y,x));
            
        }
    }
    
    return result;
}