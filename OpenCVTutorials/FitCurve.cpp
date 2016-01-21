//
//  FitCurve.cpp
//  FitCurve
//
//  Created by heermaster on 15/10/22.
//  Copyright © 2015年 heermaster. All rights reserved.
//

#include "FitCurve.hpp"

/* Draw the Bezier Curve */
void DrawBezierCurve(int n, BezierCurve curve){
    
    /* Determine the method of draw the Bezier Curve */
//    cout<< curve[2].x << endl;
    int index = 0;
    while (curve[index].x >= 0.0 && curve[index].x <= 300) {
        cout << "Index: " << index << "  " << curve[index].x << " " << curve[index].y << endl;
        index++;
    }
    
}

/*fit curve*/
void FitCurve(Point2 *d, int nPts, double error){
    Vector2 tHat1, tHat2;
    tHat1 = ComputeLeftTangent(d, 0);
    tHat2 = ComputeRightTangent(d, nPts-1);
    FitCubic(d, 0, nPts-1, tHat1, tHat2, error);
}


/* fit cubic*/
static void FitCubic(Point2 *d, int first, int last, Vector2 tHat1, Vector2 tHat2, double error){
    BezierCurve bezCurve;
    double *u;
    double *uPrime;
    double maxError;
    int splitPoint;
    int nPts;
    double iterationError;
    int maxIterations = 4;
    Vector2 tHatCenter;
    int i;
    
    iterationError = error * error;
    
    nPts = last - first + 1;
    /*use heuristic if region only has two points in it*/
    if (nPts == 2) {
        double dist = V2DistanceBetween2Points(&d[last], &d[first]) / 3.0;
        bezCurve = (Point2 *)malloc(4 * sizeof(Point2));
        bezCurve[0] = d[first];
        bezCurve[3] = d[last];
        V2Add(&bezCurve[0], V2Scale(&tHat1, dist), &bezCurve[1]);
        V2Add(&bezCurve[3], V2Scale(&tHat2, dist), &bezCurve[2]);
        DrawBezierCurve(3, bezCurve);
        free((void *)bezCurve);
        return;
    }
    
    /*parameterize points and attempt to fit curve*/
    u = ChordLengthParameterize(d, first, last);
    bezCurve = GenerateBezier(d, first, last, u, tHat1, tHat2);
    
    /*find max deviation of points to fitted curve*/
    maxError = ComputeMaxError(d, first, last, bezCurve, u, &splitPoint);
    
    if (maxError < error) {
        DrawBezierCurve(3, bezCurve);
        free((void *)u);
        free((void *)bezCurve);
        return;
    }
    
    /*if error not too large try some reparameterization*/
    if (maxError < iterationError) {
        for (i = 0; i < maxIterations; i++) {
            uPrime = Reparameterize(d, first, last, u, bezCurve);
            bezCurve = GenerateBezier(d, first, last, uPrime, tHat1, tHat2);
            maxError = ComputeMaxError(d, first, last, bezCurve, uPrime, &splitPoint);
            if (maxError < error) {
                DrawBezierCurve(3, bezCurve);
                free((void *)u);
                free((void *)bezCurve);
                return;
            }
            free((void *)u);
            u = uPrime;
        }
    }
    
    /*failed*/
    free((void *)u);
    free((void *)bezCurve);
    tHatCenter = ComputeCenterTangent(d, splitPoint);
    FitCubic(d, first, splitPoint, tHat1, tHatCenter, error);
    V2Negate(&tHatCenter);
    FitCubic(d, splitPoint, last, tHatCenter, tHat2, error);
    
}

