#include <stdio.h>
#include <stdint.h>
#include "midfunction.h"

int main(){
    int64_t input[10000] = {0};
    printf("Please enter the integer: ");
    int index = 0;
    while(scanf("%ld", &input[index]) && input[index++] != 0){
        printf("Please enter the integer: ");
    }

    int64_t startPos = 0, startPoint = 0;
    int8_t success = 0;
    int64_t match[2] = {0};
    for(int64_t i = 0 ;i < index; i++){
        if(input[i] == 13 || input[i] == 27 || input[i] == 68){
            match[0]++;
            if(success == 0 && match[0] == 1 && match[1] == 0){
                startPos = i;
                startPoint = input[i];
            }
        }
        else if(input[i] == -5 || input[i] == 19 || input[i] == 103|| input[i] == 27){
            match[1]++;
            if(success == 0 && match[0] == 0 && match[1] == 1 ){
                startPos = i;
                startPoint = input[i];
            }
        }
        else if(input[i] == -33){
            if(success == 0){
                if(match[0] < 2 && match[1] != 0 && match[1] < 3){
                    success++;
                    match[0] = 0;
                    match[1] = 0;
                }
            }
            else if(success == 1){
                if(match[0] < 2 && match[1] != 0 && match[1] < 3){ 
                    break;
                }
            }
        }
    }

    if(success == 2){
        printf("The first matching series is at position %ld, integer %ld.\n", startPos, startPoint);
    }
    else{
        printf("None\n");
    }
    return 0;
}