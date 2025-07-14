#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
    private:
            std::string _name;
    public:
            Zombie(){}; //first constructor (empty)
            Zombie(std::string name) : _name(name){}; //Second constructor
            ~Zombie(){std::cout << "🧠 The zombie " << _name << " has been annihilated. 🔫\n";};
            void announce (void);
};

//Functions

Zombie *newZombie(std::string name); //heap
void    randomChump(std::string name); //stack

#endif