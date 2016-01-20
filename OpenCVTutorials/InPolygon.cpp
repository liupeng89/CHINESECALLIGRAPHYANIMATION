//
//  InPolygon.cpp
//  OpenCVTutorials
//
//  Created by PeterLiu on 1/15/16.
//  Copyright © 2016 PeterLiu. All rights reserved.
//

#include "InPolygon.hpp"

Point2 *sortPoints(Point2 *unsorted, int len){
    Point2 *sorted, *tmp;
    
    if (len == 0) {
        cout << "The points len is zero" << endl;
        return sorted;
    }
    
    // Copy the points data.
    tmp = (Point2 *)malloc(len * sizeof(Point2));
    sorted = (Point2 *)malloc(len * sizeof(Point2));
    
    for (int i = 0; i < len; i++) {
        //
        tmp[i].x = unsorted[i].x;
        tmp[i].y = unsorted[i].y;
    }
    
    // Strat point
    
    int count = 0;
    Point2 start = tmp[count];
    sorted[count].x = start.x;
    sorted[count].y = start.y;
    
    double distance = sqrt((start.x - tmp[1].x) * (start.x - tmp[1].x) + (start.y - tmp[1].y) * (start.y - tmp[1].y));
    
    int index = 0;
    while (count < len) {
        // new start point
        start = tmp[index];
        for (int i = 0; i < len; i++) {
            //
            double dis = sqrt((start.x - tmp[i].x) * (start.x - tmp[i].x) + (start.y - tmp[i].y) * (start.y - tmp[i].y));
            if (dis < distance) {
                // Get the min distance.

                distance = dis;
                if (i == len - 1) {
                    tmp[index].x = MAXINFINATE;
                    tmp[index].y = MAXINFINATE;
                    index = i;
                    sorted[count].x = tmp[i].x;
                    sorted[count].y = tmp[i].y;
                }
            }
        }
        count++;
    }
    
    free(tmp);
    return sorted;
}