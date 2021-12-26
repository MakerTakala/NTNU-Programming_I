#pragma once
#include <stdint.h>

// If a < b, return -1 and c is meaningless.
// If a and b are co-prime , return 1 and c is the multiplicative inverse of b mod a.
// If a and b are not co-prime , return 0 and c is the gcd.
int32_t ext_euclidean( uint32_t, uint32_t, uint32_t * );
uint32_t gcd(uint32_t, uint32_t );
uint32_t phi(uint32_t);