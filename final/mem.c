#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include "mem.h"

size_t recode_front = 0;

void *my_malloc( size_t size, size_t front_size , size_t *available_front_size){
    if(available_front_size != NULL){
        *available_front_size = size;
    }
    recode_front = front_size;
    int8_t *add_ptr = malloc(size + front_size);
    int8_t *req_ptr = add_ptr + front_size;
    return req_ptr;
}

void my_push( void **ptr, size_t size, size_t *available_front_size ){
    int8_t ava = (available_front_size == NULL ? 0 : (*available_front_size));
    if(size >= ava){
        *ptr = (int8_t *)(*ptr) + ava;
        if(available_front_size != NULL){
            *available_front_size = 0;
        }
    }
    else{
        *ptr = (int8_t *)(*ptr) + size;
        if(available_front_size != NULL){
            *available_front_size -= size;
        }
    }
}

void my_free( void *ptr, size_t available_front_size ){
    ptr =(int8_t *)ptr - recode_front;
    free(ptr);
}