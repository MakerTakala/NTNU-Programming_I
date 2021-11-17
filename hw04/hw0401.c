#include <stdio.h>
#include <stdint.h>
#include "askinput_exit.h"
#include "hw0401kprint.h"

int main(){
    int64_t n = 0;
    askInput("Please enter n (1-100, n must be odd): ", &n);
    wrongInputDectect(n);
    kprint(n);
    return 0;
}