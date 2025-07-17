#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB
{
    public:
            void    attack();
            void    setWeapon(Weapon    &weapon_name);
            HumanB(std::string name) : _name(name), _weapon(NULL){}; //los dos primeros son lo que recive y los dos seegundos son como inicializa _name = name y _weapon = weapon_name
    private:
            std::string _name;
            Weapon      *_weapon; //NOT always has a weapon, so we use a pointer, since we know that it can be NULL sometimes
};

#endif