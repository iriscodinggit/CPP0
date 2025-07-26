#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <sstream> //to concatenate numbers and strings safely

class Zombie
{
    private:
            std::string _name;
    public:
            Zombie(){}; //first constructor (empty)
            Zombie(std::string name) : _name(name){}; //Second constructor
            ~Zombie(){std::cout << "🧠 The zombie " << _name << " has been annihilated. 🔫\n";};
            void announce (void);
            void setName(std::string name); //why? cant i just use the initialisation list?

};

//Functions

Zombie *zombieHorde(int N, std::string name);

#endif