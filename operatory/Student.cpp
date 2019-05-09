//
// Created by falcon on 4/14/19.
//

#include "Student.h"

std::istream &Student::operator>>(std::istream & stream) {
    string tmp;
//    stream >> tmp;
    getline(stream , tmp);
    regex data(R"(\"(\w+[^:|"]|\d+)\"|(\d+))");
    smatch matches;
    int i = 0;
    while (regex_search(tmp,matches,data))
    {
        switch (i)
        {
            case ID:
                id = matches[1];
                break;
            case FIRST_NAME:
                f_name = matches[1];
                break;
            case LAST_NAME:
                l_name = matches[1];
            case PROGRAM:
                program = matches[1];
                break;
            case YEAR:
                year = StudyYear(std::stoi(matches[2]));
            default:
                break;
        }
        tmp = matches.suffix().str();
        ++i;
    };
    return stream;
}

void Student::about() {
    std::cout<< "ID: " << id << std::endl << "First name: " << f_name << std::endl << "Programm: " << program << std::endl <<"Study year: " << year.year() <<std::endl;


}

Student::Student(const string & student) {
    string tmp = student;
    regex data(R"(\"(\w+[^:|"]|\d+)\"|(\d+))");
    smatch matches;
    int i = 0;
    while (regex_search(tmp,matches,data))
    {
        switch (i)
        {
            case ID:
                id = matches[1];
                break;
            case FIRST_NAME:
                f_name = matches[1];
                break;
            case LAST_NAME:
                l_name = matches[1];
            case PROGRAM:
                program = matches[1];
                break;
            case YEAR:
                year = StudyYear(std::stoi(matches[2]));
            default:
                break;
        }
        tmp = matches.suffix().str();
        ++i;
    };

}
