//
// Created by falcon on 4/14/19.
//

#ifndef optional
#include <experimental/optional>
#endif
#ifndef vector
#include <vector>
#endif
#ifndef OPERATORY_STUDENT_H
#include "Student.h"
#endif

#ifndef OPERATORY_STUDENTREPOSITORY_H
#define OPERATORY_STUDENTREPOSITORY_H

using ::std::vector;
using ::std::experimental::optional;
class StudentRepository {
private:
    vector<Student> Students;
public:
    std::istream&operator>>(std::istream& stream);
    Student* operator[](const string&);
    bool operator==(StudentRepository&);

};


#endif //OPERATORY_STUDENTREPOSITORY_H
