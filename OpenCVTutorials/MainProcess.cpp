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
    
    // 8. Animation based on the edge data and skeleton data.
    
    // Clean
    waitKey(0);
    src.release();
    skeleton.release();
}