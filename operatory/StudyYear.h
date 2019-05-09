//
// Created by falcon on 4/14/19.
//
#ifndef IOSTREAM_NAMESPACE

#include <iostream>
#endif

#ifndef OPERATORY_STUDYYEAR_H
#define OPERATORY_STUDYYEAR_H


class StudyYear {
private:
    int studyYear;
public:
    explicit StudyYear(int yr = 0 ){studyYear = yr;};
    StudyYear& operator++();
    StudyYear& operator--();
    StudyYear(const StudyYear&);
    std::istream & operator>>(std::istream&);
    int year(){return studyYear;}
    bool operator==(StudyYear&);
};


#endif //OPERATORY_STUDYYEAR_H
