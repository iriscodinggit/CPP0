#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    try
    {
        Form Document1("Document1", false, 15, 15);
        Bureaucrat Amy("Amy", 100);
        Amy.signForm(Document1);
    }
    catch(const Bureaucrat::GradeTooHighException &error)
    {
        std::cerr << error.what();
    }
    catch(const Bureaucrat::GradeTooLowException &error)
    {
        std::cerr << error.what();
    }
    std::cout << std::endl;
       try
    {
        Form Document2("Document2", false, 15, 15);
        Bureaucrat Rose("Rose", 1);
        Rose.signForm(Document2);
    }
    catch(const Bureaucrat::GradeTooHighException &error)
    {
        std::cerr << error.what();
    }
    catch(const Bureaucrat::GradeTooLowException &error)
    {
        std::cerr << error.what();
    }
    return(0);
}