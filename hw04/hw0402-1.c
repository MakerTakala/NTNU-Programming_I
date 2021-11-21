#include <stdio.h>
#include <stdint.h>
#include "hw04fuc.h"

int main(){
    int64_t n = 0;
    askInput("Please enter the disk number (2-20): ", &n);
    if(n < 2 || 20 < n){
        errorMessageExit("Wrong Input\n");
    }
    hanoi_recur(n, 1, 2, 3, n);
    return 0;
}