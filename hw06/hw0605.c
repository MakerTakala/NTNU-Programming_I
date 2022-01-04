#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "mymem.h"
#define before 0x80
#define after 0x10

int main(){
    int64_t *p;
    p = malloc(before);
    my_realloc((void**)&p, before, after);
    return 0;
}