//
// Created by falcon on 3/28/19.
//

#ifndef NAMES_NAME_H
#define NAMES_NAME_H

#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <experimental/optional>
#include <sstream>

namespace model {
    using ::std::regex;
    using ::std::vector;
    using ::std::string;
    using ::std::stringstream;
    using ::std::experimental::optional;


    class Name {
    public:
        explicit Name(const string &first_names_surname);

        string FirstName() const;
        optional<string> SecondName() const;
        optional<string> ThirdName() const;
        string Surname() const;
        string ToFullInitials() const;
        string ToFirstNamesInitials() const;
        string ToSurnameNames() const;
        string ToNamesSurname() const;
        bool IsBeforeBySurname(const Name &other) const;
        bool IsBeforeByFirstName(const Name &other) const;

    private:
        string first_name_;
        string second_name_;

        string third_name_;
        string last_name_;
    };
}

#endif //NAMES_NAME_H
