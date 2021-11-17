#ifndef MID04FUNCTION_H_INCLUDE
#define MID04FUNCTION_H_INCLUDE

#include <stdint.h>
extern char map[21][81];

typedef struct{
    int64_t movement;
    int64_t x;
    int64_t y;
}Player;

typedef struct{
    int64_t movement;
    int64_t vision;
    int64_t x;
    int64_t y;
}enemy;


void InitMap();
void playerAndEnemySetup(char[], int64_t*, int64_t, int64_t);
void enemyLocationsetup(enemy);
void playerMovement(Player*);
void printMap();

#endif