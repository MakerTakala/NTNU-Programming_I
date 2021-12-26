#pragma once
#include <stdint.h>

typedef struct{
    double x;
    double y;
}point;

// Use (x1,y1) and (x2,y2) to determine a line.
// If the input is not a valid line , use previous valid one.
void set_line( double , double , double , double  );

// Q(c,d) is the mirror of P(a,b) according to the pre-determined line.
// If there is no valid line , return -1; otherwise , return 0.
int32_t get_mirror( double , double , double *, double * );