#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){};

BitcoinExchange::BitcoinExchange(const BitcoinExchange& otherBitcoinExchange) : _dateRate(otherBitcoinExchange._dateRate){};

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& otherBitcoinExchange)
{
    if(this != &otherBitcoinExchange)
        this->_dateRate = otherBitcoinExchange._dateRate;
    return (*this);
}

float BitcoinExchange::searchRate(const std::string& date) const
{
	std::map<std::string, float>::const_iterator i = _dateRate.find(date);
	if(i != _dateRate.end()) //check for exact coincidence of date in database
	    return(i->second);
	i = _dateRate.lower_bound(date); //returns a value with a key no less than the given key. En este caso el siguiente mayor al date que buscamos
	if(i != _dateRate.begin()) //si no es ya el primer elemnto de la lista, vamos al anterior porque se retorna la fecha más cercana ANTERIOR
	{
        i--;
        return (i->second);
    }
	//if(i != _dateRate.end()) //I THINK THIS CHECK IS NOT NECCESSARY CAUSE THE ONLY MOMENT WHERE IT CAN BE END IS IF THE MAP IS EMPTY BUT I ALREADY ADDED A CHECK FOR THAT WE ALREADY KNOW THAT THE FILE IS NOT EMPTY AND CHECK THE DATE IS BIGGER OR EQUAL TO 2009-01-02
	   // return(i->second);
	std::cerr << "Error: Invalid date. Choose a date starting from 2009-01-02." << std::endl;
	std::exit(1);
}

void BitcoinExchange::fillMap(void) //CONTINUE
{
    std::string line;
    std::string date;
    std::string rate;
    std::ifstream DBFile("data.csv");
    
    if(!DBFile.is_open())
    {
        std::cout << "Error: could not open file -> data.csv." << std::endl;
        return ;
    }
    if (DBFile.peek() == std::ifstream::traits_type::eof())
	{
		std::cerr << "Error: file is empty." << std::endl;
		return;
	}
    std::getline(DBFile, line); //getline returns a line until it finds an end of line or EOF. This time we just skip the first line which is date, exchange_rate
    while (std::getline(DBFile, line)) //as long as we don't reach the end of the database
    {
        size_t comma_pos = line.find(',');
        if (comma_pos != std::string::npos) //npos is a const that means is "no position found" (not found)
        {
            date = line.substr(0, comma_pos);
            rate = line.substr(comma_pos + 1);
            this->_dateRate[date] = strtof(rate.c_str(), NULL);
        }
    }
}