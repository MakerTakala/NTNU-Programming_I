#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "polynomial.h"

void ask_degree_input( char message [], int64_t* input){
    printf("%s", message);
    scanf("%ld", input);
    if( (*input) < 1 || 100 < (*input) ){
        printf("\n\nWrong Input!\n");
        printf("-----------------------------------\n");
        exit(0);
    }
}

void ask_array_input( char message [], int64_t arr [], size_t degree){
    printf("%s", message);
    for(int i = degree; i >= 0; i--){
        scanf("%ld", &arr[i]);
    }
    if(arr[degree] == 0){
        printf("\n\nWrong Input!\n");
        printf("-----------------------------------\n");
        exit(0);
    }
}

void print_polynomial(int64_t coefficient [], int64_t degree){
    while(coefficient[degree] == 0){
        degree--;
    }
    if(degree == -1){
        printf("0\n");
        return ;
    }
    for(int i = degree; i >= 0; i--){
        if(coefficient[i] == 0){
            continue;
        }
        if(i == degree){
            if(coefficient[i] < 0){
                printf("-");
            }
        }
        else{
            printf("%s", coefficient[i] > 0 ? " + " : " - ");
        }
        if(abs(coefficient[i]) != 1 || (abs(coefficient[i]) == 1 && i == 0) ){
            printf("%d", abs(coefficient[i]));
        }
        if(i != 0){
            printf("x");
        }
        if(i != 1 && i != 0){
            printf("^");
        }
        if(i >= 2){
            printf("%d", i);
        }
    }
    printf("\n");
}

void add( int64_t p1Coefficient [], int64_t p2Coefficient [], int64_t degree ){
    int64_t ans[degree];
    for(int i = 0; i <= degree; i++){
        ans[i] = p1Coefficient[i] + p2Coefficient[i];
    }
    printf("p1 + p2: ");
    print_polynomial(ans, degree);
}

void sub( int64_t p1Coefficient [], int64_t p2Coefficient [], int64_t degree ){
    int64_t ans[degree];
    for(int i = 0; i <= degree; i++){
        ans[i] = p1Coefficient[i] - p2Coefficient[i];
    }
    printf("p1 - p2: ");
    print_polynomial(ans, degree);
}

void mul( int64_t p1Coefficient [], int64_t p2Coefficient [], int64_t degree1, int64_t degree2 ){
    int64_t degree = degree1 + degree2;
    int64_t ans[degree + 1];
    for(int i = 0 ; i <= degree; i++){
        ans[i] = 0;
    }
    for(int i = 0; i <= degree1; i++){
        for(int j = 0; j <= degree2; j++){
            ans[i + j] += p1Coefficient[i] * p2Coefficient[j];
        }
    }
    printf("p1 * p2: ");
    print_polynomial(ans, degree);
}