#include "DiamondTrap.hpp"

//takeDamage y beRepaired los he quitado del .hpp porque no cambian del .cpp de ClapTrap y los heredan

DiamondTrap::DiamondTrap() : ClapTrap("RandomDiamond_clap_name") //si no inicializa con ningun nombre, le pasamos a clap el default de RandomDiamond + clap_name
{
    _name = "RandomDiamond";
    _hitPoints = FragTrap::_hitPoints;
    _energyPoints = ScavTrap::_energyPoints;
    _attackDamage = FragTrap::_attackDamage;
    std::cout << "Default constructor for DiamondTrap " << _name << " has been called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string& name) : ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap(), _name(name) //le pasa un nuevo nombre a claptrap, hereda de scav y frag y guarda el nombre de diamond al valor de name. Por ejemplo, si el parametro es Bob, el diamond se llama Bob y el clap Bob_clap_name
{
    _name = name;
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "Constructor for DiamondTrap " << _name << " has been called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "Destructor has been called for DiamondTrap" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& originalObject)
    : ClapTrap (originalObject) //i dont need to add all the variables in the initialisation list because claptrap does the job for me :)
{
    std::cout << "Copy constructor for DiamondTrap named " << _name << " has been called" << std::endl;
}

DiamondTrap&   DiamondTrap::operator=(const DiamondTrap& originalObject)
{
    ClapTrap::operator=(originalObject); //aqui no puedo hacer como en las anteriores que lo añadia con : justo despues de la declaración, eso solo se puede hacer en des/constructores. En funciones normales, hay que llamarlo dentro de los brackets
    if (this != &originalObject) //PROBAR A QUITAR ESTE BLOQUE IF this i a pointer to the current object
    {
        _name = originalObject._name;
        _hitPoints = originalObject._hitPoints;
        _energyPoints = originalObject._energyPoints;
        _attackDamage = originalObject._attackDamage;
    }
    std::cout << "Assignment operator overload has been called for DiamondTrap." << std::endl;
    return(*this);
}

void        DiamondTrap::attack(const std::string& target)
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
    std::cout << "🥊 DiamondTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void DiamondTrap::highFivesGuys()
{
    std::cout << "🚪 DiamondTrap " << _name << ": Hey guys! Why attack each other when we can...high-five! 🙏" << std::endl;
}