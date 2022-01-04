#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "mymem.h"

size_t change_size(size_t num){
    if(num <= 0x18){
        return 0x21;
    }
    else if(num <= 0x2F){
        return 0x31;
    }
    else{
        return (num / 0x10 + 1) * 0x10 + 1;
    }
}

void my_realloc( void **pptr, size_t before , size_t after ){
    if(after == 0){
        free(*pptr);
        (*pptr) = NULL;
        return;
    }
    if(before == 0){
        *pptr = malloc(after);
        return;
    }
    if(before == after){
        return;
    }
    if(before < after){
        int8_t *newpptr = malloc(after);
        for(int i = 0; i <= before ; i++){
            *(newpptr + i) = *(int8_t*)((*pptr) + i);
        }
        free(*pptr);
        *pptr = newpptr;
        return;
    }
    if(before > after){
        int64_t *pptr_metadata = ((int64_t*)(*pptr)) - 1;

        before = change_size(before);
        after = change_size(after);
        if(before - after < 0x20){
            return;
        }
        (*pptr_metadata) = after;

        int64_t *release = (int64_t*)(*pptr) + ((*pptr_metadata) - 1) / sizeof(int64_t);
        int64_t *release_metadata = release - 1;

        (*release_metadata) = ((before - after) / 0x10) * 0x10 + 1;
        free(release);
        return;
    }
}
