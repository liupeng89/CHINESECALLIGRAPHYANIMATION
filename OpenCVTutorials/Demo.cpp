//
//  Demo.cpp
//  OpenCVTutorials
//
//  Created by PeterLiu on 1/13/16.
//  Copyright © 2016 PeterLiu. All rights reserved.
//

#include "Demo.hpp"

int _width = 0;
int _height = 0;

CAPoint *edgepoints;
CAPoint *tracepoints;

int _edgeLen = 0;
int _traceLen = 0;

int _displayorder = 0;

////////////////////////////////////////////////////////////////////////////////////////////////
//Initilize all data
void init(){
    // 1. load source image file
    // 1. Image process
    Mat src = imageprocess(source);
    imshow("src", src);
    _width = src.cols;
    _height = src.rows;
    
    // 2. Edge detection
    Mat edge ;
    src.copyTo(edge);
    edge = edgeDetection(edge);
    
    FILE *ofp = fopen(edgedatafile.c_str(), "w");
    
    if ( ofp == NULL ){
        cout << "Edge data file open failed!" << endl;
        return ;
    }
    
    // get the coordinate of points on edge and save to file.
    
    for (int x = 0; x < _height; x++) {
        for (int y = 0; y < _width; y++) {
            Scalar color = edge.at<char>(y, x);
            if (color.val[0] != 0) {
                cout << "x:" << x << "," << "y:" << y << endl;
                fprintf(ofp, "%d %d\n", x, y);
                _edgeLen++;
            }
        }
    }
    
    fclose(ofp);
    
    
    //    saveEdgeDataToFile(edge, edgedatafile);
    //    imshow("edge", edge);
    
    // 3. Trace Line detection
    Mat thinning;
    src.copyTo(thinning);
    bitwise_not(thinning, thinning);
    
    thinningImage(thinning, thinning);
    
    // Save the trace data to file
    ofp = fopen(thinningdatafile.c_str(), "w");
    if (ofp == NULL) {
        cout << "Thinning data file open failed!"<< endl;
    }
    
    for (int x = 0; x < _width; x++) {
        for (int y = 0; y < _height; y++) {
            // save the data.
            Scalar color = thinning.at<char>(y, x);
            if (color.val[0] != 0) {
                // white point save
                fprintf(ofp, "%d %d\n", x, y);
                _traceLen++;
            }
            
        }
    }
    
    fclose(ofp);
    
    if (_edgeLen == 0) {
        cout << "The edge point number is zero!" << endl;
        return;
    }
    
    if (_edgeLen == 0) {
        cout << " The trace point number is zero!" << endl;
    }
    /*
     The edge function
     */
    // Load the edge point data and animation
    CAPoint _edgepoints[_edgeLen];
    GLfloat _x, _y;
    
    ofp = fopen(edgedatafile.c_str(), "r");
    int index = 0;
    while (fscanf(ofp, "%f %f", &_x, &_y) == 2) {
        if (index >= _edgeLen) {
            break;
        }
        _edgepoints[index].x = _x;
        _edgepoints[index].y = _y;
        index++;
    }
    
    fclose(ofp);
    
    edgepoints = _edgepoints;
    
    // Check the edge point
    cout << "The edge point:" << endl;
    
    for (int i = 0; i < _edgeLen; i++) {
        cout << "x:" << edgepoints[i].x << " y:" << edgepoints[i].y << endl;
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
     The trace function
     */
    CAPoint _tracepoints[_traceLen];
    
    ofp = fopen(thinningdatafile.c_str(), "r");
    index = 0;
    while (fscanf(ofp, "%f %f", &_x, &_y) == 2) {
        if (index >= _traceLen) {
            break;
        }
        _tracepoints[index].x = _x;
        _tracepoints[index].y = _y;
        index++;
    }
    
    fclose(ofp);
    
    tracepoints = _tracepoints;
    
    // Check the trace point
    cout << "The trace point:" << endl;
    for (int i = 0; i < _traceLen; i++) {
        cout << "x:" << tracepoints[i].x << " y: " << tracepoints[i].y << endl;
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////


}
/////////////////////////////////////////////////////////////////////////////
Mat imageprocess(string source){
    Mat src;
    
    // Load image file.
    src = imread(source);
    if (src.empty()) {
        cout << "The image file is empty!" << endl;
        return src;
    }
    
    // Gray
    cvtColor(src, src, CV_BGR2GRAY, 1);
    
    return src;
}
/////////////////////////////////////////////////////////////////////////////
// Ray casting algorithm
bool raycasting(GLfloat x, GLfloat y, CAPoint *points, int length){
    if (length == 0) {
        return false;
    }
    int count = 0;
    for (ptrdiff_t i = 0; i < length; i++) {
        if (points[i].y == y && points[i].x != x) {
            count++;
        }
    }
    
    if (count % 2 == 1) {
        // Odd number, inside
        return true;
    }
    // Even number, outsize
    return false;
}
/////////////////////////////////////////////////////////////////////////////
void draw(){
    if (_displayorder == _traceLen) {
        return;
    }
    
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    
    drawEllipse(tracepoints[_displayorder].x, tracepoints[_displayorder].y, 10.0/ _width, 10.0/_height);
    if (_displayorder < _traceLen) {
        _displayorder++;
        cout << "num:" << _displayorder << endl;
    }
    glEnd();
    glFlush();
}
/////////////////////////////////////////////////////////////////////////////
void drawEllipse(GLfloat x,GLfloat y,GLfloat ra,GLfloat rb){
    for (GLfloat i = 0.0; i < 360.0; i+= 0.1) {
        GLfloat degInRad = i * DEG2RAD;
        GLfloat _x = cos(degInRad) * ra + x;
        GLfloat _y = sin(degInRad) * rb + y;
        //Check the coordiante
//        if (raycasting(_x, _y, edgepoints, _edgeLen)) {
//            glVertex2f(_x, _y);
//        }
        glVertex2f(_x, _y);
    }
}
/////////////////////////////////////////////////////////////////////////////
void Timer(int){
    glutPostRedisplay();
    glutTimerFunc(_delay, Timer, 0);
}
/////////////////////////////////////////////////////////////////////////////
// Demo operation
void demo(){
    
    init();
    
    // 4. Animation
    
    
}

void demo(int argc, char** argv){
    
    init();
    
    //Animation
    cout << "Animation begin:" << endl;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(_width, _height);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Chinese Animation");
    
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    
    glutDisplayFunc(draw);
    Timer(0);
    glutMainLoop();
    

}