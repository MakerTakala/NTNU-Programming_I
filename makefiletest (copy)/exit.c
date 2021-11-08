#include "exit.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void wrongInputDetect(int64_t num){
    if(num <= 0){
        printf("\nWrong Input!!!\n");
        printf("----------------------------------------------------------\n\n");
        exit(0);
    }
}