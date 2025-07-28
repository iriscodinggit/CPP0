#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
    private:
        std::string ideas[100];
    public:
        Brain();
        Brain(const Brain& otherBrain);
        Brain& operator=(const Brain& otherBrain);
        ~Brain();
        std::string GetIdea(int index);
        void SetIdea(int index, std::string NewIdea);
};

#endif