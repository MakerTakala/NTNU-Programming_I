#pragma once

#include <stdint.h>

void errorMessageExit(char []);
void askInput(char [], int64_t* );
void kprint(int64_t n);
void hanoi_recur(int64_t, int8_t, int8_t, int8_t, int64_t);
void hanoi_loop(int64_t);
long double countResistance(int64_t , int64_t );
