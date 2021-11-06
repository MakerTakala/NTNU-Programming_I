#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int64_t inputNumber = 0;

void intoNewBlock();
void start();
void s1();
void s2();
void s3();
void s4();
void s5();
void s6();
void final();

int main(){
    start();
    return 0;
}

void intoNewBlock(){
    printf("Please enter an integer: ");
    scanf("%ld", &inputNumber);
    return;
}

void start(){
    printf("Start\n");
    intoNewBlock();
    if(inputNumber == 10 || inputNumber == 35){
        s1();
    }
    else if(inputNumber == 11){
        s3();
    }
    else if(inputNumber == 20 || inputNumber == 78){
        s5();
    }
    else{
        start();
    }
    return;
}

void s1(){
    printf("S1\n");
    intoNewBlock();
    if(inputNumber == 19){
        s2();
    }
    else if(inputNumber == 12 || inputNumber == 36){
        s6();
    }
    else{
        s1();
    }
    return;
}

void s2(){
    printf("S2\n");
    intoNewBlock();
    if(inputNumber == 43){
        s2();
    }
    else if(inputNumber == 99){
        final();
    }
    else{
        start();
    }
    return;
}

void s3(){
    printf("S3\n");
    intoNewBlock();
    s4();
    return;
}

void s4(){
    printf("S4\n");
    intoNewBlock();
    s6();
    return;
}

void s5(){
    printf("S5\n");
    intoNewBlock();
    if(inputNumber == 1){
        s4();
    }
    else if(inputNumber == 2){
        s6();
    }
    else{
        start();
    }
    return;
}

void s6(){
    printf("S6\n");
    intoNewBlock();
    if(inputNumber == 108){
        final();
    }
    else{
        s5();
    }
    return;
}
void final(){
    printf("Final\n");
    exit(0);
}