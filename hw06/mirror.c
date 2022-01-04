#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include "mirror.h"

//y = mx + c
bool allow = false;
double a = 0, b = 0, c = 0, _a = 0, _b = 0, _c = 0, m = 0;

void set_line( double x1, double y1, double x2, double y2 ){
    if(x1 == x2 && y1 == y2){
        return;
    }
    a = y2 - y1;
    b = -(x2 - x1);
    c = -a * x1 - b * y1;
    m = sqrt(a * a + b * b);
    _a = a / m;
    _b = b / m;
    _c = c / m;
    allow = true;
    return ;
}

int32_t get_mirror( double x, double y, double *r_x, double *r_y ){
    if(allow == false){
        return -1;
    }
    double d = _a * x + _b * y + _c;
    *r_x = x - 2 * _a * d;
    *r_y = y - 2 * _b * d;
    return 0;
}