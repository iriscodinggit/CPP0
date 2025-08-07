#include "../headers/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", false, 72, 45), _target("DefaultForm")
{
    std::srand(std::time(NULL)); //srand gives the seed for the "random numbers", but not the numbers themselves (that comes later in executor). it takes a seed, could be an int like 42, or a time(NULL), different seed every second. the equivalent in modern C+ is random(). time() returns the current calndar time (number of seconds since january 1, 1970 (unix epoch))
    std::cout << "Default consdtructor for RobotomyRequestForm has been called -> " << *this << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", false, 72, 45), _target(target)
{
    /*if (_gradeToExec > 150 || _gradeToSign > 150)
        throw (GradeTooLowException());
    else if(_gradeToExec < 1 || _gradeToSign < 1)
        throw (GradeTooHighException());*/ //we don't need to include this again because it inherits it from the AForm parent
    std::srand(std::time(NULL));
    std::cout << "Constructor for RobotomyRequestForm has been called -> " << *this << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& otherForm) : AForm(otherForm), _target(otherForm._target)
{
    std::cout << "Copy constructor for RobotomyRequestForm has been called -> " << *this << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& otherForm)
{
    if (this != &otherForm)
    {
        AForm::operator=(otherForm); //este solo copiaba el signedStatus
        _target = otherForm._target;
    }
    std::cout << "Copy overload for RobotomyRequestForm has been called" << std::endl;
    return(*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "Destructor for RobotomyRequestForm has been called" << std::endl;
}

void    RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
    if(getSignedStatus() == false)
        throw(AForm::FormNotSigned()); //i can't just do throw("Form is not signed!") because that is a string not an excetpion object so it cannot be "caught"
    else if(executor.getGrade() > getGradeToExec())
        throw(AForm::GradeTooLowException()),
    std::cout << "🤖 Bip bop bip! RRRRRRRRRRRRRRRRRRR! Bip bop bip!" << std::endl;
    if (std::rand() % 2) //rand generates the actual random number, while srand just creates the seed
        std::cout << "🤕🔨 The robotomy for " << _target << " has failed. You can always try again..." << std::endl;
    else
        std::cout << "🤖 The robotomy has been a success! " << _target << " is feeling good as new! ✨" << std::endl;
}