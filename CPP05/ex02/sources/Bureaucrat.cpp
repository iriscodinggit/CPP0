#include "../headers/Bureaucrat.hpp"
#include "../headers/AForm.hpp"

Bureaucrat::Bureaucrat() : _name("RandomBureaucrat"), _grade(1)
{
    std::cout << "Default constructor for Bureaucrat has been called -> " << *this << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    if (grade > 150)
        throw GradeTooLowException();
    else if (grade < 1)
        throw GradeTooHighException();
    else
        _grade = grade;
    std::cout << "Constructor for Bureaucrat has been called -> " << *this << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& otherBureaucrat) : _name(otherBureaucrat._name), _grade(otherBureaucrat._grade)
{
    std::cout << "Copy constructor for Bureaucrat has been called -> " << *this << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &otherBureaucrat)
{
    if (this != &otherBureaucrat)
        _grade = otherBureaucrat._grade; //we don't copy name cause it's constant so it can't be initialised more than once (the = overload is used after the first initialisation)
    std::cout << "Assignment overload for Bureaucrat called -> " << *this << std::endl;
    return(*this);
}

Bureaucrat::Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor for Bureaucrat has been called" << std::endl;
}

int Bureaucrat::getGrade() const
{
    return(_grade);
}

std::string Bureaucrat::getName() const
{
    return(_name);
}

void Bureaucrat::increaseGrade()
{
    if(_grade <= 1)
        throw(GradeTooHighException()); //1 is the top rank that's why it's highest
    _grade--;
    std::cout << "📈💰 Bureaucrat has been promoted! ->" << *this << std::endl;
}

void Bureaucrat::decreaseGrade()
{
    if(_grade >= 150)
        throw(GradeTooLowException()); //1 is the top rank that's why it's highest
    _grade++;
    std::cout << "📉🙇🏻 Bureaucrat has been demoted! ->" << *this << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return("Grade is too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return("Grade is too low!");
}

void Bureaucrat::signForm(AForm &document)
{
    try
    {
        document.beSigned(*this);
        std::cout << "📝  " << _name << " signed " << document.getDocName() << std::endl;
    }
    catch(const std::exception& error)
    {
        std::cerr << "🚨 Form has not been signed" << std::endl;
        std::cout << "🚨 " << _name << " couldn't sign " << document.getDocName() << " because: " << error.what();
    }
    
}

void Bureaucrat::executeForm(AForm const & form) const
{
    try
    {
        form.execute(*this); //execute la coge de Aform.hpp porque es pública y Bureaucrat incluye el header de Aform en su header
        std::cout << _name << " executed " << form.getDocName() << std::endl;
    }
    catch(const AForm::GradeTooLowException &error)
    {
        std::cout << _name << " could not execute " << form.getDocName() << " because the grade is too low." << std::endl;
    }
    catch(const std::exception& error)
    {
        std::cerr << "🚨 Form needs to be signed before it is executed." << std::endl;
    }
}

std::ostream& operator<<(std::ostream& outputStream, const Bureaucrat& otherBureaucrat)
{
    outputStream << otherBureaucrat.getName() << ", bureaucrat grade " << otherBureaucrat.getGrade();
    return(outputStream);
}