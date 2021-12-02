#include <stdio.h>
#include <stdint.h>
#include "polynomial.h"

void ask_input( char message [], int64_t* input){
    printf("%s", message);
    scanf("%ld", input);
}
void ask_array_input( char message [], int64_t arr[], size_t size){
    printf("%s", message);
    for(int i = 0; i < size; i++){
        scanf("%ld", &arr[i]);
    }
}