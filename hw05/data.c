#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <math.h>
#include "data.h"

double get_mean( const int32_t input[], size_t size ){
    int64_t sum = 0;
    for(int i = 0 ; i < size; i++){
        sum += input[i];
    }
    return (double)sum / (double)size;
}

double get_median( const int32_t input[], size_t size ){
    int32_t sortedInput[size];
    sort_input(input, size, sortedInput);
    if(size % 2 == 1){
        return sortedInput[size / 2];
    }
    else{
        return sortedInput[size / 2 - 1] + (sortedInput[size / 2] - sortedInput[size / 2 - 1]) / 2.0;
    }
}

int32_t get_mode( const int32_t input[], size_t size ){
    int32_t sortedInput[size];
    sort_input(input, size, sortedInput);

    int mode = sortedInput[0];
    for(int i = 1, pre = sortedInput[0], times = 1, maxTimes = 1; i < size; i++){
        times = (sortedInput[i] == pre ? times + 1 : 1);
        if(times >= maxTimes){
            maxTimes = times;
            mode = sortedInput[i];
        }
        pre = sortedInput[i];
    }
    return mode;
}

double get_stddev( const int32_t input[], size_t size ){
    double avg = get_mean(input, size);
    double sumOfSquare = 0;
    for(int i = 0 ; i < size; i++){
        double sub = input[i] - avg;
        sumOfSquare += sub * sub;
    }
    return sqrt(sumOfSquare / size);
}

void sort_input( const int32_t input [], size_t size, int32_t sorted []){
    for(int i = 0; i < size; i++){
        sorted[i] = input[i];
    }
    qsort(sorted, size, sizeof(int32_t), compare);
}

int compare(const void* arg1, const void* arg2){
	return (*(int32_t*)arg1) - (*(int32_t*)arg2);
}