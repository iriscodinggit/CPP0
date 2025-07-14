#include "Zombie.hpp"

void    Zombie::setName(std::string name) //why not just the initialisation lsit?
{
    _name = name;
}

void    Zombie::announce(void)
{
     std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl; //how does it know which p_name to print?
}