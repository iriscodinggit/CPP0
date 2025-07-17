#include "HumanA.hpp"

void    HumanA::attack()
{
    std::cout << _name << " attacks with their " << _weapon.getType() << std::endl; //why .getType instead of just Type? because type is private, so we need a public function to recover it here in humana.cpp
}