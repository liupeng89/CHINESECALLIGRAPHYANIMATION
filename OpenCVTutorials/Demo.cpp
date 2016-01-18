//
//  Demo.cpp
//  OpenCVTutorials
//
//  Created by PeterLiu on 1/13/16.
//  Copyright © 2016 PeterLiu. All rights reserved.
//

#include "Demo.hpp"

GLfloat _width = 0.0;
GLfloat _height = 0.0;

struct CAPoint *edgepoints;
struct CAPoint *tracepoints;
int *imgVertex;

//int *imgVertex;

//int imgVertex[90000];

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
//                cout << "x:" << x << "," << "y:" << y << endl;
                fprintf(ofp, "%d %d\n", x, y);
                _edgeLen++;
            }
        }
    }
    
    fclose(ofp);
    
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
    
    if (_traceLen == 0) {
        cout << " The trace point number is zero!" << endl;
    }
    
    src.release();
    edge.release();
    thinning.release();
}
// Get the gray vertex
int *getImgColorVert(){
    
    Mat src = imageprocess(source);
//    cout << src.channels() << endl;
    int w = src.cols;
    int h = src.rows;
    int *vert = (int *)malloc((w * h )* sizeof(int));
    int count = 0;
    for (int x = 0; x < w; x++) {
        for (int y = 0; y < h; y++) {
            //
            Scalar color = src.at<uchar>(y, x);
//            cout << color.val[0] << endl;
            if (color.val[0] != 0) {
                vert[x * h + y] = 0;
            }else {
                vert[x * h + y] = 1;
                count++;
            }
        }
    }
    
    cout << "the gray count num" << count << endl;
    
    src.release();
    return vert;
}


//////////////////////////////////////////////////////////////////////////////////////////////////
CAPoint *getEdgePoints(){
    // Load the edge point data and animation
    
    CAPoint *_edgepoints = (CAPoint *)malloc(_edgeLen * sizeof(CAPoint));
    GLfloat _x, _y;
    
    FILE *ofp = fopen(edgedatafile.c_str(), "r");
    int index = 0;
    while (fscanf(ofp, "%f %f", &_x, &_y) == 2) {
        _edgepoints[index].x = _x;
        _edgepoints[index].y = _y;
        index++;
    }
    
    fclose(ofp);
    return _edgepoints;
}

void getEdge(){
//    edgepoints = (CAPoint *)malloc(_edgeLen);
    GLfloat _x, _y;
    
    FILE *ofp = fopen(edgedatafile.c_str(), "r");
    int index = 0;
    while (fscanf(ofp, "%f %f", &_x, &_y) == 2) {
        edgepoints[index].x = _x;
        edgepoints[index].y = _y;
        index++;
    }
    
    fclose(ofp);
}
/////////////////////////////////////////////////////////
CAPoint *getTracePoints(){
    
    CAPoint *_tracepoints = (CAPoint *)malloc(_traceLen * sizeof(CAPoint));
    GLfloat _x, _y;
    
    FILE *ofp = fopen(thinningdatafile.c_str(), "r");
    int index = 0;
    while (fscanf(ofp, "%f %f", &_x, &_y) == 2) {
        
        _tracepoints[index].x = _x;
        _tracepoints[index].y = _y;
        index++;
    }
    
    fclose(ofp);
    return _tracepoints;
}

void getTrace(){
//    tracepoints = (CAPoint *)malloc(_traceLen);
    GLfloat _x, _y;
    
    FILE *ofp = fopen(thinningdatafile.c_str(), "r");
    int index = 0;
    while (fscanf(ofp, "%f %f", &_x, &_y) == 2) {
        
        tracepoints[index].x = _x;
        tracepoints[index].y = _y;
        index++;
    }
    
    fclose(ofp);
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
    for (int i = 0; i < length; i++) {
        if (points[i].y == y) {
            count++;
        }
    }
    cout << "count" << count << endl;
//    if (count % 2 == 1) {
//        // Odd number, inside
//        return true;
//    }
//    // Even number, outsize
//    return false;
    if (count == 2) {
        return true;
    }
    return false;
}

/////////////////////////////////////////////////////////////////////////////
void draw(){
    if (_displayorder == _traceLen) {
        return;
    }
    
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
//    cout << "trace x:" << tracepoints[_displayorder].x << endl;
    
//    GLfloat x = tracepoints[_displayorder].x / _width;
//    GLfloat y = 1.0 - tracepoints[_displayorder].y / _height;
//    GLfloat ra = 100.0 /_height;
//    GLfloat rb = 100.0 / _height;
    
    GLfloat x = tracepoints[_displayorder].x;
    GLfloat y = tracepoints[_displayorder].y;
    GLfloat ra = 10.0 ;
    GLfloat rb = 5.0 ;

    drawRect(x, y);
//    drawEllipse(x, y, ra, rb);
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
        GLfloat _x = floor(cos(degInRad) * ra + x);
        GLfloat _y = floor(sin(degInRad) * rb + y);
        //Check the coordiante
        cout << "-- x:" << _x << "  " << _y << endl;
        int vertindex = (int)_x * _width + _y;
        if (imgVertex[vertindex] == 1) {
            glVertex2f(_x / _width, 1- _y/_height);
        }
//        glVertex2f(_x, _y);
    }
}
/////////////////////////////////////////////////////////////////////////////
void drawRect(GLfloat x, GLfloat y){
    for (int i = x - 20; i < x + 20; i++) {
        for (int j = y - 20; j < y + 20; j++) {
//            if (raycasting(i, j, edgepoints, _edgeLen)) {
//                glVertex2f(i / _width, 1 - j / _height);
//            }
            if (imgVertex[(int)(x * _height + y)] == 1) {
                glVertex2f(i / _width, 1 - j / _height);
            }
        }
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
    
    // 1. Init all data
    init();
    // The gray color vertex
    imgVertex = getImgColorVert();
    
//    Mat src = imageprocess(source);
//    int w = src.cols;
//    int h = src.rows;
////    int *vert = (int *)malloc(w * h * sizeof(int));
//
//    for (int x = 0; x < w; x++) {
//        for (int y = 0; y < h; y++) {
//            //
//            Scalar color = src.at<char>(y, x);
//            if (color.val[0] != 0) {
//                imgVertex[x * w + y] = 0;
//            }else {
//                imgVertex[x * w + y] = 1;
//               
//            }
//        }
//    }

    int count = 0;
    for (int i = 0; i < 90000; i++) {
        if (imgVertex[i] == 1) {
            count++;
        }
//        cout << imgVertex[i] << endl;
    }
    cout << "The count:" << count << endl;
    
//    edgepoints = (CAPoint *)malloc(_edgeLen * sizeof(CAPoint));
//    tracepoints = (CAPoint *)malloc(_traceLen * sizeof(CAPoint));
    
    edgepoints = getEdgePoints();
    
    tracepoints = getTracePoints();
//    getEdge();
//    getTrace();
    
    // Check the edge data and trace data
//    cout << "Edge data" << endl;
//    for (int i = 0; i < _edgeLen; i++) {
//        cout << "x:" << edgepoints[i].x << " y:" << edgepoints[i].y << endl;
//    }
//    cout << " Trace data " << endl;
//    
//    for (int i = 0; i < _traceLen; i++) {
//        cout << "x: " << tracepoints[i].x << " y:" << tracepoints[i].y  << endl;
//    }
    cout << "---------------------------------------" << endl;
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
    
    free(imgVertex);
    free(edgepoints);
    free(tracepoints);
}