#include <stdio.h>
#include <stdint.h>

int main(){
    int16_t num1 = 0, num2 = 0;
    printf("Please enter the first  number: ");
    scanf("%hd", &num1);
    printf("Please enter the second number: ");
    scanf("%hd", &num2);

    int sum = num1 + num2;
    printf("   %hd %hd %hd\n", num1 / 100, num1 / 10 % 10, num1 % 10);
    printf("+) %hd %hd %hd\n", num2 / 100, num2 / 10 % 10, num2 % 10);
    printf("--------\n");
    printf(" %s %d %d %d\n", sum < 1000 ? " " : "1", sum / 100 % 10, sum / 10 % 10, sum % 10);
    return 0;
}