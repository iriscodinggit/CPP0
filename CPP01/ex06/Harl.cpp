#include "Harl.hpp"

void Harl::debug()
{
    std::cout << "[DEBUG]" << std::endl << "👨‍💻 Harl: \"AAAAAGH! Another BUG! When will this come to an end?\"" << std::endl;
}

void Harl::info()
{
    std::cout << "[INFO]" << std::endl << "👨‍💻 Harl: \"Mhm? You want information? What about this: RTFM.\"" << std::endl;
}

void Harl::warning()
{
    std::cout << "[WARNING]" << std::endl << "👨‍💻 Harl: \"How many times do I have to warn you NOT to forget to push your code?\"" << std::endl;
}

void Harl::error()
{
    std::cout << "[DEBUG]" << std::endl << "👨‍💻 Harl: \"This error is unacceptable! I want to speak to the manager NOW.\"" << std::endl;
}

void    Harl::complain(std::string level)
{
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*function[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error}; //this is a pointer to a function array of 4 functions

    for (int i = 0; i < 4; i++)
    {
        if(levels[i] == level)
        {
                return((this->*function[i])()); //the keyword "this" means, get the function from the object where you are calling from (in this case Harl)
        }
    }
    std::cerr << "Oops! Level not found!" << std::endl;
}