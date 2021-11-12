#ifndef MIDFUNCTION_H_INCLUDE
#define MIDFUNCTION_H_INCLUDE

#include <stdint.h>

void errorMessageExit(char []);
void askInput(char [], int64_t* );

typedef struct{
    long double x;
    long double y;
}point;

typedef struct{
    point p1;
    point p2;
}line;

long double getSlope(line);
point getIntersection(line, line);

#endif