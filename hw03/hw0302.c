#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>

void wrongInputDetect(int64_t);
void numberOutput(int64_t, int8_t);
void printLine(int8_t);

int main(){
    int64_t number1 = 0, number2 = 0;
    printf("Please enter the first number: ");
    scanf("%ld", &number1);
    wrongInputDetect(number1);
    printf("Please enter the second number: ");
    scanf("%ld", &number2);
    wrongInputDetect(number2);
    int64_t sum = number1 + number2;
    if(sum > INT32_MAX){
        printf("\nOverflow!!!\n");
        printf("----------------------------------------------------------\n\n");
        exit(0);
    }
    int8_t sumdigit = (sum == 0 ? 1 : log10((double)sum) + 1);

    printf("   ");
    numberOutput(number1, sumdigit);
    printf("+) ");
    numberOutput(number2, sumdigit);
    printLine(sumdigit);
    printf("   ");
    numberOutput(sum, sumdigit);
    return 0;
}

void wrongInputDetect(int64_t num){
    if(num < 0 || num > INT32_MAX){
        printf("\nWrong Input!!!\n");
        printf("----------------------------------------------------------\n\n");
        exit(0);
    }
}

void numberOutput(int64_t num, int8_t sumdigit){
    int8_t bits[12] = {0}, numdigit = (num == 0 ? 1 : log10((double)num) + 1);
    for(int8_t i = 0; i < numdigit; i++){
        bits[i] = num % 10;
        num /= 10;
    }
    for(int i = 0; i < sumdigit - numdigit; i++){
        printf("  ");
    }
    for(int8_t i = numdigit - 1; i >= 0; i--){
        printf("%hhd ", bits[i]);
    }
    printf("\n");
}

void printLine(int8_t sumdigit){
    for(int i = 0; i < sumdigit * 2 + 2; i++){
        printf("-");
    }
    printf("\n");
}