/* Generate Bezier curve */
static BezierCurve GenerateBezier(Point2 *d, int first, int last, double *uPrime, Vector2 tHat1, Vector2 tHat2){
    int i;
    Vector2 A[MAXPOINTS][2];
    int nPts;
    double C[2][2];
    double X[2];
    double det_C0_C1, det_C0_X, det_X_C1;
    
    double alpha_1, alpha_r;
    Vector2 tmp;
    BezierCurve bezCurve;
    
    bezCurve = (Point2 *)malloc(4 * sizeof(Point2));
    nPts = last - first + 1;
    
    /* Compute the A's */
    for (i = 0; i < nPts; i++) {
        Vector2 v1, v2;
        v1 = tHat1;
        v2 = tHat2;
        
        V2Scale(&v1, B1(uPrime[i]));
        V2Scale(&v2, B2(uPrime[i]));
        A[i][0] = v1;
        A[i][1] = v2;
    }
    
    /* create the C and X matrices */
    C[0][0] = 0.0;
    C[0][1] = 0.0;
    C[1][0] = 0.0;
    C[1][1] = 0.0;
    X[0] = 0.0;
    X[1] = 0.0;
    
    for (i = 0; i < nPts; i++) {
        C[0][0] += V2Dot(&A[i][0], &A[i][0]);
        C[0][1] += V2Dot(&A[i][0], &A[i][1]);
        C[1][0] = C[0][1];
        C[1][1] += V2Dot(&A[i][1], &A[i][1]);
        
        tmp = V2SubII(d[first+i],V2AddII(V2ScaleIII(d[first], B1(uPrime[i])), V2AddII(V2ScaleIII(d[last], B2(uPrime[i])), V2ScaleIII(d[last], B3(uPrime[i])))));
        
        X[0] += V2Dot(&A[i][0], &tmp);
        X[1] += V2Dot(&A[i][1], &tmp);
        
    }
    
    /*compute the determinants of C and X*/
    det_C0_C1 = C[0][0] * C[1][1] - C[1][0] * C[0][1];
    det_C0_X = C[0][0] * X[1] - C[0][1] * X[0];
    det_X_C1 = X[0] * C[1][1] - X[1] * C[0][1];
    
    /*Finally  derive alpha values*/
    if (det_C0_C1 == 0.0) {
        det_C0_C1 = (C[0][0] * C[1][1]) * 10e-12;
    }
    
    alpha_1 = det_X_C1 / det_C0_C1;
    alpha_r = det_C0_X / det_C0_C1;
    
    if (alpha_1 < 1.0e-6 || alpha_r < 1.0e-6) {
        double dist = V2DistanceBetween2Points(&d[last], &d[first]) / 3.0;
        bezCurve[0] = d[first];
        bezCurve[3] = d[last];
        V2Add(&bezCurve[0], V2Scale(&tHat1, dist), &bezCurve[1]);
        V2Add(&bezCurve[3], V2Scale(&tHat2, dist), &bezCurve[2]);
        return bezCurve;
    }
    
    bezCurve[0] = d[first];
    bezCurve[3] = d[last];
    V2Add(&bezCurve[0], V2Scale(&tHat1, alpha_1), &bezCurve[1]);
    V2Add(&bezCurve[3], V2Scale(&tHat2, alpha_r), &bezCurve[2]);
    
    
    return bezCurve;
}



/* Reparameterize */
static double *Reparameterize(Point2 *d, int first, int last, double *u, BezierCurve bezCurve){
    int nPts = last - first + 1;
    int i;
    double *uPrime;
    
    uPrime = (double *)malloc(nPts * sizeof(Point2));
    for (i = first; i <= last; i++) {
        uPrime[i-first] = NewtonRaphsonRootFind(bezCurve, d[i], u[i-first]);
    }
    
    return uPrime;
}



/*
 Newton-Raphson Root Find
 */
static double NewtonRaphsonRootFind(BezierCurve Q, Point2 P, double u){
    double numerator, denominator;
    Point2 Q1[3], Q2[2];
    Point2 Q_u, Q1_u, Q2_u;
    double uPrime;
    int i;
    
    /* Compute Q(u) */
    Q_u = BezierII(3, Q, u);
    
    /*Generate control vertices for Q' */
    for (i = 0; i <= 2; i++) {
        Q1[i].x = (Q[i+1].x - Q[i].x) * 3.0;
        Q1[i].y = (Q[i+1].y - Q[i].y) * 3.0;
    }
    
    /*Generate control vertices for Q''*/
    for (i = 0; i <= 1; i++) {
        Q2[i].x = (Q1[i+1].x - Q1[i].x) * 2.0;
        Q2[i].y = (Q1[i+1].y - Q1[i].y) * 2.0;
    }
    
    /* Compute Q'(u)and Q'' (u) */
    Q1_u = BezierII(2, Q1, u);
    Q2_u = BezierII(1, Q2, u);
    
    /* compute f(u)/ f'(u) */
    numerator = (Q_u.x - P.x) * (Q1_u.x) + (Q_u.y - P.y) * (Q1_u.y);
    denominator = Q1_u.x * Q1_u.x + Q1_u.y * Q1_u.y + (Q_u.x - P.x) * Q2_u.x + (Q_u.y - P.y) * Q2_u.y;
    
    /* u = u - f(u) / f'(u) */
    uPrime = u - numerator / denominator;
    
    return uPrime;
}


/*
 Bezier II
 */
static Point2 BezierII(int degree, Point2 *V, double t){
    int i,j;
    Point2 Q;
    Point2 *Vtemp;
    Vtemp = (Point2 *)malloc((unsigned)((degree + 1) * sizeof(Point2)));
    
    for (i = 1; i <= degree; i++) {
        Vtemp[i] = V[i];
    }
    
    /*Triangle computation*/
    
    for (i = 1; i <= degree; i++) {
        for (j = 0; j<=degree-i; j++) {
            Vtemp[j].x = (1.0 - t) * Vtemp[j].x + t * Vtemp[j + 1].x;
            Vtemp[j].y = (1.0 - t) * Vtemp[j].y + t * Vtemp[j + 1].y;
        }
    }
    Q = Vtemp[0];
    free((void *)Vtemp);
    
    return Q;
}


