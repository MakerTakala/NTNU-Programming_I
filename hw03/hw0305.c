#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    int64_t year[100000] = {0};
    long double temperature[100000] = {0};
    int64_t sampleQuantity = 0, sumYear = 0;
    long double sumTemperature = 0;

    while(true){
        printf("Please enter the year: ");
        scanf("%ld", &year[sampleQuantity]);
        if(year[sampleQuantity] == -1){
            break;
        }
        if(year[sampleQuantity] < 1900){
            printf("\nWrong Input!!!\n");
            printf("----------------------------------------------------------\n\n");
            exit(0);
        }
        printf("Temperature: ");
        scanf("%Lf", &temperature[sampleQuantity]);
        if(temperature[sampleQuantity] < -273.15){
            printf("\nWrong Input!!!\n");
            printf("----------------------------------------------------------\n\n");
            exit(0);
        }

        sumYear += year[sampleQuantity];
        sumTemperature += temperature[sampleQuantity];

        sampleQuantity++;
    }

    if(sampleQuantity < 2){
        printf("\nThe amount of data is not enough to predict.\n");
        printf("----------------------------------------------------------\n\n");
        exit(0);
    }

    //calculate regression line
    long double Sxy = 0, Sxx = 0;
    long double averageYear = sumYear / sampleQuantity, averageTemperature = sumTemperature / sampleQuantity;
    for(int i = 0; i < sampleQuantity; i++){
        double Xi = year[i] - averageYear , Yi = temperature[i] - averageTemperature;
        Sxy += Xi * Yi;
        Sxx += Xi * Xi;
    }
    long double slope = Sxy / Sxx, intercept = averageTemperature - (slope * averageYear + 0.000001);

    int64_t predictYear = 0;
    printf("Please enter the prediction year: ");
    scanf("%ld", &predictYear);
    long double predictTemperature = predictYear * slope + intercept + 0.000001;
    printf("Temperature: %.4Lf\n", predictTemperature);
    return 0;
}