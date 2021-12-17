#include <stdint.h>
#include <stdlib.h>
#include "poker.h"

int32_t big_two_sort( int8_t cards[] ){
    for(int i = 0 ; i < 13; i++){
        if(cards[i] < 1 || 52 < cards[i]){
            return -1;
        }
    }
    qsort(cards, 13, sizeof(int8_t), compare);
    return 0;
}

int compare(const void * arg1, const void * arg2){
    int8_t point1 = (*(int8_t*)arg1 - 1) % 13, point2 = (*(int8_t*)arg2 - 1) % 13;
    static int8_t biggerTable[13] = {12, 13, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    if(biggerTable[point1] > biggerTable[point2]){
        return 1;
    }
    else if(biggerTable[point1] == biggerTable[point2]){
        int8_t suit1 = (*(int8_t*)arg1 - 1) / 13, suit2 = (*(int8_t*)arg2 - 1) / 13; 
        return (suit1 > suit2 ? 1 : -1);
    }
	return -1;
}