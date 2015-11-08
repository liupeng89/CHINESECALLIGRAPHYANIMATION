//
//  main.cpp
//  OpenCVTutorials
//
//  Created by PeterLiu on 10/12/15.
//  Copyright © 2015 PeterLiu. All rights reserved.
//

#include <iostream>
//#include "ImgProcess.hpp"
//#include "FitCurve.hpp"
//#include "ThinningProcess.hpp"
#include <GLUT/GLUT.h>
#include <math.h>

#include "MlddleLineProcess.hpp"

using namespace std;

int discount = 0;
const int pathLen = 460;

typedef float GLfloat;
typedef int GLint;

#define sizeofa(array) sizeof array / sizeof array[0]

GLfloat gfPosX = 0.25;
GLfloat gfDeltaX = 0.005;
GLfloat fontSizeDelta = 0.001;
GLfloat fontSize = 0.00;
const float DEG2RAD = 3.14159 / 180.0;

struct PathElement {
    float x,y;
    float ra,rb;
};
// Paths array
struct PathElement paths[241];

void DrawCircle(float cx, float cy, float r, int num_segments);
void DrawEllipse(PathElement element);
void DrawEllipse();
void Timer(int iUnused);
void Initialize();
void drawEllipse(float dx, float dy, float xradius, float yradius);
void initPath();

/*
    Draw the ellipse object.
 */
void Draw() {

    glColor3f(1.0, 0.0, 1.0);
    glBegin(GL_TRIANGLE_FAN);
    
    drawEllipse(paths[discount].x, paths[discount].y, paths[discount].ra, paths[discount].rb);
    if (discount < pathLen) {
        discount++;
    }
    cout<< discount << endl;
    cout << paths[discount].x << ":" << paths[discount].y << ":" << paths[discount].ra << ":" << paths[discount].rb << endl;
    glEnd();
    glFlush();
}

/* Draw the ellipse */
void drawEllipse(float dx, float dy, float xradius, float yradius)
{
    for (int i = 0; i<360; i++) {
        float degInRad = i * DEG2RAD;
        glVertex2f(cos(degInRad)*xradius + dx, sin(degInRad)*yradius + dy);
    }
    
}

/*Timer function*/
void Timer(int iUnused)
{
    glutPostRedisplay();
    glutTimerFunc(100, Timer, 0);
}

void Initialize() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
   
    // Init the paths
    initPath();
    
}

/* Init the paths array */
void initPath()
{
    
    // Load image
    middleLine();
    
    FILE *fr = fopen("/Users/peterliu/Documents/openDevelopment/path.txt", "r");
    int index = 0;
    
    float pointx, pointy, ra, rb;
    
    while (fscanf(fr, "%f %f %f %f", &pointx, &pointy, &ra, &rb) == 4) {
        cout << pointx << ":" << pointy << ":"  << ra << ":"  << rb << endl;
        paths[index].x = pointx / 500.0;
        paths[index].y = 1 - pointy / 500.0;
        
        paths[index].ra = ra / 1000.0;
        paths[index].rb = rb / 1000.0;
        index++;
    }
    
//    for (int i = 0; i < l; i++) {
//        // convert
//        paths[i].x = temp[i].x / 300.0;
//        paths[i].y = temp[i].y / 300.0;
//        paths[i].ra = temp[i].ra / 1000.0;
//        paths[i].rb = temp[i].rb / 1000.0;
//        cout <<temp[i].x << ":" <<temp[i].y <<":"<< temp[i].ra <<":"<< temp[i].rb <<endl;
//    }
    
    // Data convertation.
//    int len = 50; // Hard code , need to modify.
//    
//    if (len == 0) {
//        return;
//    }
//    cout << "len:" << len << endl;
//    PathElement p[len];
//    
//    for (int i = 0; i < len; i++) {
//        MiddleLineElement m = middle[i];
//        
//        p[i].x = m.x / 300.0;
//        p[i].y = m.y / 300.0;
//        p[i].ra = m.ra / 1000.0;
//        p[i].rb = m.rb / 1000.0;
//        cout << m.x << ":" << m.y << ":"<< m.ra << ":" << m.rb << endl;
////        cout << p[i].x << ":" << p[i].y << ":"<< p[i].ra << ":" << p[i].rb << endl;
//    }
//    
//    paths = p;
}

int main(int argc, char** argv) {

    /* OpenGL Animation */
    

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(900, 800);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("XoaX.net");
    Initialize();
    glutDisplayFunc(Draw);
    Timer(0);
    glutMainLoop();
    
    return 0;

}




