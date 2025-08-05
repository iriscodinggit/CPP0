#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("RandomForm"), _signedStatus(false), _gradeToSign(150), _gradeToExec(150)
{
    std::cout << "Default consdtructor for Form has been called -> " << *this << std::endl;
}

Form::Form(std::string name, bool signedStatus, int gradeToSign, int gradeToExec) : _name(name), _signedStatus(signedStatus), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
    if (_gradeToExec > 150 || _gradeToSign > 150)
        throw (GradeTooLowException());
    else if(_gradeToExec < 1 || _gradeToSign < 1)
        throw (GradeTooHighException());
    std::cout << "Constructor for form has been called -> " << *this << std::endl;
}

Form::Form(const Form& otherForm) : _name(otherForm._name), _signedStatus(otherForm._signedStatus), _gradeToSign(otherForm._gradeToSign), _gradeToExec(otherForm._gradeToExec)
{
    std::cout << "Copy constructor for form has been called -> " << *this << std::endl;
}

Form& Form::operator=(const Form& otherForm)
{
    if (this != &otherForm)
        _signedStatus = otherForm._signedStatus; //we only copy signed status because the other variables are const (the subject requires it)
    std::cout << "Copy overload for form has been called" << std::endl;
    return(*this);
}

Form::~Form()
{
    std::cout << "Destructor for form has been called" << std::endl;
}

void Form::beSigned(Bureaucrat &otherBureaucrat)
{
    if (otherBureaucrat.getGrade() > _gradeToSign)
        throw (GradeTooLowException());
    std::cout << "📝  Form has been signed" << std::endl;
    _signedStatus = true;
}

std::string Form::getDocName() const
{
    return(_name);
}

bool Form::getSignedStatus() const
{
    return(_signedStatus);
}

int Form::getGradeToSign() const
{
    return(_gradeToSign);
}

int Form::getGradeToExec() const
{
    return(_gradeToExec);
}

const char* Form::GradeTooHighException::what() const throw()
{
    return("⚠️  Grade is too high!\n");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return("⚠️  Grade is too low!\n");
}

std::ostream& operator<<(std::ostream& outputStream, const Form& otherForm)
{
    outputStream << "📝 Form: " << otherForm.getDocName() << ", signed status: " << otherForm.getSignedStatus() << ", grade to sign: " << otherForm.getGradeToSign() << ", grade to exec: " << otherForm.getGradeToExec();
    return(outputStream);
}