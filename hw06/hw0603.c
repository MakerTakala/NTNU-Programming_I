#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void print_num(int64_t);

int main(){
    int64_t num = 0;
    printf("Please input an integer: ");
    scanf("%ld", &num);
    int64_t pos = 0, revise_value = 0;
    while(1){
        while(1){
            print_num(num);
            printf("Please enter the position (1-8, 0: End): ");
            scanf("%ld", &pos);
            if(pos == 0){
                exit(0);
            }
            else if(pos < 1 ||8 < pos){
                printf("\nWrong Input!\n\n");
            }
            else{
                break;
            }
        }
        while(1){
            printf("Please enter the new value (0-255):");
            scanf("%ld", &revise_value);
            if(revise_value < 0 || 255 < revise_value){
                printf("\nWrong Input!\n\n");
                print_num(num);
                printf("Position: %ld\n", pos);
            }
            else{
                printf("---\n");
                break;
            }
        }
        int8_t *ptr = (uint8_t *)&num + (sizeof(num) - pos);
        *ptr = revise_value; 
    }
    
    return 0;
}

void print_num(int64_t num){
    uint8_t *ptr = (uint8_t *)&num;
    printf("The integer: %ld\n", num);
    for(int i = sizeof(num) - 1; i >= 0 ; i--){
        printf("(%lu) 0x%02X " , sizeof(num) - i, *(ptr + i));
    }
    printf("\n");
}