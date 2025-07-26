#include "ClapTrap.hpp"

int main()
{
    ClapTrap RandomBot;
    ClapTrap B("WALL-E");
    ClapTrap C;
    ClapTrap D(B);
    std::cout << std::endl;
    RandomBot.attack("your boss");
    B.attack("the spider that is scaring you");
    RandomBot.takeDamage(5);
    B.takeDamage(5);
    RandomBot.beRepaired(3);
    B.beRepaired(3);
    C = B;
    C.attack("annoying insect on your burger");
    std::cout << std::endl;
    return(0);
}