#include "FragTrap.hpp"

//takeDamage y beRepaired los he quitado del .hpp porque no cambian del .cpp de ClapTrap y los heredan

void FragTrap::initStats()
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
}

FragTrap::FragTrap() : ClapTrap()
{
    //gonna cause trouble when creating frags if we leave it uncommented..._name = "RandomFrag"; Lo comentamos para que no cambie el nombre de Diamond al RandomFrag
    initStats();
    std::cout << "Default constructor for FragTrap " << _name << " has been called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    initStats();
    std::cout << "Constructor for FragTrap " << _name << " has been called" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "Destructor has been called for FragTrap" << std::endl;
}

FragTrap::FragTrap(const FragTrap& originalObject)
    : ClapTrap (originalObject) //i dont need to add all the variables in the initialisation list because claptrap does the job for me :)
{
    std::cout << "Copy constructor for FragTrap named " << _name << " has been called" << std::endl;
}

FragTrap&   FragTrap::operator=(const FragTrap& originalObject)
{
    ClapTrap::operator=(originalObject); //aqui no puedo hacer como en las anteriores que lo añadia con : justo despues de la declaración, eso solo se puede hacer en des/constructores. En funciones normales, hay que llamarlo dentro de los brackets
    std::cout << "Assignment operator overload has been called for FragTrap." << std::endl;
    return(*this);
}

void        FragTrap::attack(const std::string& target)
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
    std::cout << "🥊 FragTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << "🙏 " << _name << ": Hey guys! Why attack each other when we can...high-five! 🙏" << std::endl;
}