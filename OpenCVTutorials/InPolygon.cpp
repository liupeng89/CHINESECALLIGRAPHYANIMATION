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
    cout << "len:" << len << endl;
    // Copy the points data.
    tmp = (Point2 *)malloc(len * sizeof(Point2));
    sorted = (Point2 *)malloc(len * sizeof(Point2));
    
    for (int i = 0; i < len; i++) {
        //
        tmp[i].x = unsorted[i].x;
        tmp[i].y = unsorted[i].y;
        cout << unsorted[i].x << " " << unsorted[i].y << endl;
    }
    
    // Strat point
    
    int count = 0;
    
    int index = 0;

    int pre = 0;
    while (count < len) {
        // start point
        Point2 start = unsorted[index];
        pre = index;
        double distance = MAXINFINATE;
        for (int i = 0; i < len; i++) {
            //
            double dis = sqrt((start.x - tmp[i].x) * (start.x - tmp[i].x) + (start.y - tmp[i].y) * (start.y - tmp[i].y));
            if (dis == 0 || dis >= MAXINFINATE) {
                continue;
            }
            if (dis < distance) {
                distance = dis;
                
                index = i;
            }
            if (i == len - 1) {
                // get the min distance
                sorted[count].x = unsorted[pre].x;
                sorted[count].y = unsorted[pre].y;
                tmp[pre].x = MAXINFINATE;
                tmp[pre].y = MAXINFINATE;
                
                cout << "count:" << count << " " << sorted[count].x << endl;
            }
        }
        count++;
    }
    
    
    free(tmp);
    
    // Check the result
    cout << "The sorted result:" << endl;
    for (int i = 0; i < len; i++) {
        cout << sorted[i].x << " " << sorted[i].y << endl;
    }
    
    return sorted;
}