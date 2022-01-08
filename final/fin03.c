#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include "frac.h"

int main(){
    srandom(time(0));
    int a = -random() % 11;
    srandom(random());
    int b = -random() % 11;
    srandom(random());
    int c = -random() % 11;
    srandom(random());
    int d = -random() % 11;
    int x, y;
    printf("%d %d %d %d\n",a, b, c, d);
    frac_add(&x, &y, a, b, c, d);
    printf("%d %d\n", x, y);
    frac_del(&x, &y, a, b, c, d);
    printf("%d %d\n", x, y);
    frac_mul(&x, &y, a, b, c, d);
    printf("%d %d\n", x, y);
    frac_div(&x, &y, a, b, c, d);
    printf("%d %d\n", x, y);
    
    return 0;
}