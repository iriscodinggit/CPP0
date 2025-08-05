#ifndef A_FORM_HPP
# define A_FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class AForm
{
    private:
            const std::string   _name;
            bool                _signedStatus;
            const int           _gradeToSign;
            const int           _gradeToExec;
    public:
            AForm();
            AForm(std::string name, bool signedStatus, int gradeToSign, int gradeToExec);
            AForm(const AForm& otherForm);
            AForm& operator=(const AForm& other);
            ~AForm();
            std::string         getDocName() const;
            bool                getSignedStatus() const;
            int                 getGradeToSign() const;
            int                 getGradeToExec() const;
            void                beSigned(Bureaucrat& otherBureaucrat);
            virtual     void    execute(Bureaucrat const & executor) const = 0; // 0 para que sea de tipo abstract (solo vale de plantilla, no se puede instanciar). el & volando es porque el subject pide declararlo así. es una referencia a un bureaucrat constante. No necesitamos definirla en el .cpp es solo para  que todas las clases form hijas (presidential, robotomy...)tengan una funcion que se llame igual (execute)
            class GradeTooHighException : public std::exception
            {
                public:
                        virtual const char* what() const throw(); //throw keyword tells the compiler that the function is guaranteed to never throw an exception si devolviese un int sería throw(int) pero como está vacío no devuelve nada. En c11 ya no se usa throw, se usa noexception
            };
            class GradeTooLowException : public std::exception
            {
                public:
                        virtual const char* what() const throw();
            };
};
std::ostream& operator<<(std::ostream& outputStream, const AForm &otherForm);

#endif