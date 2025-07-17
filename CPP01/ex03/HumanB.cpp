#include "HumanB.hpp"

void    HumanB::attack()
{
    if (_weapon == NULL)
    
        std::cout << _name << " attacks unarmed 👊💥" << std::endl;
    else
        std::cout << _name << " attacks with their "  << _weapon->getType() << std::endl;
}

//why is setWeapon defined here but not getType? ok, i confused setWeapon (from human) to setType (from weapon)...the latter and GetType are always defined together (check weapon.cpp)
void    HumanB::setWeapon(Weapon &weapon_name)  // we use & in weapon_name because we need to pass the value by ref to not assign _weapon to an adress that will later point to garbage because if you pass by value the copy will stop existing once the function ends and therefore you will be pointing to an adress that doesnt store anything
{
    _weapon = &weapon_name; //why this  instead of the initialiser? because the weapon can also change throughout the main, so we use the initalising list for the first value and setweapon for the rest
}