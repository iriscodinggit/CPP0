#include "../headers/Intern.hpp"

Intern::Intern() //aquí qué pongo para inicializar el target? nada, porque target no es atributo de intern, es argumento de makeForm
{
    std::cout << "Default constructor for Intern has been called" << std::endl;
}

Intern::Intern(const Intern& otherIntern)
{
    (void)otherIntern;
    std::cout << "Copy constructor for Intern has been called" << std::endl;
}

Intern& Intern::operator=(const Intern &otherIntern)
{
    (void)otherIntern; //we don't need to copy anything because Intern has no attributes
    std::cout << "Assignment overload for Intern called" <<  std::endl;
    return(*this);
}

Intern::Intern::~Intern()
{
    std::cout << "Destructor for Intern has been called" << std::endl;
}

AForm* CreatePresidential(const std::string& target)
{
    return (new PresidentialPardonForm(target));
}

AForm* CreateRobotomy(const std::string& target)
{
    return (new RobotomyRequestForm(target));
}

AForm* CreateShrubbery(const std::string& target)
{
    return (new ShrubberyCreationForm(target));
}

AForm* Intern::makeForm(const std::string formName, const std::string target) //each function takes a target and returns a newly created form
{
    const   std::string possibleForms[] = {"shrubbery request", "robotomy request", "presidential request"};
    AForm* (*formFunctions[])(const std::string&) =
    {
        CreateShrubbery,
        CreateRobotomy,
        CreatePresidential
    };
    for(int i = 0; i < 3; i++)
    {
        if(formName == possibleForms[i])
        {
            std::cout << "Intern creates " << formName << " form." << std::endl;
            return(formFunctions[i](target)); //returns pointer to the newly created form
        }
    }
    std::cout << "Sorry, but that form is not available. Try one of these options: shrubbery request, robotomy request, presidential request." << std::endl;
    return (NULL);
}