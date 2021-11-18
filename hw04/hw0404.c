#include <stdio.h>
#include <stdint.h>
#include "hw04fuc.h"

int main(){
    int64_t resistance = 0;
    askInput("Please enter the resistance (1-100): ", &resistance);
    if(resistance <= 0 || 100 <= resistance){
        errorMessageExit("Wrong Input");
    }
    int64_t n = 0;
    askInput("Please enter n (1-100):", &n);
    if(n <= 0 || 100 <= n){
        errorMessageExit("Wrong Input");
    }
    printf("Ans: %Lf\n", countResistance(resistance, n));
    return 0;
}