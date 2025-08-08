#include "../headers/Bureaucrat.hpp"
#include "../headers/Intern.hpp"
#include "../headers/AForm.hpp"
#include "../headers/ShrubberyCreationForm.hpp"
#include "../headers/RobotomyRequestForm.hpp"
#include "../headers/PresidentialPardonForm.hpp"

int main(void)
{
    try
    {
        Bureaucrat  MichaelScott("MichaelScott", 1);
        Intern      Noob;
        std::cout << std::endl;
        AForm *newForm = Noob.makeForm("robotomy request", "R2-D2");
        std::cout << std::endl;
        newForm->beSigned(MichaelScott);
        newForm->execute(MichaelScott);
        delete newForm;
        std::cout << std::endl;
    }
    catch(const std::exception &error) // captura tanto las de Bureaucrat como de Form
    {
        std::cerr << error.what();
    }

    return(0);
}