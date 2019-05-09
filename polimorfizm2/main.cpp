#include <iostream>
#include "Provision.h"
Provision what(int);
int main() {
    Student Qualt(80,20,0,10);
    std::cout<<"Choose option:\n1-add 2-pick_up 3 -show_inv 0 - end" << std::endl;
    int option;
    int item;
    std::cin>>option;
    while (option)
    {
        switch (option)
        {
            case 1:
                std::cout<<"What? :\n 1- Beer 2-Wine 3-Cheaps 4-Sandwiches 5-Milk"<<std::endl;
                std::cin>>item;
                Qualt.add_item(what(item));
                break;
            case 2:
                std::cout<<"Pick up what? :\n 1- Beer 2-Wine 3-Cheaps 4-Sandwiches 5-Milk"<<std::endl;
                std::cin>>item;
                Qualt.pick_up(what(item));
                break;
            case 3:
                Qualt.show_inventory();
                break;
            default:
                std::cerr<<"No such option"<<std::endl;
        }
        std::cout<<std::endl<<"Choose option:\n1-add 2-pick_up 3 -show_inv 0 - end" <<  std::endl<< std::endl;
        std::cin>>option;
    }
    return 0;
}

Provision what(int item)
{
    try{
    switch (item){
        case 1:
            return Provision::Beer;
        case 2:
            return Provision::Wine;
        case 3:
            return Provision::Cheaps;
        case 4:
            return Provision::Sandwiches;
        case 5:
            return Provision::Milk;
        default:
            throw NoPlaceInBackpackForSuchThigs();
    }}catch (std::invalid_argument &e ){std::cerr<<e.what();}
}