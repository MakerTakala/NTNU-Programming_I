#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "midfunction.h"
#include "mid04function.h"


void InitMap(){
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 80; j++){
            if(i == 0 || i == 19){
                map[i][j] = '-';
            }
            else if(j == 0 || j == 79){
                map[i][j] = '|';
            }
            else{
                map[i][j] = ' ';
            }
        }
    }
}

void playerAndEnemySetup(char ask[], int64_t* input, int64_t down, int64_t up){
    bool pass = false;
    while(!pass){
        askInput(ask, input);
        pass = (down <= *input && *input <= up);
        if(!pass){
            printf("\033[91m \nInvalid input!!\n\033[m\n");
        }
    }
}

void playerMovement(Player* p){
    int64_t vertical = 0, horizon = 0;
    int64_t ymove = 0, xmove = 0;
    int64_t movement = p -> movement;
    char askword[100];
    while(true){

        askInput("Move: (1) Up (2) Down?", &vertical);
        if(!( vertical == 1 || vertical == 2) ){
            printf("\033[91m \nInvalid input!!\n\033[m\n");
            continue;
        }
        sprintf(askword, "Range (0-%ld)?", movement);
        askInput(askword, &ymove);
        if(ymove > movement){
            printf("\033[91m \nYour can only move %ld steps.\n\033[m\n", movement);
            continue;
        }
        
        askInput("Move: (1) Left (2) Right?", &horizon);
        if( !(horizon == 1 || horizon == 2) ){
            printf("\033[91m \nInvalid input!!\n\033[m\n");
            continue;
        }
        sprintf(askword, "Range (0-%ld)?", movement - ymove);
        askInput(askword, &xmove);
        if(xmove > movement - ymove){
            printf("\033[91m \nYour can only move %ld steps.\n\033[m\n", movement - ymove);
            continue;
        }

        if(xmove + ymove > p -> movement){
            printf("\033[91m \nYour can only move %ld steps.\n\033[m\n", movement);
            continue;
        }
        ymove *= (vertical == 1 ? 1 : -1);
        xmove *= (horizon == 1 ? 1 : -1);
        if( p -> y + ymove  < 1 || 18 < p -> x + ymove ){
            printf("\033[91m \nYour move will hit the boundary.\n\033[m\n");
            continue;
        }
        if( p -> x + xmove  < 1 || 78 < p -> x + xmove ){
            printf("\033[91m \nYour move will hit the boundary.\n\033[m\n");
            continue;
        }
        break;
    }
    p -> y += ymove;
    p -> x += xmove;
}

void printMap(Player* p, enemy* e1, enemy* e2){
    InitMap();
    
    map[p -> y][p -> x] = 'S';
    map[18][78] = 'P';
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 80; j++){
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}