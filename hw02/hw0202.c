#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(){
    int64_t x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    printf("First point (x,y): ");
    scanf("%ld, %ld", &x1, &y1);
    printf("Second point (x,y): ");
    scanf("%ld, %ld", &x2, &y2);
    if( (x1 == x2) || (y1 == y2) ){
        printf("\nWrong Input!!!\n");
        printf("----------------------------------------------------------\n\n");
        return 0;
    }
    int64_t deltaX = labs(x1 - x2), deltaY = labs(y1 - y2);
    printf("Perimeter --> %ld\n", 2 * (deltaX + deltaY));
    printf("Area --> %ld\n", deltaX * deltaY);
    return 0;
}