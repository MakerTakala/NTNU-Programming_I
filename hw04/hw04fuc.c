#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void errorMessageExit(char message[]){
    printf("\n%s\n", message);
    printf("----------------------------------------------------------\n\n");
    exit(0);
}

void askInput(char message[], int64_t* input){
    printf("%s", message);
    scanf("%ld", input);
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

void hanoi_recur(int64_t n, int8_t now, int8_t next, int8_t temp, int64_t disk){
    if(n == 1){
        printf("move disk %ld form %hhd to rod %hhd\n", disk, now, next);
        return;
    }
    hanoi_recur(n - 1, now, temp, next, disk - 1);
    hanoi_recur(1, now, next, temp, disk);
    hanoi_recur(n - 1, temp, next, now, disk - 1);
}

void hanoi_loop(int64_t n){
    
}

long double countResistance(int64_t r, int64_t n){
    long double ans = 2 * r;
    for(int i = 1; i < n; i++){
        ans = (ans * r) / (ans + r) + r;
    }
    return ans;
}