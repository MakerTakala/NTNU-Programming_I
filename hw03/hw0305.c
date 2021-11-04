#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    int64_t year[1000] = {0};
    double temperature[1000] = {0};
    int64_t sampleQuantity = 0, sumYear = 0;
    double sumTempreature = 0;

    //input necessary information
    while(true){
        printf("Please enter the year: ");
        scanf("%ld", &year[sampleQuantity]);
        if(year[sampleQuantity] == -1){
            break;
        }
        if(year[sampleQuantity] <= 0){
            printf("\nWrong Input!!!\n");
            printf("----------------------------------------------------------\n\n");
            exit(0);
        }
        printf("Temperature: ");
        scanf("%lf", &temperature[sampleQuantity]);

        sumYear += year[sampleQuantity];
        sumTempreature += temperature[sampleQuantity];

        sampleQuantity++;
    }

    if(sampleQuantity <= 1){
        printf("\nNot enough Input!!!\n");
        printf("----------------------------------------------------------\n\n");
        exit(0);
    }

    //calculate regression line
    double Sxy = 0, Sxx = 0;
    double averageYear = sumYear / sampleQuantity, averageTemperature = sumTempreature / sampleQuantity;
    for(int i = 0; i < sampleQuantity; i++){
        double Xi = year[i] - averageYear , Yi = temperature[i] - averageTemperature;
        Sxy += Xi * Yi;
        Sxx += Xi * Xi;
    }
    long double slope = Sxy / Sxx, intercept = temperature[0] - slope * year[0];

    int64_t predictYear = 0;
    printf("Please enter the prediction year: ");
    scanf("%ld", &predictYear);
    double predictTemperature = predictYear * slope + intercept;
    printf("[debug]intercept %Lf\n", intercept);
    printf("Temperature: %lf\n", predictTemperature);
    return 0;
}