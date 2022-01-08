#include <stdio.h>
#include <stdint.h>
#include "mem.h"

int main(){
    size_t ava_size;
    int64_t* req;
    req = my_malloc(128, 64, &ava_size);
    printf("%p %lu", req, ava_size);
    
    return 0;
}