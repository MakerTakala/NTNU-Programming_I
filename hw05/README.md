# Homework05 41047025 王重鈞

## 4.1 Big Two
---
It is a library named poker, there is a function big_two_sort you can use.
    int32_t big_two_sort( int8_t cards[] );
This function only allow an int8_t array with 13 size.It will sort you array and return it.
If the input is invalid, please return -1; otherwise,return 0.

## 4.2 Statistics
---
It is a library named poker, there are some functions you can use.
    double get_mean( const int32_t input[], size_t size );
    double get_median( const int32_t input[], size_t size );
    int32_t get_mode( const int32_t input[], size_t size );
    double get_stddev( const int32_t input[], size_t size );
get_mean will return mean in the array.
get_median will return median in the array.
get_mode will return mdeian in the array.
get_stddev wiil return median in the array.

## 4.3 Polynomial Calculator
---
This ia a Polynomial Calculator, please input two polynomial and it degree.
Any input invaild will make the program  print "Wrong Input!" as warning and terminate the program.

## 4.4 Banqi
---
This a Banqi game. Please obey following rules.
1. 1(A) > 2(B) > 3(C) > 4(D) > 5(E) > 6(F) > 7(G); 7(G) > 1(A)
2. If Player choose a chess which can move, this round will be pass.
3. 6(F) has special move and eat rule, please follow the rules on wiki.
4. If there isn't any eat and filp chess in 50 septs, this game will be TIE.
5. Frist Player eat all another Player chess, Player WIN.
