#pragma once

#include <stdint.h>

void errorMessageExit(char []);
void askInput(char [], int64_t* );
void kprint(int64_t n);
void hanoi_recur(int64_t, int8_t, int8_t, int8_t, int64_t);
typedef struct{
    int8_t status;
    int8_t disk[20];
    int8_t top;
}rod;
void hanoi_loop(int64_t);
rod initRod(int8_t, int8_t, int8_t);
void transformDisk(rod*, rod*);
int64_t power(int64_t, int64_t);
long double countResistance(int64_t, int64_t);
