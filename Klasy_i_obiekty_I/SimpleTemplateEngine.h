//
// Created by falcon on 3/29/19.
//

#ifndef NAMES_SIMPLETEMPLATEENGINE_H
#define NAMES_SIMPLETEMPLATEENGINE_H
#include <string>
#include <unordered_map>
#include <regex>
#include <ostream>
#include <iostream>


namespace nets {
    using ::std::string;
    using ::std::regex;
    using ::std::smatch;
    using ::std::regex_search;
    using ::std::regex_replace;
    using ::std::ostream;
    using ::std::unordered_map;
    using ::std::stringstream;
    class View {
    private:


        string base;


    public:
        explicit View(string);
        string Render(const std::unordered_map<std::string, std::string> &model) const;
    };
}

#endif //NAMES_SIMPLETEMPLATEENGINE_H
