#include "DiamondTrap.hpp"

int main()
{
		std::cout << "TESTING DIAMOND TRAP" << std::endl;
    DiamondTrap I;
	std::cout << std::endl;
	DiamondTrap J("Diamond2000");
	std::cout << std::endl;
	DiamondTrap K(J);
	std::cout << std::endl;
	I.attack("a peaceful sleeping cow");
	J.attack("a really angry and awake cow");
	I.takeDamage(15);
	J.takeDamage(15);
	I.beRepaired(5);
	J.beRepaired(5);
	I.highFivesGuys();
	J.highFivesGuys();
	I.guardGate();
	I.whoAmI();
	J.whoAmI();
	K = I;
	std::cout << std::endl;
    return(0);
	/*
	std::cout << "TESTING FRAG TRAP" << std::endl;
	FragTrap E;
	std::cout << std::endl;
	FragTrap F("Frag2000");
	std::cout << std::endl;
	FragTrap G(F);
	std::cout << std::endl;
	E.attack("a peaceful sleeping cow");
	F.attack("a really angry and awake cow");
	std::cout << std::endl;

	std::cout << "TESTING SCAV TRAP" << std::endl;
	ScavTrap A;
	std::cout << std::endl;
	ScavTrap B("Scav2000");
	std::cout << std::endl;
	ScavTrap C(B);
	std::cout << std::endl;
	A.attack("a peaceful sleeping cow");
	B.attack("a really angry and awake cow");
	std::cout << std::endl;
	*/
}