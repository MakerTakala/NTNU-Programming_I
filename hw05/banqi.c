#include "banqi.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

Chess chess[4][8];
Player player1, player2;
int16_t tie = 0;



void init_chess(){
    srandom(time(0));
    int8_t target_chess[2][7] = {{1, 2, 2, 2, 2, 2, 5}, {1, 2, 2, 2, 2, 2, 5}};
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 8;){
            int8_t col = random() % 2;
            int8_t type =  random() % 7;
            if(target_chess[col][type] != 0){
                target_chess[col][type]--;
                chess[i][j].name = (col == 0 ? (type + '1') : (type + 'A'));
                chess[i][j].color = (col == 0 ? 'B' : 'R');
                chess[i][j].level = 7 - type;
                chess[i][j].state = 0;
                j++;
            }
        }
    }
}

void init_player(Player *p, char n){
    p -> name = n;
    p -> color = 'N';
    p -> left_chess = 16;
}

void print_board(){
    printf("\n  ");
    for(int i = 1; i <= 8; i++){
        printf("%d ", i);
    }
    printf("\n +---------------+\n");
    for(int i = 0; i < 4; i++){
        printf("%d|", i + 1);
        for(int j = 0; j < 8; j++){
            switch(chess[i][j].state){
                case 0:{
                    printf("*|");
                    break;
                }
                case 1:{
                    printf("%c|", chess[i][j].name);
                    break;
                }
                case 2:{
                    printf(" |");
                    break;
                }
            }
        }
        printf(i != 3 ?"\n |---------------|\n" : "\n +---------------+\n");
    }
    printf("\n");
}

void banqi_game(){
    Player player1, player2;
    init_chess();
    init_player(&player1, '1');
    init_player(&player2, '2');
    int8_t turn = 0;
    while(1){
        tie++;
        print_board();
        if(turn == 0){
            player_round(&player1, &player2);
        }
        else{
            player_round(&player2, &player1);
        }
        if(player2.left_chess == 0){
            printf("\nPlayer1 WIN!!\n");
            exit(0);
        }
        if(player1.left_chess == 0){
            printf("\nPlayer2 WIN!!\n");
            exit(0);
        }
        if(tie == 50){
            printf("\nTIE!!\n");
            exit(0);
        }
        turn ^= 1;
    }
}

void player_round(Player *playing_player, Player *enemy_player){
    
    if(playing_player -> color == 'N'){
        int64_t chess_x, chess_y;
        while(1){
            printf("Player 1 (x,y):");
            scanf("%ld,%ld", &chess_x, &chess_y);
            if(chess_x < 1 || 8 < chess_x || chess_y < 1 || 4 < chess_y){
                printf("\nWrong Input!!Please input your choice again!\n\n");
                continue;
            }
            break;
        }
        Chess *choice_chess = &chess[chess_y - 1][chess_x - 1];
        choice_chess -> state = 1;
        if(choice_chess -> color == 'B'){
            playing_player -> color = 'B';
            enemy_player -> color = 'R';
        }
        else if(choice_chess -> color == 'R'){
            playing_player -> color = 'R';
            enemy_player -> color = 'B';
        }
    }
    else{
        int64_t chess_x, chess_y;
        while(1){
            printf("Player %c (x,y): ", playing_player -> name);
            scanf("%ld,%ld", &chess_x, &chess_y);
            if(chess_x < 1 || 8 < chess_x || chess_y < 1 || 4 < chess_y){
                printf("\nWrong Input!!Please input your choice again!\n\n");
                continue;
            }
            Chess *choice_chess = &chess[chess_y - 1][chess_x - 1];
            if(choice_chess -> state == 0){
                choice_chess -> state = 1;
                break;
            }
            else if(choice_chess -> state == 1){
                if(choice_chess -> color == playing_player -> color){
                    if(choice_chess -> level == 2){
                        cannon_move(playing_player, enemy_player, chess_x - 1, chess_y - 1);
                        break;
                    }
                    else{
                        move(playing_player, enemy_player, chess_x - 1, chess_y - 1);
                        break;
                    }
                }
                else{
                    printf("\nThis chess is not your!!Please input your choice again!\n\n");
                    continue;
                }
            }
            else if(choice_chess -> state == 2){
                printf("\nThis position is empty!!Please input your choice again!\n\n");
                continue;
            }
        }
    }
}

