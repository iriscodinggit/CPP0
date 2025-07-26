#include "ScavTrap.hpp"

//takeDamage y beRepaired los he quitado del .hpp porque no cambian del .cpp de ClapTrap y los heredan

void ScavTrap::initStats()
{
    _hitPoints = 100;
    _energyPoints = 50;
    if(_attackDamage != 30)
        _attackDamage = 20;
}

ScavTrap::ScavTrap() : ClapTrap()
{
    initStats();
    std::cout << "Default constructor for ScavTrap " << _name << " has been called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    initStats();
    std::cout << "Constructor for ScavTrap " << _name << " has been called" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "Destructor has been called for ScavTrap" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& originalObject)
    : ClapTrap (originalObject) //i dont need to add all the variables in the initialisation list because claptrap does the job for me :)
{
    std::cout << "Copy constructor for ScavTrap named " << _name << " has been called" << std::endl;
}

ScavTrap&   ScavTrap::operator=(const ScavTrap& originalObject)
{
    ClapTrap::operator=(originalObject); //aqui no puedo hacer como en las anteriores que lo añadia con : justo despues de la declaración, eso solo se puede hacer en des/constructores. En funciones normales, hay que llamarlo dentro de los brackets
    std::cout << "Assignment operator overload has been called for ScavTrap." << std::endl;
    return(*this);
}

void        ScavTrap::attack(const std::string& target)
{
    if(_hitPoints <= 0)
    {
        std::cout << "😥 Cannot attack!" << _name << "has no Health/Hit Points left!" << std::endl;
        return ;
    }
    else if (_energyPoints <= 0)
    {
        std::cout << "😥 Cannot attack!" << _name << "has no Energy Points left!" << std::endl;
        return ;
    }
    _energyPoints--;
    std::cout << "🥊 " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "🚪 ScavTrap " << _name << " is now in gate keeper mode." << std::endl;
}