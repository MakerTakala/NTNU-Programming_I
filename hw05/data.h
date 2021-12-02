#pragma once

#include <stdint.h>
#include <stddef.h>

double get_mean( const int32_t [], size_t );
double get_median( const int32_t [], size_t );
int32_t get_mode( const int32_t [], size_t );
double get_stddev( const int32_t [], size_t );
void sort_input(const int32_t [], size_t, int32_t [] );
int compare(const void* , const void* );