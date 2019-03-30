//
// Created by falcon on 3/26/19.
//

#ifndef CZIWC4_SQUARE_H
#define CZIWC4_SQUARE_H

#include <vector>
#include <iostream>
#include <sstream>
#include "Point.h"
class Square {
private:
//    std::vector <Point> Edges;
    Point rigth_edge;
    Point left_edge;
    double Area;
    double Circumference;
public:
    Square(double,double,double,double );
    void CArea();
    void CCircumference();
    void Show();
};


#endif //CZIWC4_SQUARE_H
