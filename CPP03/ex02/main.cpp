#include "FragTrap.hpp"
#include "ClapTrap.hpp"

int main()
{
    FragTrap I;
	FragTrap J("FRAG_J");
	FragTrap K;
	FragTrap L(J);
	I.attack("a laser beam as if he were a cat");
	J.attack("his sister");
	I.takeDamage(15);
	J.takeDamage(15);
	I.beRepaired(5);
	J.beRepaired(5);
	I.highFivesGuys();
	J.highFivesGuys();
	K = J;
    return(0);
}