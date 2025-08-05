#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class Form
{
    private:
            const std::string   _name;
            bool                _signedStatus;
            const int           _gradeToSign;
            const int           _gradeToExec;
    public:
            Form();
            Form(std::string name, bool signedStatus, int gradeToSign, int gradeToExec);
            Form(const Form& otherForm);
            Form& operator=(const Form& other);
            ~Form();
            std::string getDocName() const;
            bool        getSignedStatus() const;
            int         getGradeToSign() const;
            int         getGradeToExec() const;
            void        beSigned(Bureaucrat& otherBureaucrat);
            class GradeTooHighException : public std::exception
            {
                public:
                        virtual const char* what() const throw(); //throw keyword tells the compiler that the function is guaranteed to never throw an exception
            };
            class GradeTooLowException : public std::exception
            {
                public:
                        virtual const char* what() const throw();
            };
};
std::ostream& operator<<(std::ostream& outputStream, const Form &otherForm);

#endif