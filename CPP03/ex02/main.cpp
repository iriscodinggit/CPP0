#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    FragTrap I;
	FragTrap J("Frag2000");
	FragTrap K;
	FragTrap L(J);
	std::cout << std::endl;
	I.attack("a laser beam as if he were a cat");
	J.attack("his sister");
	I.takeDamage(15);
	J.takeDamage(15);
	I.beRepaired(5);
	J.beRepaired(5);
	I.highFivesGuys();
	J.highFivesGuys();
	K = J;
	std::cout << std::endl;
    return(0);
}