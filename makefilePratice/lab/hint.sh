# dynamic link main object with math & qdbmp library under current path
gcc -g -o main main.c -lqdbmp -lm -L. -Wl,-rpath,`pwd`
