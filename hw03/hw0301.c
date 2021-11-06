#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>
#define min(a, b) (a > b ? b : a)

void wrongInputDetect(int64_t);
int64_t numcalculate(int64_t, int64_t);
int64_t w = 0, h = 0;

int main(){
    printf("Please enter the width : ");
    scanf("%ld", &w);
    wrongInputDetect(w);
    printf("Please enter the height: ");
    scanf("%ld", &h);
    wrongInputDetect(h);
    
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            printf("%*ld ", (int)log10(w * h) + 1, numcalculate(i, j));
        }
        printf("\n");
    }

    return 0;
}

void wrongInputDetect(int64_t num){
    if(num <= 0){
        printf("\nWrong Input!!!\n");
        printf("----------------------------------------------------------\n\n");
        exit(0);
    }
}

int64_t numcalculate(int64_t y, int64_t x){
    int64_t level = min( min(y, x), min(h - y - 1, w - x - 1) );
    int64_t m = h - level * 2, n = w - level * 2;
    int64_t loopFirstNum = (h * w) - m * n + 1;

    if(x == level || y == h - level - 1){
        return loopFirstNum + (y - level) + (x - level);
    }
    else{
        return (loopFirstNum + (m - 1) + (n - 1) ) + (h - y - level - 1) + (w - x - level - 1);
    }
    
}
