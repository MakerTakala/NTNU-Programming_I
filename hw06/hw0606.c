#include <stdio.h>

int main(){
    int N1, N2;
    printf("123%n456\n%n", &N1, &N2);
    printf("%d %d\n", N1, N2);
    return 0;
}