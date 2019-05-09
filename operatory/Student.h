//
// Created by falcon on 4/14/19.
//
#ifndef regexec
#include <regex>
#endif
#ifndef STRING
#include <string>
#endif
#ifndef OPERATORY_STUDYYEAR_H
#include "StudyYear.h"
#endif
#ifndef OPERATORY_STUDENTREPOSITORY_H
class StudentRepository;

#endif
#ifndef OPERATORY_STUDENT_H
#define OPERATORY_STUDENT_H
using ::std::string;
using ::std::regex;
using ::std::regex_search;
using ::std::smatch;
enum PD{ID,FIRST_NAME,LAST_NAME,PROGRAM,YEAR};
class Student {
private:
    string id;
    string f_name;
    string l_name;
    string program;
    StudyYear year;
public:
    void about();
    friend StudentRepository;
    explicit Student(const string& student="");
    std::istream &operator>> (std::istream& );

};


#endif //OPERATORY_STUDENT_H
