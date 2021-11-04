#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(){
    int64_t year[1000] = 0;
    double temperature[1000] = 0;
    int16_t sampleQuantity;

    while(true){
        printf("Please enter the year: ");
        scanf("%ld", &year[sampleQuantity]);
        if(year == -1){
            break;
        }
        if(year <= 0){
            exit(0);
        }
        printf("Temperature: ");
        scanf("%lf", &temperature[sampleQuantity]);
        sampleQuantity++;
    }

    double Sxy = 0, Sxx = 0;
    double averageX = 0 averageX = 0;

    int64_t predictYear = 0;
    printf("Please enter the prediction year: ");
    scanf("%ld", &year);

    return 0;
}