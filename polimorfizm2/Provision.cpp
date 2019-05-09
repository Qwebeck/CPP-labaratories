//
// Created by falcon on 5/7/19.
//

#include "Provision.h"

/*bool operator<(Provision left,Provision right)
{
    return static_cast<int>(left)< static_cast<int>(right);
}
bool operator>(Provision left,Provision right)
{
    return static_cast<int>(left)> static_cast<int>(right);
}*/

bool Student::is_enough() {
    std::vector<Provision >::iterator it = std::find(_backpack.begin(), _backpack.end(), Provision::Beer);
    int alchohol_num;
    if(it!=_backpack.end())
    {
        alchohol_num = count_alc(it);

    } else{
        it = std::find(_backpack.begin(), _backpack.end(), Provision::Wine);
        alchohol_num = count_alc(it);
    }
    return _alc_level_in_blood > _allowed_level;

}

int Student::count_alc(std::vector<Provision >::const_iterator begin){
    int i = 0;
    while (begin!=_backpack.end()){
    if(*begin==Provision::Beer)++i;
    else i += 2;
    ++begin;
    }
    return i;

}

void Student::calculate_allowed_level(int mass ,  int allowed_period,Sex sex) {
    if (sex == Sex::Men){
     _allowed_level = mass * 2 * allowed_period / ALCHOHOL_IN_DRINK;
    } else{
        _allowed_level = mass * allowed_period/ALCHOHOL_IN_DRINK;
        }
}
void Student::add_item(Provision item)
{
    try {
    if((item==Provision::Beer or item==Provision::Wine) and is_enough())throw TooDrunkError();
    if(_current_volume + static_cast<int>(item) < _bp_vol){
        if(item ==Provision::Beer)
        {
            _alc_level_in_blood += 1;
            std::cout<<"Alchohol level increased.New level :"<<_alc_level_in_blood<<"\nYou can drink "<<_allowed_level - _alc_level_in_blood << " more beers  or " << ((_allowed_level - _alc_level_in_blood ))/2 << " bottles of wine "<< std::endl;
        }
        else if(item==Provision::Wine)
        {
            _alc_level_in_blood += 2;
            std::cout<<"Alchohol level increased.New level :"<<_alc_level_in_blood<<"\nYou can drink "<<_allowed_level - _alc_level_in_blood << " more beers  or " << (_allowed_level - _alc_level_in_blood )/2 << " bottles of wine "<< std::endl;
        }


            _backpack.emplace_back(item);
            std::sort(_backpack.begin(),_backpack.end());
            _current_volume = _current_volume + static_cast<int>(item);
        } else
            {
        throw NoPlaceInBackpack();
            };

    }catch (std::invalid_argument &e){std::cerr << e.what() << std::endl;}
}
void Student::show_inventory() const
{
    for(auto& item:_backpack)
    {
        switch (item){
            case Provision::Beer:
                std::cout<<"Beer"<<std::endl;
                break;
            case Provision::Wine:
                std::cout<<"Wine"<<std::endl;
                break;
            case Provision::Cheaps:
                std::cout<<"Cheaps"<<std::endl;
                break;
            case Provision::Sandwiches:
                std::cout<<"Sanwiches"<<std::endl;
                break;
            case Provision::Milk:
                std::cout<<"Milk"<<std::endl;
                break;
            default:
                break;
        }
    }
}

void Student::pick_up(Provision required) {
    for(int i = 0;i<_backpack.size();++i)
    {
        if(_backpack[i] == required)
        {
            switch (required){
                case Provision::Beer:
                    std::cout<<"Get Beer"<<std::endl;
                    break;
                case Provision::Wine:
                    std::cout<<"Get Wine"<<std::endl;
                    break;
                case Provision::Cheaps:
                    std::cout<<"Get Cheaps"<<std::endl;
                    break;
                case Provision::Sandwiches:
                    std::cout<<"Get Sanwiches"<<std::endl;
                    break;
                case Provision::Milk:
                    std::cout<<"Get Milk"<<std::endl;
                    break;
                default:
                    break;
            }
            _backpack.erase(_backpack.begin() + i);
            return;
        }
    }
    std::cerr <<"No such item in backpack" << std::endl;
}
