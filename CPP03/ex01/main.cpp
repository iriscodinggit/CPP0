#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main()
{
    ClapTrap RandomClap;
    ScavTrap RandomScav;
    ScavTrap B("WALL-E");
    ScavTrap C;
    ScavTrap D(B);
    std::cout << std::endl;
    RandomClap.attack("your shadow");
    RandomScav.attack("your expensive porcelain set");
    B.attack("a scary-looking pile of clothes");
    RandomScav.takeDamage(5);
    B.takeDamage(5);
    RandomScav.beRepaired(3);
    B.beRepaired(3);
    C = B;
    C.attack("his own reflection in the mirror");
    C.guardGate();
    std::cout << std::endl;
    return(0);
}