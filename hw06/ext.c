#include <stdint.h>
#include <stdlib.h>
#include "ext.h"

int32_t ext_euclidean( uint32_t a, uint32_t b, uint32_t *c ){
    if(a < b){
        c = NULL;
        return -1;
    }
    else{
        uint32_t g = gcd(a, b);
        if(g != 1){
            *c = g;
            return 0;
        }
        else{
            for(int i = 1, base = b; i < phi(a) - 1; i++){
                b = (b * base) % a;
            }
            *c = b;
            return 1;
        }
    }
}

uint32_t gcd(uint32_t a, uint32_t b){
    if(a % b == 0){
        return b;
    }
    else{
        return gcd(b, a % b);
    }
}

uint32_t phi(uint32_t n){
    uint32_t ans = n;
    for(uint32_t i = 2; i * i <= n; i++){
        if(n % i == 0){
            ans = ans / i * (i - 1);
            while(n % i == 0){
                n /= i;
            }
        }
    }
    if(n > 1){
        ans = ans / n * (n - 1);
    }
    return ans;
}