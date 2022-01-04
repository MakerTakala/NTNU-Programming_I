#pragma once
#include <stddef.h>

// *pptr is the original pointer.
// before is the original size and after is the wanted size.
// You need to make sure that the first min( before , after ) bytes are the same.
void my_realloc( void **, size_t , size_t );