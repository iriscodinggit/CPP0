#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
    private:
            const std::string   _name;
            int                 _grade;
    public:
            Bureaucrat();
            Bureaucrat(std::string name, int grade);
            Bureaucrat(const Bureaucrat& otherBureaucrat);
            Bureaucrat& operator=(const Bureaucrat& otherBureaucrat);
            ~Bureaucrat();
            
            std::string getName() const;
            int         getGrade() const;
            void        increaseGrade();
            void        decreaseGrade();

            //Exceptions

            class GradeTooHighException : public std::exception
            {
                public:
                        virtual const char* what() const throw(); //throw keyword tells the compiler that the function is guaranteed to neveer throw an exception
            };

            class GradeTooLowException : public std::exception
            {
                public:
                        virtual const char* what() const throw();
            };
};

std::ostream& operator<<(std::ostream& outputStream, const Bureaucrat& otherBureaucrat);

#endif