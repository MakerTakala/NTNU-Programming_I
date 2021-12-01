#include <stdio.h>
#include <stdint.h>
#include "poker.h"

int main(){
    int8_t cards[13] = {0};
    for(int i = 0; i < 13; i++){
        scanf("%hhd", &cards[i]);
    }
    big_two_sort(cards);
    for(int i = 0; i < 13; i++){
        printf("%hhd ", cards[i]);
    }
    return 0;
}