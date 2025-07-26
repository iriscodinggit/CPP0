#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include <iostream>

class ClapTrap
{
    protected: //we change private for protected to make sure that the child can inherit them
            std::string _name;
            int         _hitPoints;
            int         _energyPoints;
            int         _attackDamage;
    public:
            ClapTrap();
            ClapTrap(std::string name);
            ClapTrap(const ClapTrap &originalObject);
            ClapTrap& operator=(const ClapTrap &originalObject);
            ~ClapTrap();
            void        attack(const std::string& target);
            void        takeDamage(unsigned int amount);
            void        beRepaired(unsigned int amount);
};

#endif