#include "../headers/Brain.hpp"

Brain::Brain()
{
    std::cout << "Default constructor for Brain called" << std::endl;
}

Brain::Brain(const Brain& otherBrain)
{
    std::cout << "Copy constructor for Brain called" << std::endl;
    for (int i = 0; i < 100; i++)
        this->ideas[i] = otherBrain.ideas[i];
}

Brain& Brain::operator=(const Brain& otherBrain)
{
    std::cout << "Assignment operator for Brain called" << std::endl;
    if (this != &otherBrain)
    {
        for(int i = 0; i < 100; i++)
            this->ideas[i] = otherBrain.ideas[i];
    }
    return(*this);
}

Brain::~Brain()
{
    std::cout << "Destructor for Brain called" << std::endl;
}

std::string Brain::GetIdea(int index)
{
    if (index >= 0 && index < 100)
        return(ideas[index]);
    return(NULL);
}

void Brain::SetIdea(int index, std::string NewIdea)
{
    if(index >= 0 && index < 100)
        ideas[index] = NewIdea;
    return ;
}