#include <math.h>
#include <stdlib.h>
#include "triangle.h"
#define eps 1e-8

static point point1 = {0, 0}, point2 = {0, 0}, point3 = {0, 0};

int set_1_point( double x, double y){
    point1.x = x;
    point1.y = y;
    return 1;
}
int set_2_point( double x, double y){
    point2.x = x;
    point2.y = y;
    return 1;
}
int set_3_point( double x, double y){
    point3.x = x;
    point3.y = y;
    return 1;
}


int check( void ){
    double line1 = get_side_length(point2, point3), line2 = get_side_length(point1, point3), line3 = get_side_length(point1, point2);
    if(line1 + line2 > line3 && line2 + line3 > line1 && line3 + line1 > line2){
        return 1;
    }
    else{
        return 0;
    }
}

double get_perimeter( void ){
    double perimeter = get_side_length(point1, point2) + get_side_length(point2, point3) + get_side_length(point3, point1);
    if(check() == 1){
        return perimeter;
    }
    else{
        return -1;
    }
}

double get_area( void ){
    double area = fabs( 0.5 * ( (point1.x * point2.y + point2.x * point3.y + point3.x * point1.y) - \
                                (point3.x * point2.y + point2.x * point1.y + point1.x * point3.y) ) );
    if(check() == 1){
        return area;
    }
    else{
        return -1;
    }
}

double get_1_degree( void ){
    double main_line = get_side_length(point2, point3), side_line1 = get_side_length(point1, point2), side_line2 = get_side_length(point1, point3);
    double degree = acos( ( main_line * main_line - side_line1 * side_line1 - side_line2 * side_line2) / (-2.0 * side_line1 * side_line2) ) / M_PI * 180;
    if(check() == 1){
        return degree;
    }
    else{
        return -1;
    }
}
double get_2_degree( void ){
    double main_line = get_side_length(point1, point3), side_line1 = get_side_length(point2, point1), side_line2 = get_side_length(point2, point3);
    double degree = acos( ( main_line * main_line - side_line1 * side_line1 - side_line2 * side_line2) / (-2.0 * side_line1 * side_line2) ) / M_PI * 180;
    if(check() == 1){
        return degree;
    }
    else{
        return -1;
    }
}
double get_3_degree( void ){
    double main_line = get_side_length(point1, point2), side_line1 = get_side_length(point3, point1), side_line2 = get_side_length(point3, point1);
    double degree = acos( ( main_line * main_line - side_line1 * side_line1 - side_line2 * side_line2) / (-2.0 * side_line1 * side_line2) ) / M_PI * 180;
    if(check() == 1){
        return degree;
    }
    else{
        return -1;
    }
}

double get_inscribed_center_x( void ){
    double line1 = get_side_length(point2, point3), line2 = get_side_length(point1, point3), line3 = get_side_length(point1, point2);
    double inscribed_center_x = (point1.x * line1 + point2.x * line2 + point3.x * line3) / (line1 + line2 + line3);
    if(check() == 1){
        return inscribed_center_x;
    }
    else{
        return 0;
    }
}
double get_inscribed_center_y( void ){
    double line1 = get_side_length(point2, point3), line2 = get_side_length(point1, point3), line3 = get_side_length(point1, point2);
    double inscribed_center_y = (point1.y * line1 + point2.y * line2 + point3.y * line3) / (line1 + line2 + line3);
    if(check() == 1){
        return inscribed_center_y;
    }
    else{
        return 0;
    }
}
double get_inscribed_center_area( void ){
    double inscribed_circle_radius = 2 * get_area() / get_perimeter();
    double inscribed_circle_area = inscribed_circle_radius * inscribed_circle_radius * M_PI;
    if(check() == 1){
        return inscribed_circle_area;
    }
    else{
        return -1;
    }
}
double get_circumscribed_center_x( void ){
    double denominator = 2 * ( (point1.x * point2.y + point2.x * point3.y + point3.x * point1.y) - (point3.x * point2.y + point2.x * point1.y + point1.x * point3.y) );
    double molecular = (point1.x * point1.x + point1.y * point1.y) * point2.y + \
                       (point2.x * point2.x + point2.y * point2.y) * point3.y + \
                       (point3.x * point3.x + point3.y * point3.y) * point1.y - \
                       (point3.x * point3.x + point3.y * point3.y) * point2.y - \
                       (point2.x * point2.x + point2.y * point2.y) * point1.y - \
                       (point1.x * point1.x + point1.y * point1.y) * point3.y ;
    double circumscribed_center_x = molecular / denominator;
    if(check() == 1){
        return circumscribed_center_x;
    }
    else{
        return 0;
    }
}
double get_circumscribed_center_y( void ){
    double denominator = 2 * ( (point1.x * point2.y + point2.x * point3.y + point3.x * point1.y) - (point3.x * point2.y + point2.x * point1.y + point1.x * point3.y) );
    double molecular = (point1.x * point1.x + point1.y * point1.y) * point3.x + \
                       (point2.x * point2.x + point2.y * point2.y) * point1.x + \
                       (point3.x * point3.x + point3.y * point3.y) * point2.x - \
                       (point3.x * point3.x + point3.y * point3.y) * point2.x - \
                       (point2.x * point2.x + point2.y * point2.y) * point3.x - \
                       (point1.x * point1.x + point1.y * point1.y) * point1.x ;
    double circumscribed_center_y = molecular / denominator;
    if(check() == 1){
        return circumscribed_center_y;
    }
    else{
        return 0;
    }
}
double get_circumscribed_center_area( void ){
    double line = get_side_length(point2, point3);
    double circumscribed_center_radius = line / sin( get_1_degree() / 180 * M_PI  * 0.5);
    double circumscribed_center_area = circumscribed_center_radius * circumscribed_center_radius * M_PI;
    if(check() == 1){
        return circumscribed_center_area;
    }
    else{
        return -1;
    }
}

double get_side_length(point p1, point p2){
    double delta_x = fabs(p1.x - p2.x);
    double delta_y = fabs(p1.y - p2.y);
    return sqrt(delta_x * delta_x + delta_y * delta_y);
}