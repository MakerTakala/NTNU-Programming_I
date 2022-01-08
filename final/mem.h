#pragma once

#include <stdint.h>
#include <stddef.h>

/*
Input:
size: requested memory size.
front_size: additional memory size which is in front of the requested memory
block.
*available_front_size: used to record the available space of the front
additional size. The user should setup a valid available_front_size first.
If the available_front_size is NULL , you should treat this as zero , which
means there is no additional memory space.
Output:
The allocate memory address which does not include the front additional
memory.
*/
void * my_malloc( size_t , size_t , size_t * );
/*
Input:
**ptr: the memory address that will be changed.
size: use the front memory , which implies moving the address forward.
*available_front_size: used to record the available space of the front
additional size. If the size is larger than *available_front_size , the
function will only use all available space. If available_front_size is
NULL , then the address will not be changed.
Output:
None
*/
void my_push( void **, size_t , size_t * );
/*
Input:
*ptr: the memory address that will be freed.
available_front_size: the available memory space in front of the memory
address. You can assume that available_front_size is valid.
Output:
None
*/
void my_free( void *, size_t );