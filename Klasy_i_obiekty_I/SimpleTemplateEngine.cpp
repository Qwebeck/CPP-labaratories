//
// Created by falcon on 3/29/19.
//

#include "SimpleTemplateEngine.h"


nets::View::View(std::string text) {
    base = text;
}



std::string nets::View::Render(const std::unordered_map<std::string, std::string> &model) const {
    string change_what = model.begin() -> first;
    std::cout << change_what << std::endl ;
    stringstream p;
    for (char i:change_what) p << i;

/*pytanie :
 * W jaki sposób mogę przypisać wartość zmiennej wyrażeniu .Probowałem zapiswać zmienną change_what w postaci char array i potem zapisywać do regex , ale się nie udało
 * Inna metoda z której chiałem skorzystać - to poniższy zapis , w którym change_what - zmienna typu string otrzymana w wyniku wykonania następującego polecenia :
 *
 *          string change_what = model.begin() -> first;
 *          regex replace1(R"("+change_what +")")
 *
 * Jeszcze jeden sposób - to zapis do zmienne j typu stringstream i deklaracją regexu z tą zmienną
 *
 *          std::cout << change_what << std::endl ;
            stringstream p;
            for (char i:change_what) p << i;
            regex replace3(R"("+p+")");
    Ale żaden z tych sposobów nie dał oczekiwanych skutków
 * */


    regex replace2(R"("+change_what +")");
    regex replace3(R"("+p+")");
    regex replace(R"(name)");
    string change_on = model.begin() -> second;
    string rendered2 = regex_replace(base , replace2 , change_on);
    string rendered3 = regex_replace(base , replace3 , change_on);
    string rendered = regex_replace(base , replace , change_on);
    std::cout << rendered << std::endl;
    std::cout << rendered2 << std::endl;
    std::cout << rendered3 << std::endl;
    return rendered;
}

