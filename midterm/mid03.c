#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include "midfunction.h"
#define PI acos(-1);

int main(){
    double incidenceAngle = 0;
    int64_t layers = 0;
    printf("Incidence angle: ");
    scanf("%lf", &incidenceAngle);
    if(incidenceAngle < 0 || 90 < incidenceAngle){
        errorMessageExit("Wrong Input");
    }
    printf("How many layers: ");
    scanf("%ld", &layers);
    if(layers < 1){
        errorMessageExit("Wrong Input");
    }
    incidenceAngle = incidenceAngle / 180 * PI;

    double referactiveIndex = 0, height = 0, preReferactiveIndex = 1.0;
    double ans = 0;
    for(int32_t i = 1; i <= layers; i++){
        printf("Layer %d's refractive index: ", i);
        scanf("%lf", & referactiveIndex);
        if(referactiveIndex < 1){
            errorMessageExit("Wrong Input");
        }
        printf("Layer %d's height: ", i);
        scanf("%lf", &height);
        incidenceAngle = asin(sin(incidenceAngle) * preReferactiveIndex / referactiveIndex);
        ans += tan(incidenceAngle) * height;
        preReferactiveIndex = referactiveIndex;
    }

    printf("The shift: %lf\n", ans);
    return 0;
}