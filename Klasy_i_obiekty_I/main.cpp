#include <iostream>
#include "Name.h"
#include "SimpleTemplateEngine.h"
#include "SimpleUrl.h"


int main() {
/*Name surname */
    model::Name JD("Johathan_AbrahamMakkern_Duglas");
    model::Name Turk("Christopher_Turk");
    std::cout << JD.ToFullInitials() << std::endl;
    std::cout << JD.ToFirstNamesInitials() << std::endl;
    std::cout << JD.ToNamesSurname() << std::endl;
    std::cout << JD.ToSurnameNames() << std::endl;
    std::cout << Turk.ToFullInitials() << std::endl;
    std::cout << JD.IsBeforeBySurname(Turk);

/*Simple url */
    simpleurl::SimpleUrl stackofverflow ("http://stackoverflow.com/documentation/c%2b%2b/1206/the-rule-of-three-five-and-zero#t=201703151744410516658");
    std::cout << "Login: " <<stackofverflow.Login() << std::endl;
    std::cout << "Port: "<<stackofverflow.Port() << std::endl;
    std::cout << "Scheme: " <<stackofverflow.Scheme() << std::endl;
    std::cout << "Query: "<<stackofverflow.Query() << std::endl;
    std::cout << "Path: "<<stackofverflow.Path() << std::endl;
    std::cout << "Fragment: "<<stackofverflow.Fragment() << std::endl;
    std::cout << "Host: "<<stackofverflow.Host() << std::endl;
    /*SimpleTemplateEngine  */
    nets::View hello("Hello {{name}}");
    nets::unordered_map <std::string , std::string> map = {{"name","Xavier"}} ;
    std::cout <<"Main function: " +  hello.Render(map);
    return 0;
}