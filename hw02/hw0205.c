#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

void inputCard(bool [], int8_t []);
int8_t HCPCounter(bool []);
void HAPandSuitOutput(int8_t, int8_t []);
void bibbingChoice(int8_t, int8_t []);

int main(){
    bool card[53] = {false};
    int8_t suit[4] = {0};
    inputCard(card, suit);
    int8_t HCP = HCPCounter(card);
    HAPandSuitOutput(HCP, suit);
    bibbingChoice(HCP, suit);
    
    return 0;
}

void inputCard(bool card[], int8_t suit[]){
    int32_t inputCard = 0;
    for(int8_t i = 0; i < 13; i++){
        switch(i){
            case 0 :{
                printf("1st");
                break;
            }
            case 1 :{
                printf("2nd");
                break;
            }
            case 2 :{
                printf("3rd");
                break;
            }
            default :{
                printf("%hhdth", i + 1);
                break;
            }
        }
        printf(" card: ");
        scanf("%d", &inputCard);
        if(inputCard > 52){
            printf("\nWrong Input!!!\n");
            printf("----------------------------------------------------------\n\n");
            exit(0);
        }
        card[inputCard] = true;
        suit[(inputCard - 1) / 13]++;
    }
}

int8_t HCPCounter(bool card[]){
    int8_t HCP = 0;
    for(int8_t i = 1; i <= 52; i++){
        int8_t point = (i - 1) % 13 + 1;
        if(card[i] == true){
            switch(point){
                case 1 :{
                    HCP += 4;
                    break;
                }
                case 11 :{
                    HCP += 1;
                    break;
                }
                case 12 :{
                    HCP += 2;
                    break;
                }
                case 13 :{
                    HCP += 3;
                    break;
                }
            }
        }
    }
    return HCP;
}

void HAPandSuitOutput(int8_t HCP, int8_t suit[]){
    printf("---\n");
    printf("HCP: %hhd pts\n", HCP);
    printf("Suit: %hhd", suit[0]);
    for(int8_t i = 1; i < 4; i++){
        printf("-%d", suit[i]);
    }
    printf("\n");
}

void bibbingChoice(int8_t HCP, int8_t suit[]){
    const char suitName[5][8] = {"S", "H", "D", "C", "NT"};
    int8_t bibPoint = 0, bibSuit = 0, mostHolding = 0;

    for(int8_t i = 0; i < 4; i++){
        mostHolding = suit[i] > mostHolding ? suit[i] : mostHolding;
    }

    if(10 <= HCP && HCP <= 12){
        if(suit[0] >=6 || suit[1] >= 6 || suit[2] >= 6){
            for(int8_t i = 0; i < 3; i++){
                if(suit[i] == mostHolding){
                    bibPoint = 2;
                    bibSuit = i;
                    break;
                }
            }
        }
        if(suit[0] >= 7 || suit[1] >= 7 || suit[2] >= 7 || suit[3] >= 7){
            for(int8_t i = 0; i < 4; i++){
                if(suit[i] == mostHolding){
                    bibPoint = 3;
                    bibSuit = i;
                    break;
                }
            }
        }
    }
    if(13 <= HCP && HCP <= 21){
        if( (suit[2] >= 3 || suit[3] >= 3) && (suit[2] == mostHolding || suit[3] == mostHolding) ){
            bibPoint = 1;
            bibSuit = (suit[2] >= suit[3] ? 2 : 3);
        }
    }
    if(20 <= HCP && HCP <= 21){
        bibPoint = 2;
        bibSuit = 4;
    }
    if(16 <= HCP && HCP <=18){
        bibPoint = 1;
        bibSuit = 4;
    }
    if(13 <= HCP && HCP <= 21){
        if( (suit[0] >= 5 || suit[1] >= 5) && (suit[0] == mostHolding || suit[1] == mostHolding)){
            bibPoint = 1;
            bibSuit = (suit[0] >= suit[1] ? 0 : 1);
        }
    }
    if(22 <= HCP){
        bibPoint = 2;
        bibSuit = 3;
    }

    if(bibPoint == 0){
        printf("The bidding choice : Pass\n");
    }
    else{
        printf("The bidding choice : %hhd %s\n", bibPoint, suitName[bibSuit]);
    }

}

/* 10  11  12  13  14  15  16  17  18  19  20  21  22
                                                   2C -------
                -----------1S1H1D1C------------- 
                            --1NT---
                                            -2NT
    3S3H3D3C
    -2S2H2D-
*/