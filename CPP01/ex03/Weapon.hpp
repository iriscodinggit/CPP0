#ifndef WEAPON_HPP
# define WEAPON_HPP
#include <string>
#include <iostream>

class Weapon
{
    private:
                std::string _type;
    public:
                Weapon(){};
                Weapon(std::string type) : _type(type){};
                const std::string& getType(); //returns a ref to a string (ref is not a keyword, so we use &)
                void        setType(std::string type);   
};

#endif