#include <stdio.h>
#include <stdint.h>

int main(){
    uint16_t num = 0, flip_num = 0;
    printf("Please enter an unsigned 16-bits number: ");
    scanf("%hu", &num);

    printf("Before Flip:\n%hu_10 = %04X_16\n", num, num);
    for(int i = 0; i < 4; i++){
        flip_num = flip_num * 16 + num % 16;
        num /= 16;
    }
    printf("After  Flip:\n%hu_10 = %04X_16\n", flip_num, flip_num);

    return 0;
}