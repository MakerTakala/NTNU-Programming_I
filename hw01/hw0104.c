#include <stdio.h>

int main(){
    float v_0 = 0, a = 0, t = 0;
    printf("v_0: ");
    scanf("%f", &v_0);
    printf("a: ");
    scanf("%f", &a);
    printf("t: ");
    scanf("%f", &t);
    printf("--> s = %f\n", v_0 * t + a * t * t * 0.5);
    return 0;
}