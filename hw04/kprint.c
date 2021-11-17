#include <stdio.h>
#include <stdint.h>

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