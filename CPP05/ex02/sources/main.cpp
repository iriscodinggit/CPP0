#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    try
    {
        Form Document1("Document1", false, 15, 100);
        Bureaucrat Amy("Amy", 100);
        std::cout << std::endl;
        Amy.signForm(Document1);
        std::cout << std::endl;
    }
    catch(const std::exception &error) // captura tanto Bureaucrat como Form
    {
        std::cerr << error.what();
    }
    std::cout << std::endl;
       try
    {
        Form Document2("Document2", false, 15, 15);
        Bureaucrat Rose("Rose", 1);
        std::cout << std::endl;
        Rose.signForm(Document2);
        std::cout << std::endl;
    }
    catch(const std::exception &error) // Captura tanto Bureaucrat como Form
    {
        std::cerr << error.what();
    }
    return(0);
}