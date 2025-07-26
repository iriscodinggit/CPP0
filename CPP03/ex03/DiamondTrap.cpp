#include "DiamondTrap.hpp"

//takeDamage y beRepaired los he quitado del .hpp porque no cambian del .cpp de ClapTrap y los heredan

DiamondTrap::DiamondTrap() : ClapTrap("RandomDiamond_clap_name") //si no inicializa con ningun nombre, le pasamos a clap el default de RandomDiamond + _clap_name
{
    _name = "RandomDiamond";
    std::cout << "Default constructor for DiamondTrap " << _name << " has been called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap(), _name(name) //le pasa un nuevo nombre a claptrap, hereda de scav y frag y guarda el nombre de diamond al valor de name. Por ejemplo, si el parametro es Bob, el diamond se llama Bob y el clap Bob_clap_name
{
    std::cout << "Constructor for DiamondTrap " << _name << " has been called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "Destructor has been called for DiamondTrap" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& originalObject)
    : ClapTrap (originalObject), FragTrap(originalObject), ScavTrap(originalObject), _name(originalObject._name) //i dont need to add all the variables in the initialisation list because claptrap does the job for me :)
{
    std::cout << "Copy constructor for DiamondTrap named " << _name << " has been called" << std::endl;
}

DiamondTrap&   DiamondTrap::operator=(const DiamondTrap& originalObject)
{
    //aqui no puedo hacer como en las anteriores que lo añadia con : justo despues de la declaración, eso solo se puede hacer en des/constructores. En funciones normales, hay que llamarlo dentro de los brackets
    if (this != &originalObject) //PROBAR A QUITAR ESTE BLOQUE IF this i a pointer to the current object
    {
        _name = originalObject._name;
        ClapTrap::operator=(originalObject); 
    }
    std::cout << "Assignment operator overload has been called for DiamondTrap." << std::endl;
    return(*this);
}

void        DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "💎 DiamondTrap's ClapTrap is called: " << ClapTrap::_name << std::endl;
    std::cout << "💎 DiamondTrap's name: " << _name << std::endl;
}