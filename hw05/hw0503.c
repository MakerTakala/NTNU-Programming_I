#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include "polynomial.h" 

int main(){
    int64_t p1Degree = 0, p2Degree = 0;
    int64_t p1Coefficient[101] = {0}, p2Coefficient[101] = {0};

    ask_degree_input("Please enter p1 degree: ", &p1Degree);
    ask_array_input("Please enter p1 coefficients: ", p1Coefficient, p1Degree);
    ask_degree_input("Please enter p2 degree: ", &p2Degree);
    ask_array_input("Please enter p2 coefficients: ", p2Coefficient, p2Degree);

    printf("p1: ");
    print_polynomial(p1Coefficient, p1Degree);
    printf("p2: ");
    print_polynomial(p2Coefficient, p2Degree);
    
    add( p1Coefficient, p2Coefficient, (int64_t)fmax(p1Degree, p2Degree) );
    sub( p1Coefficient, p2Coefficient, (int64_t)fmax(p1Degree, p2Degree) );
    mul( p1Coefficient, p2Coefficient, p1Degree, p2Degree );


    return 0;
}