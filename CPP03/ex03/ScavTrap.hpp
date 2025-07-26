#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap //added virtual to make sure there's just one claptrap initialised
{
    private:
            void    initStats();
    public:
            ScavTrap();
            ScavTrap(std::string name);
            ScavTrap(const ScavTrap& originalObject);
            ScavTrap& operator=(const ScavTrap& originalObject);
            ~ScavTrap();
            void    attack(const std::string& target);
            void    guardGate();

};

#endif