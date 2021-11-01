#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

int8_t inputCard(int8_t []);
int8_t HCPCounter(bool []);
void HCPandSuitOutput(int8_t, int8_t []);
void bibbingChoice(int8_t, int8_t []);

int main(){
    int8_t suit[4] = {0};
    int8_t HCP = inputCard(suit);
    HCPandSuitOutput(HCP, suit);
    bibbingChoice(HCP, suit);
    
    return 0;
}

int8_t inputCard(int8_t suit[]){
    int32_t inputCard = 0;
    int8_t HCP = 0;
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
        suit[(inputCard - 1) / 13]++;
        int8_t point = (inputCard - 1) % 13 + 1;
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
    return HCP;
}

void HCPandSuitOutput(int8_t HCP, int8_t suit[]){
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
    int8_t bibPoint = 0, bibSuit = 0, mostHoldingcard = 0, mostHoldingsuit = 0;;

    for(int8_t i = 0; i < 4; i++){
        if(suit[i] > mostHoldingcard){
            mostHoldingcard = suit[i];
            mostHoldingsuit = i;
        }
    }

    if(10 <= HCP && HCP <= 12){
        if(mostHoldingsuit != 3 && mostHoldingcard >= 6){
            bibPoint = 2;
            bibSuit = mostHoldingsuit;
        }
        if(mostHoldingcard >= 7){
            bibPoint = 3;
            bibSuit = mostHoldingsuit;
        }
    }
    if(13 <= HCP && HCP <= 21){
        if( (mostHoldingcard == suit[2] || mostHoldingcard == suit[3]) && mostHoldingcard >= 3 ){
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
        if( (mostHoldingsuit == 0 || mostHoldingsuit == 1) && mostHoldingcard >= 5){
            bibPoint = 1;
            bibSuit = mostHoldingsuit;
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
