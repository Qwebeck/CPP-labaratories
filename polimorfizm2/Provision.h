//
// Created by falcon on 5/7/19.
//

#ifndef POLIMORFIZM2_PROVISION_H
#define POLIMORFIZM2_PROVISION_H
#define ALCHOHOL_IN_DRINK 100
#include <vector>
#include <algorithm>
#include <iostream>


enum class Provision{Beer=5,Wine=4,Cheaps=3,Sandwiches=1,Milk=2};
enum class Sex{Men,Women};

struct TooDrunkError:public std::invalid_argument{
    TooDrunkError():std::invalid_argument("You are too drunk"){};
};
struct NoPlaceInBackpack:public std::invalid_argument{
    NoPlaceInBackpack():std::invalid_argument("No place in backpack"){};
};
struct NoPlaceInBackpackForSuchThigs:public std::invalid_argument{
    NoPlaceInBackpackForSuchThigs():std::invalid_argument("Too big for backpack"){};
};



class Student {
private:
    int _mass;

    int _bp_vol;
    int _allowed_level;
    int _alc_level_in_blood;
    int _current_volume;
    std::vector<Provision> _backpack;
public:
    Student(int mass = 40 ,  int bp_vol = 10 , int drinking_period = 0  , int allowed_period = 10 , Sex sex = Sex::Men)
    {

        _mass = mass;
        _current_volume = 0;
        _bp_vol = bp_vol;
        _alc_level_in_blood= drinking_period;
        calculate_allowed_level(mass,allowed_period , sex);
    }
    int count_alc(std::vector<Provision >::const_iterator);
    void calculate_allowed_level(int mass , int allowed_period, Sex sex);
    bool is_enough();
    void add_item(Provision);
    void show_inventory() const;
    void pick_up(Provision);




};


#endif //POLIMORFIZM2_PROVISION_H
