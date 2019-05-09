//
// Created by falcon on 4/14/19.
//

#include "StudentRepository.h"

std::istream &StudentRepository::operator>>(std::istream &stream) {
    string tmp , buf;
    while (tmp[tmp.length()-1] != ']') {
        stream >> buf;
        tmp += buf;
    }
    regex student(R"(\{(.[^}]*)\})");
    smatch matches;
    while (regex_search(tmp , matches ,student))
    {
        Students.emplace_back(matches[1]);
        tmp = matches.suffix().str();
    }
    return stream;
}

Student* StudentRepository::operator[](const string & id) {
    for (auto& student:Students)if (student.id == id)return &student;
    return nullptr;
}

bool StudentRepository::operator==(StudentRepository & other) {
    if (this -> Students.size() != other.Students.size()) return false;
    int size = static_cast<int>(this -> Students.size());
    int i = 0;int j = 0;int m = 0;int p = 0;
    while ( m == j and m < size)
    {
        i = 0;
        while (i < size)
        {
            if (this->Students[i].id == other.Students[j].id)
            {
                ++m;
                break;
            }
            ++i;
        }
        ++j;

    }

    return m==size;
}
