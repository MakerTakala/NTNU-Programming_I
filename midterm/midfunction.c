#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "midfunction.h"

void errorMessageExit(char message[]){
    printf("\n%s\n", message);
    printf("----------------------------------------------------------\n\n");
    exit(0);
}

void ask(char message[], int64_t* input){
    printf("%s", message);
    scanf("%ld", input);
}