void move(Player *playing_player, Player *enemy_players, int64_t chess_x, int64_t chess_y){
    int8_t direction_table[5] = {0, 1, 0, -1, 0};
    for(int i = 0; i < 4; i++){
        if(can_move(chess_x, chess_y, chess_x + direction_table[i], chess_y + direction_table[i + 1])){
            break;
        }
        if(i == 3){
            printf("Because Player %c choice chess can't move\nPlayer %c PASS!!\n\n", playing_player -> name, playing_player -> name);
            return ;
        }
    }
    int64_t to_x, to_y;
    while(1){
        printf("To (x,y): ");
        scanf("%ld,%ld", &to_x, &to_y);
        if(!can_move(chess_x, chess_y, to_x - 1, to_y - 1)){
            printf("\nWrong Input!!Please input your destination again!\n\n");
            continue;
        }
        break;
    }
    Chess *moving_chess = &chess[chess_y][chess_x];
    Chess *attempt_space = &chess[to_y - 1][to_x - 1];
    if(attempt_space -> state == 1){
        attempt_space -> state = 2;
        enemy_players -> left_chess--;
        tie = 0;
    }
    swap(moving_chess, attempt_space);
}

bool can_move(int64_t chess_x, int64_t chess_y, int64_t to_x, int64_t to_y){
    if(abs(chess_x - to_x) + abs(chess_y - to_y) != 1){
        return false;
    }
    if(to_x == -1 || to_x == 8 || to_y == -1 || to_y == 4){
        return false;
    }
    Chess *moving_chess = &chess[chess_y][chess_x];
    Chess *attempt_space = &chess[to_y][to_x];
    if(attempt_space -> state == 0){
        return false;
    }
    if(attempt_space -> state == 1 && !can_eat(moving_chess, attempt_space)){
        return false;
    }
    return true;
}

bool can_eat(Chess *moving_chess, Chess *eaten_chess){
    if(moving_chess -> level == 2){
        return false;
    }
    if(moving_chess -> color == eaten_chess -> color){
        return false;
    }
    if(moving_chess -> level == 1 && eaten_chess -> level == 7){
        return true;
    }
    return moving_chess -> level >= eaten_chess -> level;
}

void cannon_move(Player *playing_player, Player *enemy_players, int64_t chess_x, int64_t chess_y){
    int8_t direction_table[5] = {0, 1, 0, -1, 0};
    bool allow = false;
    for(int i = 0; i < 4; i++){
        if(can_move(chess_x, chess_y, chess_x + direction_table[i], chess_y + direction_table[i + 1])){
            allow = true;
        }
        for(int j = 2; ; j++){
            int64_t to_x = chess_x + direction_table[i] * j, to_y = chess_y + direction_table[i + 1] * j;
            if(to_x < 0 || 7 < to_x || to_y < 0 || 3 < to_y){
                break;
            }
            if(cannon_can_move(chess_x, chess_y, to_x, to_y)){
                allow = true;
            }
        }
        if(allow){
            break;
        }
        if(i == 3){
            printf("Because Player %c choice chess can't move\nPlayer %c PASS!!\n\n", playing_player -> name, playing_player -> name);
            return ;
        }
    }
    int64_t to_x, to_y;
    while(1){
        printf("To (x,y): ");
        scanf("%ld,%ld", &to_x, &to_y);
        if(!cannon_can_move(chess_x, chess_y, to_x - 1, to_y - 1) && !can_move(chess_x, chess_y, to_x - 1, to_y - 1)){
            printf("\nWrong Input!!Please input your destination again!\n\n");
            continue;
        }
        break;
    }
    Chess *moving_chess = &chess[chess_y][chess_x];
    Chess *attempt_space = &chess[to_y - 1][to_x - 1];
    if(attempt_space -> state == 1){
        attempt_space -> state = 2;
        enemy_players -> left_chess--;
        tie = 0;
    }
    swap(moving_chess, attempt_space);
}

bool cannon_can_move(int64_t chess_x, int64_t chess_y, int64_t to_x, int64_t to_y){
    if(chess[chess_y][chess_x].color == chess[to_y][to_x].color){
        return false;
    }
    if(!(chess_x == to_x ^ chess_y == to_y)){
        return false;
    }
    if(chess_x == to_x){
        int8_t times = 0;
        for(int i = fmin(chess_y, to_y) + 1; i < fmax(chess_y, to_y); i++){
            if(chess[i][chess_x].state == 0 || chess[i][chess_x].state == 1){
                times++;
            }
        }
        return times == 1;
    }
    if(chess_y == to_y){
        int8_t times = 0;
        for(int i = fmin(chess_x, to_x) + 1; i < fmax(chess_x, to_x); i++){
            if(chess[chess_y][i].state == 0 || chess[chess_y][i].state == 1){
                times++;
            }
        }
        return times == 1;
    }
}

void swap(Chess *chess1, Chess *chess2){
    Chess tmp = *chess1;
    *chess1 = *chess2;
    *chess2 = tmp;
}
