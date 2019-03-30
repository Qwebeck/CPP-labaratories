//
// Created by falcon on 3/26/19.
//

#include "Square.h"
#include <vector>
#include <iostream>
using ::std::vector;
Square::Square(double x_t_l , double y_t_l , double x_t_r , double y_t_r)  {
    rigth_edge = Point(x_t_l, y_t_l);
    left_edge = Point (x_t_r , y_t_r);
//    Point L_B_Edge(x_b_l,y_b_l);
//    Point R_B_Edge(x_b_r,y_b_r);
//
}
void Square::CArea() {
    Area = rigth_edge.Distance(left_edge) * rigth_edge.Distance(left_edge);
}
void Square::CCircumference() {
    Circumference = rigth_edge.Distance(left_edge) * 4;
}
void Square::Show() {
    std::cout << "Pole : " << Area << std::endl;
    std::cout  << Circumference;
}