#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

#include <list> //for what?
#include <iostream>
#include <iterator>
#include <stack>


template<typename T>
class MutantStack : public std::stack<T>
{
    public:
        typedef typename std::stack<T>::container_type::iterator iterator; //typedef?
        typedef typename std::stack<T>::container_type::const_iterator const_iterator; //two iterators to be ablle to iterate in const and non const elements?
        inline iterator	begin() {return(this->c.begin());}; //change inlines (can i define the in hpp?)
        inline iterator end() {return(this->c.end());};
        inline const_iterator begin() const {return(this->c.begin());};
        inline const_iterator end() const {return(this->c.end());};
};

#endif