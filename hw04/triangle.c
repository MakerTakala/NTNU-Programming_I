#include <math.h>
#include <stdlib.h>
#include <stdint.h>
#include "triangle.h"
#define eps 1e-8

static point point1, point2, point3;

int8_t successInput = 0;

//when user input a new point, if input invalid, return 0
//x y means the input number, p means the input point
int set_point_check( double x, double y, int8_t p){
    //setpoint == 0
    if(successInput == 0){
        return 1;
    }
    //setpoint == 1 && point1 has been set
    if(successInput == 1){
        if(p == 1){
            return 1;
        }
        else{
            return (x != point1.x || y != point1.y);
        }
    }
    //setpoint == 1 && point2 has been set
    if(successInput == 2){
        if(p == 2){
            return 1;
        }
        else{
            return (x != point2.x || y != point2.y);
        }
    }
    //setpoint == 1 && point3 has been set
    if(successInput == 4){
        if(p == 3){
            return 1;
        }
        else{
            return (x != point3.x || y != point3.y);
        }
    }

    //setpoint == 2 && point1 & point2 has been set
    if(successInput == 3){
        if(p == 1){
            return (x != point2.x || y == point2.y);
        }
        if(p == 2){
            return (x != point1.x || y == point1.y);
        }
        if(p == 3){
            return fabs( (y - point1.y) * (point2.x - point1.x) - (point2.y - point1.y) * (x - point1.x) ) > eps;
        }
    }
    //setpoint == 2 && point1 & point3 has been set
    if(successInput == 5){
        if(p == 1){
            return (x != point3.x || y == point3.y);
        }
        if(p == 2){
            return fabs( (y - point1.y) * (point3.x - point1.x) - (point3.y - point1.y) * (x - point1.x) ) > eps;
        }
        if(p == 3){
            return (x != point1.x || y == point1.y);
        }
    }
    //setpoint == 2 && point2 & point3 has been set
    if(successInput == 6){
        if(p == 1){
            return fabs( (y - point2.y) * (point3.x - point2.x) - (point3.y - point2.y) * (x - point2.x) ) > eps;
        }
        if(p == 2){
            return (x != point3.x || y == point3.y);
        }
        if(p == 3){
            return (x != point2.x || y == point2.y);
        }
    }
    if(successInput == 7){
        if(p == 1){
            return fabs( (y - point2.y) * (point3.x - point2.x) - (point3.y - point2.y) * (x - point2.x) ) > eps;
        }
        if(p == 2){
            return fabs( (y - point1.y) * (point3.x - point1.x) - (point3.y - point1.y) * (x - point1.x) ) > eps;
        }
        if(p == 3){
            return fabs( (y - point1.y) * (point2.x - point1.x) - (point2.y - point1.y) * (x - point1.x) ) > eps;
        }
    }
}

int set_1_point( double x, double y){
    if(set_point_check(x, y, 1) == 1){
        point1.x = x;
        point1.y = y;
        successInput |= (1 << 0);
        return 1;
    }
    else{
        return 0;
    }
}
int set_2_point( double x, double y){
    if(set_point_check(x, y, 2) == 1){
        point2.x = x;
        point2.y = y;
        successInput |= (1 << 1);
        return 1;
    }
    else{
        return 0;
    }
}
int set_3_point( double x, double y){
    if(set_point_check(x, y, 3) == 1){
        point3.x = x;
        point3.y = y;
        successInput |= (1 << 2);
        return 1;
    }
    else{
        return 0;
    }
}

int check( void ){
    if(successInput == 7){
        return 1;
    }
    else{
        return 0;
    }
}

double get_perimeter( void ){
    if(check() == 1){
        return get_side_length(point1, point2) + get_side_length(point2, point3) + get_side_length(point3, point1);
    }
    else{
        return -1;
    }
}

double get_area( void ){
    if(check() == 1){
        return fabs( 0.5 * ( (point1.x * point2.y + point2.x * point3.y + point3.x * point1.y) - \
                             (point3.x * point2.y + point2.x * point1.y + point1.x * point3.y) ) );
    }
    else{
        return -1;
    }
}

