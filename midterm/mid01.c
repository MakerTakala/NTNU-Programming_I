#include <stdio.h>
#include <stdint.h>
#include "midfunction.h"

int main(){
    point s1 = {121, 64839};
    point s2 = {14214, 142};
    line l1 = {s1, s2};
    printf("%Lf", get_slope(l1) );
    return 0;
}