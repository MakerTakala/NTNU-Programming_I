#include <stdio.h>
#include <stdint.h>
#include "polynomial.h" 

int main(){
    int64_t p1Degree = 0, p2Degree = 0;

    ask_input("Please enter p1 degree: ", &p1Degree);
    int64_t p1Coefficient[p1Degree + 1];
    ask_array_input("Please enter p1 coefficients: ", p1Coefficient, p1Degree + 1);

    ask_input("Please enter p2 degree: ", &p2Degree);
    int64_t p2Coefficient[p2Degree + 1];
    ask_array_input("Please enter p1 coefficients: ", p2Coefficient, p2Degree + 1);

    
    return 0;
}