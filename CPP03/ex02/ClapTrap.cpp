#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    _name = "RandomClap";
    _hitPoints = 10;
    _energyPoints = 10;
    _attackDamage = 0;
    std::cout << "Default constructor for Claptrap " << _name << " has been called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
    _name = name;
    _hitPoints = 10;
    _energyPoints = 10;
    _attackDamage = 0;
    std::cout << "Constructor for ClapTrap " << _name << " has been called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor has been called for ClapTrap" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& originalObject)
    :_name(originalObject._name),                   //i use initialisation list because if we define them inside of the brackets, if would first initialise with default and THEN assign the values (two steps), isntead of directly assigning (one step)
    _hitPoints(originalObject._hitPoints),
    _energyPoints(originalObject._energyPoints),
    _attackDamage(originalObject._attackDamage)
{
    std::cout << "Copy constructor for ClapTrap named " << _name << " has been called" << std::endl;
}

ClapTrap&   ClapTrap::operator=(const ClapTrap& originalObject)
{
    if (this != &originalObject) //this is a pointer to the current object
    {
        _name = originalObject._name;
        _hitPoints = originalObject._hitPoints;
        _energyPoints = originalObject._energyPoints;
        _attackDamage = originalObject._attackDamage;
    }
    std::cout << "Assignment operator overload has been called for ClapTrap" << std::endl;
    return(*this);
}

void        ClapTrap::attack(const std::string& target)
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
    std::cout << "🥊 ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void        ClapTrap::takeDamage(unsigned int amount)
{
    if(_hitPoints <= 0)
    {
        std::cout << "😥 Cannot take damage!" << _name << " is already KO!" << std::endl;
        return ;
    }
    _hitPoints = _hitPoints - amount;
    std::cout << "❤️‍🩹 " << _name << " takes " << amount << " damage. Health/hit points left: " << _hitPoints << std::endl;
}

void        ClapTrap::beRepaired(unsigned int amount)
{
    if(_hitPoints <= 0)
    {
        std::cout << "😥 Cannot be repaired!" << _name << "has no Health/Hit Points left!" << std::endl;
        return ;
    }
    else if (_energyPoints <= 0)
    {
        std::cout << "😥 Cannot be repaired!" << _name << "has no Energy Points left!" << std::endl;
        return ;
    }
    _hitPoints = _hitPoints + amount;
    _energyPoints--;
    std::cout << "💚 " << _name << " gained " << amount << " health points. Health/hit points left: " << _hitPoints << std::endl;
}