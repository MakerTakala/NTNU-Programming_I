#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int32_t x;
    int32_t y;
}Point;

bool is_parallel(Point point1, Point point2, Point point3){
    double m1 = (double)(point1.y - point2.y) / (double)(point1.x - point2.x);
    double m2 = (double)(point2.y - point3.y) / (double)(point2.x - point3.x);
    return m1 == m2;
}

long double edge_len(Point point1, Point point2){
    long double delta_x = fabsl(point1.x - point2.x);
    long double delta_y = fabsl(point1.y - point2.y);
    return sqrtl(delta_x * delta_x + delta_y * delta_y);
}

long double get_area(long double line1, long double line2, long double line3){
    long double s = (line1 + line2 + line3) / 2.0;
    return sqrtl(s) * sqrtl(s - line1) * sqrtl(s - line2) * sqrtl(s - line3);
}

int main(){
    Point point[5];
    for(int i = 0; i < 5; i++){
        printf("Please enter P%d: ", i + 1);
        scanf("%d,%d", &point[i].x, &point[i].y);
    }
    for(int i = 0; i < 5; i++){
        if(is_parallel(point[i], point[(i + 1) % 5], point[(i + 2) % 5])){
            printf("%d", i);
            printf("This is not a pentagon.\n");
            exit(0);
        }
    }
    long double area1 = get_area(edge_len(point[0], point[1]), edge_len(point[1], point[2]), edge_len(point[2], point[0]));
    long double area2 = get_area(edge_len(point[0], point[2]), edge_len(point[2], point[3]), edge_len(point[3], point[0]));
    long double area3 = get_area(edge_len(point[0], point[3]), edge_len(point[3], point[4]), edge_len(point[4], point[0]));
    printf("%Lf\n", area1 + area2 + area3);
    return 0;
}