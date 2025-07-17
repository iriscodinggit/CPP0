#ifndef HARL_HPP_
#define HARL_HPP_

#include <iostream>

class Harl
{
public:
    void complain(std::string level);
private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
};

#endif