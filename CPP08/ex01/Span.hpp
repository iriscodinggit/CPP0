#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

class Span
{
    private:
            unsigned int                _N;
            std::vector<unsigned int>   _vector;
    public:
            Span();
            Span(unsigned int N);
            Span(const Span& otherSpan);
            Span& operator=(const Span& otherSpan);
            ~Span();
            void addNumber(unsigned int N);
            int shortestSpan();
            int longestSpan();
            template<typename i>
            void addNumbers(i start, i end)
            {
                if ((std::distance(start, end) + _vector.size()) > _N) 
                    throw(std::out_of_range("Hey go easy! The vector is not that big!"));
                _vector.insert(_vector.end(), start, end);
            }
};

#endif