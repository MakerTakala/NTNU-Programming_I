#include <stdio.h>
#include <stdint.h>
#include "hw04fuc.h"

int main(){
    int64_t n = 0;
    askInput("Please enter n (1-100, n must be odd): ", &n);
    if(n < 1 || 100 < n || n % 2 == 0){
        errorMessageExit("Wrong Input!");
    }
    kprint(n);
    return 0;
}
