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