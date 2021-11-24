#include <stdio.h>

int main(){
    int a = 0, b = 0, c = 0;
    int input = scanf("%d %d %d", &a, &b, &c);
    int output = printf("%d %d %d\n", a, b, c);
    printf("input: %d \noutput: %d\n", input, output);

    return 0;
}