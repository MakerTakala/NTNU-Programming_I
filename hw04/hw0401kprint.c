#include <stdio.h>
#include <stdint.h>
#include "askinput_exit.h"

void wrongInputDectect(int64_t n){
    if(n < 1 || n % 2 == 0){
        errorMessageExit("Wrong Input!");
    }
}

void kprint(int64_t n){
    for(int i = n / 2; i > 0; i--){
        printf("*");
        for(int j = i - 1; j > 0; j--){
            printf(" ");
        }
        printf("*\n");
    }
    printf("*\n");
    for(int i = 1; i <= n / 2 ; i++){
        printf("*");
        for(int j = i - 1; j > 0; j--){
            printf(" ");
        }
        printf("*\n");
    }
}