//
//  MainProcess.cpp
//  OpenCVTutorials
//
//  Created by PeterLiu on 1/19/16.
//  Copyright © 2016 PeterLiu. All rights reserved.
//

#include "MainProcess.hpp"

//The main process function
void process(int, char**) {
    
    // 1. Get the original image from system.
    Mat src = loadImageFile(source);
    
    // 2. Process the image, filter and smooth.
    src = processImage(src);
    imshow("Src", src);
    // 3. Get the skeleton of image.
    Mat skeleton;
    src.copyTo(skeleton);
    bitwise_not(skeleton, skeleton);
    
    thinningImage(skeleton, skeleton);
    imshow("Thinning", skeleton);
    // 4. Add the skeleton to the original image.
    int width = src.cols;
    int height = src.rows;
    int count = 0;
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            // Add the points of skeleton to the original image.
            Scalar color = skeleton.at<uchar>(y,x);
            if (color.val[0] != 0) {
                // The point at skeleton
                src.at<uchar>(y, x) = 255;
                count++;
            }
        }
    }
    
    imshow("Add Skeletion", src);
    cout << "count:" << count << endl;
    // 5. Convert the image to SVG.
    saveImageFile(src, imageWithSkeletion);
    
    // 6. Modify the skeleton to fit the daily using by hand.
    
    // 7. Covert the SVG data of skeletion to two-demantional coordinates.
    string pathdata = "m 57.752048,95.058877 c 1.052901,-0.705039 -15.770056,1.368959 -14.91777,3.850501 1.172969,3.415252 2.956941,4.496142 4.112754,5.269142 1.155814,0.773 6.582788,2.66803 8.391682,2.78795 1.808894,0.11992 6.516476,-3.78243 9.379534,-4.71667 C 103.32388,92.077311 145.62632,91.401333 182.24479,90.78927 l 47.86454,0.67415 9.43808,-2.808949 c 11.5623,4.366148 14.58581,7.820893 19.94355,17.134609 -1.35356,5.61311 -4.40728,8.89499 -8.87628,7.07856 -2.38642,-6.93931 -5.54367,-9.2876 -12.64028,-11.51671";
    
    // SVG --> 2D points
    
    
    // 8. Animation based on the edge data and skeleton data.
    
    // Clean
    waitKey(0);
    src.release();
    skeleton.release();
}