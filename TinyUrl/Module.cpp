//
// Created by falcon on 3/19/19.
//

#include <string>
#include <sstream>
#include "Module.h"
namespace mymodule {
    using ::std::string;
    using ::std::stringstream;

    string ToString(int value) {
        stringstream ss;
        ss<<value;
        return ss.str();
    }
    std::string Hashed(string& url)
    {
        std::regex pattern {R"((\w+)//(\w+)\w+)"};
        std::smatch matches;
        if( regex_match(url, matches, pattern))
        {
            std::cout<<matches[0]<<std::endl;
        }

        return " ";
    }

}

