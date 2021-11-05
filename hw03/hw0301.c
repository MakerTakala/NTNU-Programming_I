#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>

void wrongInputDetect(int64_t);

int main(){
    int64_t w = 0, h = 0;
    printf("Please enter the width : ");
    scanf("%ld", &w);
    wrongInputDetect(w);
    printf("Please enter the height: ");
    scanf("%ld", &h);
    wrongInputDetect(h);
    int64_t ans[h][w];
    int64_t tmph = h, tmpw = w;

    int64_t n = 1, y = -1, x = 0;
    int8_t digit = log10(h * w) + 1;
    w -= 1;
    while(h >= 0 && w >= 0){
        for(int i = 0; w >= 0 && i < h; i++){
            ans[++y][x] = n++;
        }
        h--;
        for(int i = 0; h >= 0 && i < w; i++){
            ans[y][++x] = n++;
        }
        w--;
        for(int i = 0; w >= 0 && i < h; i++){
            ans[--y][x] = n++;
        }
        h--;
        for(int i = 0; h >= 0 && i < w; i++){
            ans[y][--x] = n++;
        }
        w--;
    }
    
    for(int i = 0; i < tmph; i++){
        for(int j = 0; j < tmpw; j++){
            printf("%*ld ", digit, ans[i][j]);
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