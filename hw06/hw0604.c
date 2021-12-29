#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int64_t num = 0;

void into_new_block();
void Start();
void S1();
void S2();
void S3();
void S4();
void S5();
void S6();
void Final();


int main(){
    Start();
    return 0;
}

void into_new_block(){
    printf("Please enter an integer: ");
    scanf("%ld", &num);
}

void Start(){
    printf("Start\n");
    into_new_block();
    int8_t next = (num == 10 || num == 35) * 1 + (num == 11) * 2 + (num == 20 || num == 78) * 3;
    void(*fuc_next[4])() = {Start, S1, S3, S5};
    fuc_next[next]();
}

void S1(){
    printf("S1\n");
    into_new_block();
    int8_t next = (num == 19) * 1 + (num == 12 || num == 36) * 2;
    void(*fuc_next[3])() = {S1, S2, S6};
    fuc_next[next]();
}

void S2(){
    printf("S2\n");
    into_new_block();
    int8_t next = (num == 43) * 1 + (num == 99) * 2;
    void(*fuc_next[3])() = {Start, S2, Final};
    fuc_next[next]();
}

void S3(){
    printf("S3\n");
    into_new_block();
    S4();
}

void S4(){
    printf("S4\n");
    into_new_block();
    S6();
}

void S5(){
    printf("S5\n");
    into_new_block();
    int8_t next = (num == 1) * 1 + (num == 2) * 2;
    void(*fuc_next[3])() = {Start, S4, S6};
    fuc_next[next]();
}

void S6(){
    printf("S6\n");
    into_new_block();
    int8_t next = (num == 108) * 1;
    void(*fuc_next[4])() = {S5, Final};
    fuc_next[next]();
}

void Final(){
    printf("Final\n");
    exit(0);
}