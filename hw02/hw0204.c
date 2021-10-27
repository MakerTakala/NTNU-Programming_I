#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void wrongInput();
int64_t askWordCount();
int32_t askServiceLevel();
int32_t askDeliveryTime();
double proofreadingFee[3][4] = {{3.4, 3.8, 4.2, 4.6}, {1.4, 2.0, 2.3, 2.6}, {1.1, 1.2, 1.5, 2.0}};


int main(){
    int64_t wordCount = askWordCount();
    int32_t serviceLevel = askServiceLevel();
    int32_t deliveryTime = askDeliveryTime();
    double originalPrice = wordCount * proofreadingFee[serviceLevel - 1][deliveryTime - 1];
    int64_t discountPrice = 0;
    if(serviceLevel == 1 && wordCount >= 2000){
        discountPrice = originalPrice * 0.75;
    }
    else if(serviceLevel == 2 && wordCount >= 6000){
        discountPrice = originalPrice * 0.9;
    }
    else if(serviceLevel == 3 && wordCount >= 6000){
        discountPrice = originalPrice * 0.95;
    }
    else{
        discountPrice = originalPrice;
    }
    return 0;
}

void wrongInput(){
    printf("\nWrong Input!!!\n");
    printf("----------------------------------------------------------\n\n");
    exit(0);
}

int64_t askWordCount(){
    int64_t wordCount = 0;
    printf("Word Count\n");
    printf("  Please enter the word count : ");
    scanf("%ld", &wordCount);
    if(wordCount < 0){
        wrongInput();
    }
    return wordCount;
}

int32_t askServiceLevel(){
    int32_t serviceLevel = 0;
    printf("Service Level\n");
    printf("  1) Advanced service\n");
    printf("  2) Standard service\n");
    printf("  3) Basic service\n");
    printf("Your choice : ");
    scanf("%d", &serviceLevel);
    if(serviceLevel < 1 || 3 < serviceLevel){
        wrongInput();
    }
    return serviceLevel;
}

int32_t askDeliveryTime(){
    int32_t deliveryTime = 0;
    printf("Delivery Time\n");
    printf("  1) Economic\n");
    printf("  2) Standard\n");
    printf("  3) Fast\n");
    printf("  4) Deadline\n");
    printf("Your choice : ");
    scanf("%d", &deliveryTime);
    if(deliveryTime < 1 || 4 < deliveryTime){
        wrongInput();
    }
    return deliveryTime;
}