#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include "go.h"

int32_t BOARD[19][19] = {{0}};
bool visited[19][19] = {{false}};
int16_t max_lib = 0;

void init(){
    for(int i = 0; i < 19; i++){
        for(int j = 0; j < 19; j++){
            visited[i][j] = false;
        }
    }
    max_lib = 0;
}

void clean(){
    for(int i = 0; i < 19; i++){
        for(int j = 0; j < 19; j++){
            if(BOARD[i][j] == 3){
                BOARD[i][j] = 0;
            }
        }
    }
}

int32_t DFS(int32_t x, int32_t y){
    int32_t dir[5] = {-1, 0, 1, 0, -1};
    int32_t ans = 0;
    for(int i = 0; i < 4; i++){
        if(x + dir[i] < 0 || x + dir[i] > 18 || y + dir[i + 1] < 0 || y + dir[i + 1] > 18){
            ans += 0;
        }
        else if(BOARD[x + dir[i]][y + dir[i + 1]] == 0){
            ans += 1;
            BOARD[x + dir[i]][y + dir[i + 1]] = 3;
        }
        else if(BOARD[x + dir[i]][y + dir[i + 1]] == 1 && visited[x + dir[i]][y + dir[i + 1]] == false){
            visited[x][y] = true;
            ans += DFS(x + dir[i], y + dir[i + 1]);
        }
        else if(BOARD[x + dir[i]][y + dir[i + 1]] == 2){
            ans += 0;
        }
    }
    return ans;
}

int32_t max_black_chain( int32_t board[][19] ){
    init();
    for(int i = 0; i < 19; i++){
        for(int j = 0; j < 19; j++){
            BOARD[i][j] = board[i][j];
        }
    }

    for(int i = 0; i < 19; i++){
        for(int j = 0; j < 19; j++){
            if(BOARD[i][j] == 1 && visited[i][j] == false){
                visited[i][j] = true;
                max_lib = fmax(max_lib, DFS(i, j));
                clean();
            }        
        }
    }
    return max_lib;
}