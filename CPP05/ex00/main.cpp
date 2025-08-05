#include "Bureaucrat.hpp"

int main(void)
{
    try
    {
        Bureaucrat Iris("Iris", 10);
        Iris.increaseGrade();
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
        Bureaucrat Helios("Helios", 150);
        Helios.decreaseGrade();
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
        Bureaucrat Elon("Elon", 1);
        Elon.increaseGrade();
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