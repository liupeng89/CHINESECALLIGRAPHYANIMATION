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

using namespace std;

int discount = 0;
const int pathLen = 20;

typedef float GLfloat;
typedef int GLint;

GLfloat gfPosX = 0.25;
GLfloat gfDeltaX = 0.005;
GLfloat fontSizeDelta = 0.001;
GLfloat fontSize = 0.01;
const float DEG2RAD = 3.14159 / 180.0;


struct PathElement {
    float x,y;
    float ra,rb;
};


void DrawCircle(float cx, float cy, float r, int num_segments);
void DrawEllipse(PathElement element);
void DrawEllipse();
void Timer(int iUnused);
void Initialize();
void drawEllipse(float dx, float dy, float xradius, float yradius);

/*
    Draw the ellipse object.
 */
void Draw() {

    glColor3f(1.0, 0.0, 1.0);
    glBegin(GL_TRIANGLE_FAN);
    
    struct PathElement paths[pathLen];
    for (int i=0; i<pathLen; i++) {
        paths[i].x = gfPosX + i * 0.001;
        paths[i].y = 0.25;
        paths[i].ra = 0.005;
        paths[i].rb = fontSize + i * fontSizeDelta;
    }
    
    drawEllipse(paths[discount].x, paths[discount].y, paths[discount].ra, paths[discount].rb);
    if (discount < pathLen) {
        discount++;
    }
    cout<< discount << endl;
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
}

int main(int argc, char** argv) {

    /* OpenGL Animation */
    
    struct PathElement path[10];

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




