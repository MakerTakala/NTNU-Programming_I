#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(){
    for(int n = 2; n < 100; n++){
        long double ans = 2 * n, e = 2.7182818284590452354;
        for(int i = 2 * (n - 1); i >= 2; i -= 2){
            ans = i + 1 / ans;
            ans = 1 + 1 / ans;
            ans = 1 + 1 / ans;
        }
        ans += 1;
        printf("N: %d\n", n);
        printf("Answer: %.50Lf\n", ans);
        printf("differ: %.50Lf\n\n", ans - e);
    }
    
    return 0;
}