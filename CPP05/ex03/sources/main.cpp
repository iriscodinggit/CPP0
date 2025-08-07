#include "../headers/Bureaucrat.hpp"
#include "../headers/AForm.hpp"
#include "../headers/ShrubberyCreationForm.hpp"
#include "../headers/RobotomyRequestForm.hpp"
#include "../headers/PresidentialPardonForm.hpp"

int main(void)
{
    try
    {
        //enough grade, modify 1 for 150 for exceptions or for out of range stuff
        Bureaucrat MichaelScott("MichaelScott", 1);
        //Bureaucrat MichaelScott("MichaelScott", 150);
        PresidentialPardonForm  PardonForm("Thanos");
        RobotomyRequestForm     RoboForm("WALL-E");
        ShrubberyCreationForm   TreeForm("Minessota National Park");
        MichaelScott.signForm(TreeForm);
        MichaelScott.executeForm(TreeForm);
        std::cout << std::endl;
        MichaelScott.signForm(RoboForm);
        MichaelScott.executeForm(RoboForm);
        std::cout << std::endl;
        MichaelScott.signForm(PardonForm);
        MichaelScott.executeForm(PardonForm);
        std::cout << std::endl;
    }
    catch(const std::exception &error) // captura tanto las de Bureaucrat como de Form
    {
        std::cerr << error.what();
    }

    return(0);
}