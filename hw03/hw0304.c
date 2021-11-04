#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(){
    int64_t n = 0;
    printf("Please enter n: ");
    scanf("%ld", &n);
    if(n < 2){
        printf("\nWrong Input!!!\n");
        printf("----------------------------------------------------------\n\n");
        exit(0);
    }

    long double ans = 2 * n;
    for(int i = 2 * (n - 1); i >= 2; i -= 2){
        ans = i + 1 / ans;
        ans = 1 + 1 / ans;
        ans = 1 + 1 / ans;
    }
    ans += 1;
    printf("Answer: %.50Lf\n", ans);
    return 0;
}