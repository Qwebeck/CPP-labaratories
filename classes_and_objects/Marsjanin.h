//
// Created by falcon on 4/8/19.
//
#ifndef IOSTREAM_NAMESPACE

#include <iostream>

#endif
#ifndef CLASSES_AND_OBJECTS_MARSJANIN_H
#define CLASSES_AND_OBJECTS_MARSJANIN_H


#include <search.h>

class Marsjanin {
public:
    static int number;
    Marsjanin(){number++;}
    Marsjanin(const Marsjanin& other) = default;
    ~Marsjanin(){std::cout << "Destructor called " << std::endl;}
    void Action();

};


#endif //CLASSES_AND_OBJECTS_MARSJANIN_H
