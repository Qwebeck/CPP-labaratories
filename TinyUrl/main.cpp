#include <iostream>
#include <vector>
#include <regex>
#include <array>
#include <set>
#include <stdlib.h>
#include <time.h>
#include <vector>

int hashed = 0;
std::vector<std::string> urls;

struct TinyUrlCodec{
    std::array<char, 6> tiny;
    int hash_number;
    bool encrypted;
};


std::unique_ptr<TinyUrlCodec> Init();
void NextHash(std::array<char, 6> *state);
std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec);
std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec);


int main(void)
{

    srand (time(NULL));
    std::string url{"https://stackoverflow.com/questions/11375949/cout-is-not-a-member-of-std"};
    std::unique_ptr<TinyUrlCodec> Hash = Init();
    urls.push_back(url);
    Encode(url , &Hash);
    std::cout << "Decoded url:" << Decode(Hash) << std::endl;
    return 0;
}


std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec){
    int url = (codec -> tiny[0]) - '0';
    std::string full = urls[url - 1];
    std::cout << full << std::endl;
    return full;
};


std::unique_ptr<TinyUrlCodec> Init(){
    std::unique_ptr<TinyUrlCodec> NewHash= std::make_unique<TinyUrlCodec>();
    NewHash -> encrypted = false;
    NewHash -> hash_number = hashed;
    hashed += 1;
    return NewHash;
}


std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec){
    std::regex pattern {R"((\w+://\w+).[^/]*(/.*))"};
    std::string alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::smatch matches;
    regex_search(url, matches, pattern);
    std::string main_url = matches[1];
    std::array<char ,6 > hash{};

    hash[0] = std::to_string(hashed)[0];
    std::cout << std::endl;
    for(int i = 1 ; i < hash.size() ; ++i)
    {

        hash[i] = char(alpha[rand() % 10 + alpha.length() - 10]);
    }
    main_url += '/';
    for(char i : hash)
    {
        main_url += i;
    }
    std::cout << main_url << std::endl;
    (*codec) -> tiny = hash;
    (*codec) -> encrypted = true;
    (*codec) -> hash_number = hashed;
    return main_url;



};