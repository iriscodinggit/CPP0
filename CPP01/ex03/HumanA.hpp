#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA
{
    public:
            void    attack();
            HumanA(std::string name, Weapon &weapon_name) : _name(name), _weapon(weapon_name){};
            //we don't need setWeapon here, a ref CANNOT be changed later on anyways, just a pointer can be changed
    private:
            std::string _name;
            Weapon      &_weapon; //always has a weapon, so we use a ref, since we know that it will never be NULL
};            

#endif