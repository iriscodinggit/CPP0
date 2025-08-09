#include "Bureaucrat.hpp"

int main(void)
{
    try
    {
        Bureaucrat MichaelScott("MichaelScott", 10);
        MichaelScott.increaseGrade();
    }
    catch(const Bureaucrat::GradeTooHighException &error)
    {
        std::cerr << error.what() << std::endl;
    }
    catch(const Bureaucrat::GradeTooLowException &error)
    {
        std::cerr << error.what() << std::endl;
    }
    std::cout << std::endl;
    try
    {
        Bureaucrat JimHalpert("JimHalpert", 150);
        JimHalpert.decreaseGrade();
    }
    catch(const Bureaucrat::GradeTooHighException &error)
    {
        std::cerr << error.what() << std::endl;
    }
    catch(const Bureaucrat::GradeTooLowException &error)
    {
        std::cerr << error.what() << std::endl;
    }
    try
    {
        Bureaucrat PamBeesly("PamBeesly", 1);
        PamBeesly.increaseGrade();
    }
    catch(const Bureaucrat::GradeTooHighException &error)
    {
        std::cerr << error.what() << std::endl;
    }
    catch(const Bureaucrat::GradeTooLowException &error)
    {
        std::cerr << error.what() << std::endl;
    }
    return(0);
}