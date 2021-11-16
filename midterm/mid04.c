#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include "midfunction.h"

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

char map[21][81];
void mapSetup();
void playerAndEnemySetup(char[], int64_t*, int64_t, int64_t);
void enemyLocationsetup(enemy);
void playerMovement(Player*);
void printMap();

int main(){

    mapSetup();
    Player player;
    enemy enemy1;
    enemy enemy2;
    playerAndEnemySetup("Your movement (3-6): ", &(player.movement), 3, 6);
    player.x = 78;
    player.y = 18;

    //setup enemy1
    playerAndEnemySetup("Enemy 1 movement (3-6): ", &(enemy1.movement), 3, 6);
    playerAndEnemySetup("Enemy 1 vision (2-10): ", &(enemy1.vision), 2, 10);
    playerAndEnemySetup("Enemy 1 location (2-80): ", &(enemy1.x), 2, 80);
    enemy1.y = 1; 

    //setup enemy2
    playerAndEnemySetup("Enemy 2 movement (3-6): ", &(enemy2.movement), 3, 6);
    playerAndEnemySetup("Enemy 2 vision (2-10): ", &(enemy2.vision), 2, 10);
    playerAndEnemySetup("Enemy 2 location (2-20): ", &(enemy2.y), 2, 20);
    enemy2.x = 1;

    //GameStart 
    while(true){
        //PlayerMove
        playerMovement(&player);

    }
    printMap();
    /*


    for(int i = 1 ; i <= enemy1.vision; i++){
        for(int j = 0; j < i * 2 - 1; j++){
            if(j + enemy1.x - i > 0){
                map[i][j + enemy1.x - i] = '*';
            }
        }
    }
    for(int i = 1 ; i <= enemy2.vision; i++){
        for(int j = 0; j < i * 2 - 1; j++){
                map[j + enemy2.y - i][i] = '*';
        }

    }
    */
}

void mapSetup(){
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
    map[1][1] = 'S';
    map[18][78] = 'P';
}

void playerAndEnemySetup(char ask[], int64_t* input, int64_t down, int64_t up){
    bool pass = false;
    while(!pass){
        askInput(ask, input);
        pass = (down <= *input && *input <= up);
        if(!pass){
            printf("\033[31m \nInvalid input!!\n\033[m\n");
        }
    }
}

void playerMovement(Player* p){
    int64_t vertical = 0, horizon = 0;
    int64_t ymove = 0, xmove = 0;
    int64_t movement = p -> movement;
    char askword[100];
    bool pass = false;
    while(!pass){
        pass = true;
        playerAndEnemySetup("Move: (1) Up (2) Down?", &vertical, 1, 2);
        sprintf(askword, "Range (0-%ld)?", movement);
        playerAndEnemySetup(askword, &ymove, 0, movement);
        if(ymove > movement){
            printf("\033[31m \nYour can only move %ld steps.\n\033[m\n", movement);
            pass = false;
            continue;
        }
        
        playerAndEnemySetup("Move: (1) Left (2) Right?", &horizon, 1, 2);
        sprintf(askword, "Range (0-%ld)?", movement - ymove);
        playerAndEnemySetup(askword, &xmove, 0, movement - ymove);
        if(ymove > movement){
            printf("\033[31m \nYour can only move %ld steps.\n\033[m\n", movement - ymove);
            pass = false;
            continue;
        }

        ymove *= (vertical == 1 ? 1 : -1);
        xmove *= (horizon == 1 ? 1 : -1);

        if(abs(xmove) + abs(ymove) > p -> movement){
            printf("\033[31m \nYour can only move %ld steps.\n\033[m\n", movement);
            pass = false;
            continue;
        }
        if( p -> y + ymove  < 1 || 18 < p -> x + ymove ){
            printf("\033[31m \nYour move will hit the boundary.\n\033[m\n");
            pass = false;
            continue;
        }
        if( p -> x + xmove  < 1 || 78 < p -> x + xmove ){
            printf("\033[31m \nYour move will hit the boundary.\n\033[m\n");
            pass = false;
            continue;
        }
    }
    p -> y += ymove;
    p -> x += xmove;

}

void printMap(){
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 80; j++){
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}