#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "hw04fuc.h"

//general
void errorMessageExit(char message[]){
    printf("\n%s\n", message);
    printf("----------------------------------------------------------\n\n");
    exit(0);
}

void askInput(char message[], int64_t* input){
    printf("%s", message);
    scanf("%ld", input);
}

//hw0401
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

//hw0402
void hanoi_recur(int64_t n, int8_t now, int8_t next, int8_t temp, int64_t disk){
    if(n == 1){
        printf("move disk %ld to rod %hhd\n", disk, next);
        return;
    }
    hanoi_recur(n - 1, now, temp, next, disk - 1);
    hanoi_recur(1, now, next, temp, disk);
    hanoi_recur(n - 1, temp, next, now, disk - 1);
}

void hanoi_loop(int64_t n){
    rod rod1 = initRod(1, n, 1), rod2 = initRod(2, n, 0), rod3 = initRod(3, n, 0);
    int64_t move = power(2, n) - 1;
    if(n % 2 == 0){
        for(int i = 0; i < move; i++){
            if(i % 3 == 0){
                transformDisk(&rod1, &rod3);
            }
            else if(i % 3 == 1){
                transformDisk(&rod1, &rod2);
            }
            else if(i % 3 == 2){
                transformDisk(&rod2, &rod3);
            }
        }
    }
    else{
        for(int i = 0; i < move; i++){
            if(i % 3 == 0){
                transformDisk(&rod1, &rod2);
            }
            else if(i % 3 == 1){
                transformDisk(&rod1, &rod3);
            }
            else if(i % 3 == 2){
                transformDisk(&rod2, &rod3);
            }
        }
    }
    
}

void transformDisk(rod* rodx, rod* rody){
    if(rody -> top == -1){
        printf("move disk %hhd to rod %hhd\n", rodx -> disk[rodx -> top], rody -> status);
        rody -> disk[++(rody -> top)] = rodx -> disk[rodx -> top];
        (rodx -> top)--;
        return;
    }
    if(rodx -> top == -1){
        printf("move disk %hhd to rod %hhd\n", rody -> disk[rody -> top], rodx -> status);
        rodx -> disk[++(rodx -> top)] = rody -> disk[rody -> top];
        (rody -> top)--;
        return;
    }
    if( (rodx -> disk[rodx -> top]) < (rody -> disk[rody -> top]) ){
        printf("move disk %hhd to rod %hhd\n", rodx -> disk[rodx -> top], rody -> status);
        rody -> disk[++(rody -> top)] = rodx -> disk[rodx -> top];
        (rodx -> top)--;
        return;
    }
    else{
        printf("move disk %hhd to rod %hhd\n", rody -> disk[rody -> top], rodx -> status);
        rodx -> disk[++(rodx -> top)] = rody -> disk[rody -> top];
        (rody -> top)--;
        return;
    }
}

rod initRod(int8_t s,int8_t n, int8_t stuff){
    rod tmprod;
    tmprod.status = s;
    if(stuff == 1){
        tmprod.top = n - 1;
        for(int i = 1; i <= n; i++){
            tmprod.disk[i - 1] = n - i + 1;
        }
    }
    else{
        tmprod.top = -1;
    }
    return tmprod;
}

int64_t power(int64_t base, int64_t times){
    if(base == 0){
        return 0;
    }
    if(times == 0){
        return 0;
    }
    
    for(int i = 1, tmpbase = base; i < times; i++){
        base *= tmpbase;
    }
    return base;
}

//hw0404
long double countResistance(int64_t r, int64_t n){
    long double ans = 2 * r;
    for(int i = 1; i < n; i++){
        ans = (ans * r) / (ans + r) + r;
    }
    return ans;
}