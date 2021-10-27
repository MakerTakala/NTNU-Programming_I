#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
int main(){
    char Hello[12] = "Hello World";
    int8_t colortable[15] = {31, 32, 33, 34, 35, 36, 37, 90, 91, 92, 93, 94, 95, 96, 97};
    int8_t color = 0;
    while(1){
        srand(rand());
        for(int8_t i = 0; i < 11; i++){
            printf("\033[6;%d;40m%c\033[m", colortable[color], Hello[i]);
            color = rand() % 15;
        }
        printf("\n");
    }
    return 0;
}