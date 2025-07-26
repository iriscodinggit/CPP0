#ifndef DIAMOND_TRAP_HPP
# define DIAMOND_TRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
    private:
            std::string _name; //para provocar shadow, le ponemos el mismo nombre que a claptrap
    public:
            DiamondTrap();
            DiamondTrap(const std::string& name);
            DiamondTrap(const DiamondTrap& originalObject);
            DiamondTrap& operator=(const DiamondTrap& originalObject);
            ~DiamondTrap();
            void    attack(const std::string& target);
            void    whoAmI();

};

#endif