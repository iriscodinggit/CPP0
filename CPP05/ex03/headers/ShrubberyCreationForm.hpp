#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
        std::string _target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm& otherForm);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& otherForm);
        ~ShrubberyCreationForm();
        void execute(Bureaucrat const & executor) const;
};

#endif