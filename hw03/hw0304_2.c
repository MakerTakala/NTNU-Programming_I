#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(){
    for(int n = 2; n < 15; n++){
        long double ans = 2 * n;
        for(int i = 2 * (n - 1); i >= 2; i -= 2){
            ans = i + 1 / ans;
            ans = 1 + 1 / ans;
            ans = 1 + 1 / ans;
        }
        ans += 1;
        printf("N: %d\n", n);
        printf("Answer: %.25Lf\n", ans);
    }
    
    return 0;
}