double get_1_degree( void ){

    if(check() == 1){
        double main_line = get_side_length(point2, point3), side_line1 = get_side_length(point1, point2), side_line2 = get_side_length(point1, point3);
        return acos( ( main_line * main_line - side_line1 * side_line1 - side_line2 * side_line2) / (-2.0 * side_line1 * side_line2) ) / M_PI * 180;
    }
    else{
        return -1;
    }
}
double get_2_degree( void ){
    if(check() == 1){
        double main_line = get_side_length(point1, point3), side_line1 = get_side_length(point2, point1), side_line2 = get_side_length(point2, point3);
        return acos( ( main_line * main_line - side_line1 * side_line1 - side_line2 * side_line2) / (-2.0 * side_line1 * side_line2) ) / M_PI * 180;
    }
    else{
        return -1;
    }
}
double get_3_degree( void ){
    if(check() == 1){
        double main_line = get_side_length(point1, point2), side_line1 = get_side_length(point3, point1), side_line2 = get_side_length(point3, point2);
        return acos( ( main_line * main_line - side_line1 * side_line1 - side_line2 * side_line2) / (-2.0 * side_line1 * side_line2) ) / M_PI * 180;
    }
    else{
        return -1;
    }
}

double get_inscribed_center_x( void ){
    if(check() == 1){
        double line1 = get_side_length(point2, point3), line2 = get_side_length(point1, point3), line3 = get_side_length(point1, point2);
        return (point1.x * line1 + point2.x * line2 + point3.x * line3) / (line1 + line2 + line3);
    }
    else{
        return 0;
    }
}
double get_inscribed_center_y( void ){
    if(check() == 1){
        double line1 = get_side_length(point2, point3), line2 = get_side_length(point1, point3), line3 = get_side_length(point1, point2);
        return (point1.y * line1 + point2.y * line2 + point3.y * line3) / (line1 + line2 + line3);
    }
    else{
        return 0;
    }
}
double get_inscribed_center_area( void ){
    if(check() == 1){
        double inscribed_circle_radius = 2 * get_area() / get_perimeter();
        return inscribed_circle_radius * inscribed_circle_radius * M_PI;
    }
    else{
        return -1;
    }
}
double get_circumscribed_center_x( void ){
    if(check() == 1){
        double denominator = 2 * ( (point1.x * point2.y + point2.x * point3.y + point3.x * point1.y) - (point3.x * point2.y + point2.x * point1.y + point1.x * point3.y) );
        double molecular = (point1.x * point1.x + point1.y * point1.y) * point2.y + \
                           (point2.x * point2.x + point2.y * point2.y) * point3.y + \
                           (point3.x * point3.x + point3.y * point3.y) * point1.y - \
                           (point3.x * point3.x + point3.y * point3.y) * point2.y - \
                           (point2.x * point2.x + point2.y * point2.y) * point1.y - \
                           (point1.x * point1.x + point1.y * point1.y) * point3.y ;
        return molecular / denominator;
    }
    else{
        return 0;
    }
}
double get_circumscribed_center_y( void ){
    if(check() == 1){
        double denominator = 2 * ( (point1.x * point2.y + point2.x * point3.y + point3.x * point1.y) - (point3.x * point2.y + point2.x * point1.y + point1.x * point3.y) );
        double molecular = (point1.x * point1.x + point1.y * point1.y) * point3.x + \
                           (point2.x * point2.x + point2.y * point2.y) * point1.x + \
                           (point3.x * point3.x + point3.y * point3.y) * point2.x - \
                           (point3.x * point3.x + point3.y * point3.y) * point2.x - \
                           (point2.x * point2.x + point2.y * point2.y) * point3.x - \
                           (point1.x * point1.x + point1.y * point1.y) * point1.x ;
        return molecular / denominator;
    }
    else{
        return 0;
    }
}
double get_circumscribed_center_area( void ){
    if(check() == 1){
        double line = get_side_length(point2, point3);
        double circumscribed_center_radius = line / sin( get_1_degree() / 180 * M_PI  * 0.5);
        return circumscribed_center_radius * circumscribed_center_radius * M_PI;
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