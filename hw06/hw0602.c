#include <stdio.h>
#include <stdint.h>
#include "ext.h"

int main(){
    uint32_t a, b, c;
    scanf("%u %u", &a, &b);
    printf("ext_euclidean : %d\n", ext_euclidean(a, b, &c));
    printf("%u %u %u", a, b, c);
    return 0;
}