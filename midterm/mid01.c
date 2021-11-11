#include <stdio.h>
#include <stdint.h>
#include "midfunction.h"

int main(){
    int64_t input = 0;
    askInput("Input :" , &input);
    errorMessageExit("Wrong Input");
    return 0;
}