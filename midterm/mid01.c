#include <stdio.h>
#include <stdint.h>
#include "midfunction.h"

void wrongInputDetect(int64_t);

int main(){
    int64_t n1 = 0, n2 = 0;
    askInput("Please enter the 1st integer: ", &n1);
    wrongInputDetect(n1);
    askInput("Please enter the 2nd integer: ", &n2);
    wrongInputDetect(n2);
    if(n1 ==0 && n2 == 0){
        printf("00\n");
        return 0;
    }
    int64_t ans = 0;
    while( !n1 == 0 || !n2 == 0){
        if(n1 % 10 >= n2 % 10){
            ans = ans * 10 + (n1 % 10);
            n1 /= 10;
        }
        else{
            ans = ans * 10 + (n2 % 10);
            n2 /= 10;
        }
    }

    printf("%ld\n", ans);
    return 0;
}

void wrongInputDetect(int64_t x){
    int pre = x % 10;
    x /= 10;
    if(x < 0){
        errorMessageExit("Wrong Input");
    }
    while(x){
        if(pre < x % 10){
            errorMessageExit("Wrong Input");
        }
        pre = x % 10;
        x /= 10;
    }
}