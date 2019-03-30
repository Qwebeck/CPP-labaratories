//
// Created by falcon on 3/29/19.
//

#include "SimpleUrl.h"

simpleurl::SimpleUrl::SimpleUrl(const std::string & url){
        fullUrl = url;
        regex scheme(R"(^(\w+:))");
        regex login(R"(\w+@\w+)");
        regex port_regex(R"(:\d+$)");
        regex host(R"(\w+:\/\/(\w+.[^(\/|:)]*)(\/|$))");
        regex path(R"(\w+:\/\/\/\w+.*$)");
        regex query(R"(\?(\w+.*))");
        regex fragment(R"(\#(\w+.*))");
        smatch matches;
        if(regex_search(fullUrl , matches , login))parsed[LOGIN]= (string(matches[1]));
        if (regex_search(fullUrl, matches, port_regex))port = (uint16_t) stoi(string(matches[1]));
        if( regex_search(fullUrl,matches,scheme))parsed[SCHEME] = string(matches[1]);
        if(regex_search(fullUrl,matches,host))parsed[HOST] = string(matches[1]);
        if(regex_search(fullUrl,matches,path))parsed[PATH] = string(matches[1]);
        if(regex_search(fullUrl,matches,query))parsed[QUERY] = string(matches[1]);
        if(regex_search(fullUrl,matches,fragment))parsed[FRAGMENT] = string(matches[1]);

}
std::string simpleurl::SimpleUrl::Login() const {
      /*  regex login(R"(\w+@\w+)");
        smatch matches;
        //dlaczego prypisanie dziala tutaj , ale nie dziala w funkcji Port
        if(regex_search(fullUrl , matches , login))parsed[LOGIN] = string(matches[1]);*/
        return  parsed[LOGIN];
}
uint16_t simpleurl::SimpleUrl::Port() const{
   /* std::regex port_regex(R"(:\d+$)");
    smatch matches;
    string
    res = string(matches[1]);
    if (regex_search(fullUrl, matches, port_regex))port = (uint16_t) stoi(string(matches[1]));
    */
    return port;
}

std::string simpleurl::SimpleUrl::Scheme() const {
        return parsed[SCHEME];
}

std::string simpleurl::SimpleUrl::Host()const {
        return parsed[HOST];
}

std::string simpleurl::SimpleUrl::Path() const {
        return parsed[PATH];
}

std::string simpleurl::SimpleUrl::Query() const {
        return parsed[QUERY];
}

std::string simpleurl::SimpleUrl::Fragment() const {
        return parsed[FRAGMENT];
}