/*
 B0, B1,B2,B3
 */
static double B0(double u){
    double tmp = 1.0 - u;
    return (tmp * tmp * tmp);
}

static double B1(double u){
    double tmp = 1.0 - u;
    return (3 * u * (tmp * tmp));
}

static double B2(double u){
    double tmp = 1.0 - u;
    return (3 * u * u * tmp);
}

static double B3(double u){
    return u * u * u;
}


/*
 Left ,Right ,Center tangent
 */
static Vector2 ComputeLeftTangent(Point2 *d, int end){
    Vector2 tHat1;
    tHat1 = V2SubII(d[end+1], d[end]);
    tHat1 = *V2Normalize(&tHat1);
    return tHat1;
}
static Vector2 ComputeRightTangent(Point2 *d, int end){
    Vector2 tHat2;
    
    tHat2 = V2SubII(d[end-1], d[end]);
    tHat2 = *V2Normalize(&tHat2);
    
    return tHat2;
}
static Vector2 ComputeCenterTangent(Point2 *d, int center){
    Vector2 V1, V2, tHatCenter;
    
    V1 = V2SubII(d[center-1], d[center]);
    V2 = V2SubII(d[center], d[center+1]);
    tHatCenter.x = (V1.x + V2.x) / 2.0;
    tHatCenter.y = (V1.y + V2.y) / 2.0;
    tHatCenter = *V2Normalize(&tHatCenter);
    
    return tHatCenter;
}



/*
 ChordLengthParameterize:
 */
static double *ChordLengthParameterize(Point2 *d, int first, int last){
    int i;
    double *u;
    
    u = (double *)malloc((unsigned)(last - first + 1) * sizeof(Point2));
    u[0] = 0.0;
    for (i = first + 1; i <= last; i++) {
        u[i - first] = u[i-first-1] + V2DistanceBetween2Points(&d[i], &d[i-1]);
        
    }
    
    for ( i = first + 1; i <= last; i++) {
        u[i-first] = u[i-first]/ u[last - first];
    }
    
    return(u);
}


/*
 Compute the Max Error
 */

static double ComputeMaxError(Point2 *d, int first, int last, BezierCurve bezierCurve, double *u, int *splitPoint){
    int i;
    double maxDist;
    double dist;
    Point2 P;
    Vector2 v;
    
    *splitPoint = (last - first + 1) / 2;
    
    maxDist = 0.0;
    for (i = first + 1; i < last; i++) {
        P = BezierII(3, bezierCurve, u[i - first]);
        v = V2SubII(P, d[i]);
        dist = V2SquareLength(&v);
        if (dist >= maxDist) {
            *splitPoint = i;
        }
    }
    return maxDist;
}

Vector2 *V2Add(Vector2 *a, Vector2 *b, Vector2 *c){
    c->x = a->x + b->x;
    c->y = a->y + b->y;
    return c;
}

Vector2 *V2Scale(Vector2 *v, double newLen){
    double len = V2Length(v);
    if (len != 0.0) {
        v->x *= (newLen / len);
        v->y *= (newLen / len);
    }
    return v;
}

static Vector2 *V2Normalize(Vector2 *v){
    double len = V2Length(v);
    if (len != 0.0) {
        v->x /= len; v->y /= len;
    }
    return(v);
}

static double V2DistanceBetween2Points(Point2 *a, Point2 *b){
    double dx = a->x - b->x;
    double dy = a->y - b->y;
    return sqrt((dx*dx)+(dy*dy));
}

static double V2SquareLength(Vector2 *a){
    return ((a->x * a->x) + (a->y * a->y));
}

double V2SquaredLength(Vector2 *a){
    return ((a->x * a->x) + (a->y * a->y));
}

double V2Length(Vector2 *a){
    return (sqrt(V2SquaredLength(a)));
}

double V2Dot(Vector2 *a, Vector2 *b){
    return ((a->x * b->x) + (a->y * b->y));
}

Vector2 *V2Negate(Vector2 *v){
    v->x = -v->x;
    v->y = -v->y;
    return v;
}


static Vector2 V2AddII(Vector2 a, Vector2 b){
    Vector2 c;
    c.x = a.x + b.x;
    c.y = a.y + b.y;
    return c;
}

static Vector2 V2ScaleIII(Vector2 v, double s){
    Vector2 result;
    result.x = v.x * s;
    result.y = v.y * s;
    return result;
}

static Vector2 V2SubII(Vector2 a, Vector2 b){
    Vector2 c;
    c.x = a.x - b.x;
    c.y = a.y - b.y;
    return c;
}
