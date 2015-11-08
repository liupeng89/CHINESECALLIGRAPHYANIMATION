//
//  FitCurve.hpp
//  FitCurve
//
//  Created by heermaster on 15/10/22.
//  Copyright © 2015年 heermaster. All rights reserved.
//

#ifndef FitCurve_hpp
#define FitCurve_hpp

#include <iostream>
#include <math.h>
#include <malloc/malloc.h>
#include "FitCurve.hpp"
using namespace std;

// Struct define
typedef struct Point2Struct {
    double x, y;
} Point2;

typedef Point2 Vector2;

typedef struct Point3Struct {
    double x, y, z;
} Vector3;

//typedef struct {
//    int dim, deg;
//    double **Q;
//} BezierCurve;

#define MAXPOINTS 1000

typedef Point2 *BezierCurve;

/* Forward declarations */
void FitCurve(Point2 *d,int nPts, double error);

static void FitCubic(Point2 *d, int first, int last, Vector2 tHat1, Vector2 tHat2, double error);

static double *Reparameterize(Point2 *d, int first, int last, double *u, BezierCurve bezCurve);

static double NewtonRaphsonRootFind(BezierCurve Q, Point2 P, double u);

static Point2 BezierII(int degree, Point2 *V, double t);

static double B0(double u),B1(double u),B2(double u),B3(double u);

static Vector2 ComputeLeftTangent(Point2 *d, int end);

static Vector2 ComputeRightTangent(Point2 *d, int end);

static Vector2 ComputeCenterTangent(Point2 *d, int center);

static double ComputeMaxError(Point2 *d, int first, int last, BezierCurve bezCurve, double *u, int *splitPoint);

static double *ChordLengthParameterize(Point2 *d, int first, int last);

static BezierCurve GenerateBezier(Point2 *d, int first, int last, double *uPrime,Vector2 tHat1, Vector2 tHat2);

static Vector2 V2AddII(Vector2 a,Vector2 b);

static Vector2 V2ScaleIII(Vector2 v, double s);

static Vector2 V2SubII(Vector2 a, Vector2 b);

static double V2SquareLength(Vector2 *a);

static double V2DistanceBetween2Points(Point2 *a, Point2 *b);
//static Vector2 *V2Normalize(Vector2 v);
static Vector2 *V2Normalize(Vector2 *v);

static double V2SquareLength(Vector2 *a);

double V2SquaredLength(Vector2 *a);

double V2Length(Vector2 *a);

Vector2 *V2Scale(Vector2 *v, double newLen);

double V2Dot(Vector2 *a, Vector2 *b);

Vector2 *V2Add(Vector2 *a, Vector2 *b, Vector2 *c);

Vector2 *V2Negate(Vector2 *v);


/* Draw the Bezier Curve */
void DrawBezierCurve(int n, BezierCurve curve);

#endif /* FitCurve_hpp */
