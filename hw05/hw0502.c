#include <stdio.h>
#include <stdint.h>
#include "data.h"

int main(){
    int32_t input[6] = {0, 4, 6, 6, 3, 4};
    printf("mean:%lf\n", get_mean( input, 6 ));
    printf("median:%lf\n", get_median( input, 6 ));
    printf("mode:%d\n", get_mode( input, 6 ));
    printf("stddev:%lf\n", get_stddev( input, 6 ));
    return 0;
}