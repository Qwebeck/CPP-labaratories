//
// Created by falcon on 3/28/19.
//

#include "Name.h"

model::Name::Name(const std::string &first_names_surname) {
    regex model (R"([A-Z][a-z]+)");
    string sample = first_names_surname;
    std::smatch matches;
    sample = first_names_surname;
    vector<string> parts;
    while (std::regex_search(sample , matches , model)) {
        for (string name:matches) parts.push_back(name);
        sample = matches.suffix().str();
    }
    first_name_= parts[0];
    last_name_ = parts.back();
    if(parts.size() >= 3) {
        second_name_ = parts[1];
        if (parts.size() == 4) third_name_ = parts[2];
    }
}

model::string model::Name::FirstName() const {
    return first_name_;
}
model::optional<std::string> model::Name::SecondName() const {
    if (!second_name_.empty()) return second_name_;
    else return {};


}
model::optional<std::string> model::Name::ThirdName() const {
    if (!third_name_.empty()) return third_name_;
    else return {};
}
model::string model::Name::Surname() const {
    return last_name_;
}

std::string model::Name::ToFullInitials() const {
    string sn = SecondName().value_or("");
    string tn = ThirdName().value_or("");
    stringstream initials ;
    initials << first_name_[0] << ". " ;
    if(!sn.empty()) initials << second_name_[0] << ". ";
    if (!tn.empty()) initials << third_name_[0] << ". " ;
    initials << last_name_[0] <<". ";
    string fullInitials = initials.str();


    return fullInitials;
}

bool model::Name::IsBeforeBySurname(const model::Name &other) const {
    string other_sur = other.Surname() ;
    int i = 0;
    while (last_name_[i] == other_sur[i])++i;
    return last_name_[i] - other_sur[i] <= 0;
}
bool model::Name::IsBeforeByFirstName(const model::Name &other) const {
    string other_name = other.FirstName() ;
    int i = 0;
    while (first_name_[i] == other_name[i])++i;
    return first_name_[i] - other_name[i] <= 0;
}

std::string model::Name::ToFirstNamesInitials() const {
    string sn = SecondName().value_or("");
    string tn = ThirdName().value_or("");
    stringstream initials ;
    initials << first_name_[0] << ". " ;
    if(!sn.empty()) initials << second_name_[0] << ". ";
    if (!tn.empty()) initials << third_name_[0] << ". " ;
    initials << last_name_;
    string FirstNameInitials = initials.str();
    return FirstNameInitials;
}

std::string model::Name::ToNamesSurname() const {
    string sn = SecondName().value_or("");
    string tn = ThirdName().value_or("");
    stringstream initials ;
    initials << first_name_<< " ";
    if(!sn.empty()) initials << second_name_ << " ";
    if (!tn.empty()) initials << third_name_ << " ";
    initials << last_name_<< " ";
    string ToNameSurname = initials.str();
    return ToNameSurname ;
}


std::string model::Name::ToSurnameNames() const {
    string sn = SecondName().value_or("");
    string tn = ThirdName().value_or("");
    stringstream initials ;
    initials << last_name_ << " ";
    initials << first_name_ << " ";
    if(!sn.empty()) initials << second_name_  << " ";
    if (!tn.empty()) initials << third_name_  << " ";
    string ToSurnameNames = initials.str();
    return ToSurnameNames ;
}

