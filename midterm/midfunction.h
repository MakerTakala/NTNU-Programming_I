#ifndef MIDFUNCTION_H_INCLUDE
#define MIDFUNCTION_H_INCLUDE

#include <stdint.h>

typedef struct{
    double x;
    double y;
}point;

typedef struct{
    point p1;
    point p2;
}line;

void errorMessageExit(char []);
void askInput(char [], int64_t* );
double get_slope(line l);
point get_intersection(line l1, line l2);

#endif