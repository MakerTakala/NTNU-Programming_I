#include <stdio.h>
#include <stdint.h>

int main(){
    int64_t a = 0, b = 0, c = 0;
    printf("Please enter a quadratic polynomial (a,b,c): ");
    scanf("%ld,%ld,%ld", &a, &b, &c);
    if(a == 0){
        printf("\nWrong Input!!!\n");
        printf("----------------------------------------------------------\n\n");
        return 0;
    }
    int64_t discriminant = b * b - 4 * a * c;
    if(discriminant > 0){
        printf("Two distinct real roots.\n");
    }
    else if(discriminant < 0){
        printf("No real roots.\n");
    }
    else{
        printf("One real root.\n");
    }
    return 0;
}