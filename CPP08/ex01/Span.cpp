#include "Span.hpp"

Span::Span()
{
    _N = 0;
    std::cout << "Default constructor for Span has been called." << std::endl;
}

Span::Span(unsigned int N) : _N(N)
{
    _vector.reserve(N);
    std::cout << "Constructor for Span has been called." << std::endl;
}

Span::Span(const Span& otherSpan) : _N(otherSpan._N), _vector(otherSpan._vector)
{
    std::cout << "Copy constructor for Span has been called." << std::endl;
}

Span::~Span()
{
    std::cout << "Destructor for Span has been called." << std::endl;
}

Span& Span::operator=(const Span& otherSpan)
{
    if(this != &otherSpan)
    {
        this->_vector = otherSpan._vector;
        this->_N = otherSpan._N;
    }
    std::cout << "Copy assignment overload for Span has been called." << std::endl;
    return(*this);
}

void Span::addNumber(unsigned int N)
{
    if(_vector.size() >= _N)
        throw(std::out_of_range("Hey go clean your room! It's already full in here!"));
    _vector.push_back(N);
}

int Span::shortestSpan()
{
    unsigned int minSpan = std::numeric_limits<unsigned int>::max(); //equivalent to MAX_UNSIGNED_INT, since we are going to compare the first distance against this, and unless the values are 0 and MAX_UNSIGNED_INT, it should be lower
    if(_vector.size() < 2)
        throw(std::out_of_range("You need at least two numbers to calculate a span."));

    std::vector<unsigned int> copyOfVector(_vector);
    std::sort(copyOfVector.begin(), copyOfVector.end()); //doesnt return anything, it directly sorts on site directly in memory
    for(size_t i = 1; i < copyOfVector.size(); i++)
    {
        if(copyOfVector[i] - copyOfVector[i - 1] < minSpan)
            minSpan = copyOfVector[i] - copyOfVector[i - 1];
    }
    return(minSpan);
}

int Span::longestSpan()
{
    if(_vector.size() < 2)
        throw(std::out_of_range("You need at least two numbers to calculate a span."));
    std::vector<unsigned int>::iterator i = std::max_element(_vector.begin(), _vector.end());
    std::vector<unsigned int>::iterator j = std::min_element(_vector.begin(), _vector.end());
    return(*i - *j);
}