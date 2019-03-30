//
// Created by falcon on 3/29/19.
//

#ifndef NAMES_SIMPLEURL_H
#define NAMES_SIMPLEURL_H
#include <string>
#include <cstdint>
#include <regex>
#include <experimental/optional>
#include <vector>
#include <memory>

namespace simpleurl {
    using ::std::string;
    using ::std::regex;
    using ::std::smatch;
    using ::std::vector;



    class SimpleUrl {
    private:
        enum CapturingGroups {SCHEME=0,HOST,LOGIN ,PATH ,QUERY , FRAGMENT};
        string fullUrl;
//        string * parsed = new string[6] ;
        std::unique_ptr<string[]> parsed = std::make_unique <string[]> (6);
        uint16_t port;


    public:
        ///postawic pytanie
        SimpleUrl(const string & );
        string Login() const;
        string Host() const;
        string Path() const;
        uint16_t Port() const;
        string Scheme() const;
        string Query() const;
        string Fragment() const;
    };
}

#endif //NAMES_SIMPLEURL_H
