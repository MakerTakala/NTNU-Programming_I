#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "midfunction.h"

typedef struct{
    int64_t movement;
    int64_t ymove;
    int64_t xmove;
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

    while(true){
        playerAndEnemySetup("Move: (1) Up (2) Down? ", &(), 1, 2);
    }
    printMap();
    

    int64_t dir1 = 0, dir2 = 0, range1 = 0, range2 = 0;
    while(1){
        askInput("Move: (1) Up (2) Down? ", &dir1);
        if(dir1 == 1 || dir1 == 2){
            break;
        }
        else{
            printf("Invalid input!!\n");
        }
    }
    while(1){
        askInput("MRange (0-3)? ", &range1);
        if(range1 > 0 && range1 < 3){
            break;
        }
        else{
            printf("Invalid input!!\n");
        }
    }
    while(1){
        askInput("Move: (1) Up (2) Down? ", &dir2);
        if(dir2 == 1 || dir2 == 2){
            break;
        }
        else{
            printf("Invalid input!!\n");
        }
    }
    while(1){
        askInput("Range (0-3)? ", &range2);
        if(range2 > 0 && range2 < 3){
            break;
        }
        else{
            printf("Invalid input!!\n");
        }
    }
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
    do{
        askInput(ask, input);
        pass = (down <= *input && *input <= up);
        if(!pass){
            printf("Invalid input!!\n");
        }
    }while(!pass);
}

void printMap(){
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 80; j++){
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}