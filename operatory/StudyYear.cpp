//
// Created by falcon on 4/14/19.
//

#include "StudyYear.h"
StudyYear& StudyYear::operator++() {
    ++studyYear;
    return *this;
}
StudyYear& StudyYear::operator--() {
    --studyYear;
    return *this;
}

std::istream &StudyYear::operator>>(std::istream & stream) {
    stream >> this -> studyYear;

    return stream;
}

StudyYear::StudyYear(const StudyYear &old) {
    studyYear = old.studyYear;
}

bool StudyYear::operator==(StudyYear &other) {
    return this -> studyYear == other.studyYear;
}
