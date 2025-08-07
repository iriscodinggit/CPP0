#include "../headers/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", false, 145, 137), _target("DefaultForm")
{
    std::cout << "Default consdtructor for ShrubberyCreationForm has been called -> " << *this << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", false, 145, 137), _target(target)
{
    /*if (_gradeToExec > 150 || _gradeToSign > 150)
        throw (GradeTooLowException());
    else if(_gradeToExec < 1 || _gradeToSign < 1)
        throw (GradeTooHighException());*/ //we don't need to include this again because it inherits it from the AForm parent
    std::cout << "Constructor for ShrubberyCreationForm has been called -> " << *this << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& otherForm) : AForm(otherForm), _target(otherForm._target)
{
    std::cout << "Copy constructor for ShrubberyCreationForm has been called -> " << *this << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& otherForm)
{
    if (this != &otherForm)
    {
        AForm::operator=(otherForm); //este solo copiaba el signedStatus
        _target = otherForm._target;
    }
    std::cout << "Copy overload for ShrubberyCreationForm has been called" << std::endl;
    return(*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "Destructor for ShrubberyCreationForm has been called" << std::endl;
}

void    ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
    if(getSignedStatus() == false)
        throw(AForm::FormNotSigned()); //i can't just do throw("Form is not signed!") because that is a string not an excetpion object so it cannot be "caught"
    else if(executor.getGrade() > getGradeToExec())
        throw(AForm::GradeTooLowException());
    std::ofstream newFile((_target + "_shrubbery").c_str()); //ofstream (output file stream es para escribir en un archivo, en este caso target_shrubbery) c_str() (const string) es para pasar la string de target_shrubbery a const string, ya que newFile necesita un const
    newFile << "🌲  Some new trees have been planted in " << _target << "!" << std::endl << std::endl;
    newFile << "        *" << std::endl;
    newFile << "       ***" << std::endl;
    newFile << "      *****" << std::endl;
    newFile << "     *******" << std::endl;
    newFile << "       |||" << std::endl;
    newFile << std::endl;
    newFile << "              &&&" << std::endl;
    newFile << "             &&&&&" << std::endl;
    newFile << "           &&&&&&&&&" << std::endl;
    newFile << "          &&&&&&&&&&&" << std::endl;
    newFile << "              |||" << std::endl;
    newFile << std::endl;
    newFile.close();
}