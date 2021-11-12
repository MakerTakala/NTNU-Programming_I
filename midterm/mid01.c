#include <stdio.h>
#include <stdint.h>
#include "midfunction.h"

int main(){
    int x1 = 121, y1 = 3412, x2 = 1412, y2 = 124124;
    point s1 = {x1, y1};
    point s2 = {x2, y2};
    line l1 = {s1, s2};
    printf("%Lf", getSlope(l1) );
    return 0;
}