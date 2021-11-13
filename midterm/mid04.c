#include <stdio.h>
#include <stdint.h>
#include "midfunction.h"

typedef struct{
    int64_t movement;
    int64_t vision;
    int64_t location;
}enemy;


int main(){
    char map[21][81];
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
    int64_t playerMovement = 0;
    while(1){
        askInput("Your movement (3-6): ", &playerMovement);
        if(playerMovement < 3 || 6 < playerMovement ){
            printf("Invalid input!!\n");
        }
        else{
            break;
        }
    }

    enemy enemy1;
    enemy enemy2;

    while(1){
        askInput("Enemy 1 movement (3-6): ", &(enemy1.movement));
        if(enemy1.movement < 3 || 6 < enemy1.movement){
            printf("Invalid input!!\n");
        }
        else{
            break;
        }
    }
    while(1){
        askInput("Enemy 1 vision (2-10): ", &(enemy1.vision));
        if(enemy1.vision < 2 || 10 < enemy1.vision){
            printf("Invalid input!!\n");
        }
        else{
            break;
        }
    }
    while(1){
        askInput("Enemy 1 location (2-80): ", &(enemy1.location));
        if(enemy1.location < 2 || 80 < enemy1.location){
            printf("Invalid input!!\n");
        }
        else{
            break;
        }
    }
    
    while(1){
        askInput("Enemy 2 movement (3-6): ", &(enemy2.movement));
        if(enemy2.movement < 3 || 6 < enemy2.movement){
            printf("Invalid input!!\n");
        }
        else{
            break;
        }
    }
    while(1){
        askInput("Enemy 2 vision (2-10): ", &(enemy2.vision));
        if(enemy2.vision < 2 || 10 < enemy2.vision){
            printf("Invalid input!!\n");
        }
        else{
            break;
        }
    }
    while(1){
        askInput("Enemy 2 location (2-20): ", &(enemy2.location));
        if(enemy2.location < 2 || 20 < enemy2.location){
            printf("Invalid input!!\n");
        }
        else{
            break;
        }
    }
    
    for(int i = 1 ; i <= enemy1.vision; i++){
        for(int j = 0; j < i * 2 - 1; j++){
            if(j + enemy1.location - i > 0){
                map[i][j + enemy1.location - i] = '*';
            }
        }
    }
    for(int i = 1 ; i <= enemy2.vision; i++){
        for(int j = 0; j < i * 2 - 1; j++){
                map[j + enemy2.location - i][i] = '*';
        }

    }

    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 80; j++){
            printf("%c", map[i][j]);
        }
        printf("\n");
    }

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
    
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 80; j++){
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
    return 0;
}

