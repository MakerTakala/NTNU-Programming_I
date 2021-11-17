#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include "midfunction.h"
#include "mid04function.h"

int main(){

    InitMap();
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
    printMap();

    //GameStart 
    while(true){
        //PlayerMove
        playerMovement(&player);

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
