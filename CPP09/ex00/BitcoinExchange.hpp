#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm> //find does linear search (one by one), not binary search

class BitcoinExchange
{
    private:
                std::map<std::string, float> _dateRate;
    public:
                BitcoinExchange();
                BitcoinExchange(const BitcoinExchange& otherBitcoinExchange);
                BitcoinExchange& operator=(const BitcoinExchange& otherBitcoinExchange);
                ~BitcoinExchange();
                void    fillMap(void);
                float   searchRate(const std::string &date) const;
};

#endif