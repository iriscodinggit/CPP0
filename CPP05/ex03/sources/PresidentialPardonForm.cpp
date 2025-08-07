#include "../headers/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", false, 25, 5), _target("DefaultForm")
{
    std::cout << "Default consdtructor for PresidentialPardonForm has been called -> " << *this << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", false, 25, 5), _target(target)
{
    /*if (_gradeToExec > 150 || _gradeToSign > 150)
        throw (GradeTooLowException());
    else if(_gradeToExec < 1 || _gradeToSign < 1)
        throw (GradeTooHighException());*/ //we don't need to include this again because it inherits it from the AForm parent
    std::cout << "Constructor for PresidentialPardonForm has been called -> " << *this << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& otherForm) : AForm(otherForm), _target(otherForm._target)
{
    std::cout << "Copy constructor for PresidentialPardonForm has been called -> " << *this << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& otherForm)
{
    if (this != &otherForm)
    {
        AForm::operator=(otherForm); //este solo copiaba el signedStatus
        _target = otherForm._target;
    }
    std::cout << "Copy overload for PresidentialPardonForm has been called" << std::endl;
    return(*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "Destructor for PresidentialPardonForm has been called" << std::endl;
}

void    PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
    if(getSignedStatus() == false)
        throw(AForm::FormNotSigned()); //i can't just do throw("Form is not signed!") because that is a string not an excetpion object so it cannot be "caught"
    else if(executor.getGrade() > getGradeToExec())
        throw(AForm::GradeTooLowException());
    std::cout << "🌌🪐💫 Interstellar breaking news!: " <<_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}