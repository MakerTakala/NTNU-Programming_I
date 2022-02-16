#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include "frac.h"

int32_t gcd(int32_t a, int32_t b){
    if(a % b == 0){
        return b;
    }
    return gcd(b, a % b);
}

void about(int32_t *x, int32_t *y){
    int32_t g = gcd(abs(*x), abs(*y));
    if((*x) == 0){
        (*y) =1;
        return;
    }
    (*x) /= g;
    (*y) /= g;
    if((*y) < 0){
        (*x) = -(*x);
        (*y) = -(*y);
        return;
    }
}

int32_t frac_add( int32_t *x, int32_t *y, int32_t a, int32_t b, int32_t c, int32_t d ){
    if(b == 0 || d == 0){
        return -1;
    }
    (*x) = a * d + b * c;
    (*y) = b * d;
    about(x, y);
    return 0;
}

int32_t frac_del( int32_t *x, int32_t *y, int32_t a, int32_t b, int32_t c, int32_t d ){
    if(b == 0 || d == 0){
        return -1;
    }
    (*x) = a * d - b * c;
    (*y) = b * d;
    about(x, y);
    return 0;
}

int32_t frac_mul( int32_t *x, int32_t *y, int32_t a, int32_t b, int32_t c, int32_t d ){
    if(b == 0 || d == 0){
        return -1;
    }
    (*x) = a * c;
    (*y) = b * d;
    about(x, y);
    return 0;
}

int32_t frac_div( int32_t *x, int32_t *y, int32_t a, int32_t b, int32_t c, int32_t d ){
    if(b == 0 || c == 0 || d == 0){
        return -1;
    }
    (*x) = a * d;
    (*y) = b * c;
    about(x, y);
    return 0;
}