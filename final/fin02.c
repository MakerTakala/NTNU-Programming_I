#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include "go.h"

int main(){
    int board[19][19] = {{0}};
    srandom(time(0));
    for(int i = 0; i < 19; i++){
        for(int j = 0; j < 19; j++){
            srandom(random());
            board[i][j] = random() % 3;
            if(board[i][j] == 0){
                printf("\033[34m%d\033[m ", board[i][j]);
            }
            else if(board[i][j] == 1){
                printf("%d ", board[i][j]);
            }
            else{
                printf("\033[31m%d\033[m ", board[i][j]);
            }
        }
        printf("\n");
    }
    printf("%d", max_black_chain(board));
    return 0;
}