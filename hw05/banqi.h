#pragma once
#include <stdint.h>
#include <stdbool.h>
#include "banqi.h"

typedef struct{
    char name;
    char color;
    int8_t level; 
    int8_t state;
}Chess;

typedef struct{
    char name;
    char color;
    int8_t left_chess;
}Player;

void init_chess();
void init_player(Player *, char);
void print_board();
void banqi_game();
void player_round(Player *, Player *);
void move(Player *, Player *, int64_t, int64_t);
bool can_move(int64_t, int64_t, int64_t, int64_t);
bool can_eat(Chess *, Chess *);
void cannon_move(Player *, Player *, int64_t, int64_t);
bool cannon_can_move(int64_t, int64_t, int64_t, int64_t);
void swap(Chess *, Chess *);