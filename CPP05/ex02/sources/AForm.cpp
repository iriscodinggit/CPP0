#include "../header/AForm.hpp"
#include "../header/Bureaucrat.hpp"

AForm::AForm() : _name("RandomAForm"), _signedStatus(false), _gradeToSign(150), _gradeToExec(150)
{
    std::cout << "Default consdtructor for AForm has been called -> " << *this << std::endl;
}

AForm::AForm(std::string name, bool signedStatus, int gradeToSign, int gradeToExec) : _name(name), _signedStatus(signedStatus), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
    if (_gradeToExec > 150 || _gradeToSign > 150)
        throw (GradeTooLowException());
    else if(_gradeToExec < 1 || _gradeToSign < 1)
        throw (GradeTooHighException());
    std::cout << "Constructor for AForm has been called -> " << *this << std::endl;
}

AForm::AForm(const AForm& otherAForm) : _name(otherAForm._name), _signedStatus(otherAForm._signedStatus), _gradeToSign(otherAForm._gradeToSign), _gradeToExec(otherAForm._gradeToExec)
{
    std::cout << "Copy constructor for AForm has been called -> " << *this << std::endl;
}

AForm& AForm::operator=(const AForm& otherAForm)
{
    if (this != &otherAForm)
        _signedStatus = otherAForm._signedStatus; //we only copy signed status because the other variables are const (the subject requires it)
    std::cout << "Copy overload for AForm has been called" << std::endl;
    return(*this);
}

AForm::~AForm()
{
    std::cout << "Destructor for AForm has been called" << std::endl;
}

void AForm::beSigned(Bureaucrat &otherBureaucrat)
{
    if (otherBureaucrat.getGrade() > _gradeToSign)
        throw (GradeTooLowException());
    std::cout << "📝  AForm has been signed" << std::endl;
    _signedStatus = true;
}

std::string AForm::getDocName() const
{
    return(_name);
}

bool AForm::getSignedStatus() const
{
    return(_signedStatus);
}

int AForm::getGradeToSign() const
{
    return(_gradeToSign);
}

int AForm::getGradeToExec() const
{
    return(_gradeToExec);
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return("Grade is too high!\n");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return("Grade is too low!\n");
}

std::ostream& operator<<(std::ostream& outputStream, const AForm& otherAForm)
{
    outputStream << "📝 AForm: " << otherAForm.getDocName() << ", signed status: " << otherAForm.getSignedStatus() << ", grade to sign: " << otherAForm.getGradeToSign() << ", grade to exec: " << otherAForm.getGradeToExec();
    return(outputStream);
}