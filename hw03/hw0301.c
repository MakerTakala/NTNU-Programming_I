#include <stdio.h>
#include <stdint.h>
#include <math.h>

int main(){
    int64_t w = 0, h = 0;
    printf("Please enter the width : ");
    scanf("%ld", &w);
    printf("Please enter the height: ");
    scanf("%ld", &h);
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