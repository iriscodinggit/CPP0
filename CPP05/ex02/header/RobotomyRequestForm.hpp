#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        std::string _target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm& otherForm);
        RobotomyRequestForm& operator0(const RobotomyRequestForm& otherForm);
        ~RobotomyRequestForm();
        void execute(Bureaucrat const & executor) const;
};

#endif