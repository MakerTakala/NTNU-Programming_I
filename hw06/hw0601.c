#include <stdio.h>
#include <stdint.h>
#include "mirror.h"

int main(){
    double x1, y1, x2, y2, x, y, ans_x, ans_y;
    scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x, &y);
    set_line(x1, y1, x2, y2);
    get_mirror(x, y, &ans_x, &ans_y);
    printf("%lf %lf\n", ans_x, ans_y);
    return 0;
}