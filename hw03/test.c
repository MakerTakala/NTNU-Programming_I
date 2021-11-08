#include <stdio.h>
#include <stdint.h>
int main(){
    int32_t a;
    float b = NaN;
    a = b;
    printf("%d\n", a);
    printf("%f\n", b);
    return 0;
}