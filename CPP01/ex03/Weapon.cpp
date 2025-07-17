#include "Weapon.hpp"

const std::string& Weapon::getType()
{
    return(_type);
}

void        Weapon::setType(std::string type)
{
    _type = type; //why use this instead of an initialisation list? because the weapon value can change later on, so we don't initialise, we change it throughout the main
}