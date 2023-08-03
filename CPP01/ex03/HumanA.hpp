#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include <cstring>

#include "Weapon.hpp"

class HumanA {
private:
    std::string	name;
    Weapon*		weapon;

public:
    HumanA(const std::string& name, Weapon& weaponn);
    void attack();
};

#endif