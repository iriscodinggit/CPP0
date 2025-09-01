/*main parse
    number of arguments == 2
    can open file? no empty file?
//parse per line
valid short csv format? date | value in ALL lines? show: error: bad input -> (line content) Important: even if a line is bad, still has to show the vlaue of the other lines that ae good. string to int
valid date 2009-2025, 1-12, 1-31 (excepto febrero y trententos),
all values in short csv are ints/floats between 0 and 1000?
if not, print errors
//retrieve values
read shortCSV first line, save date and search in long csv...do i search by binary search or line by line (there are 1613 lines)
if the exact value is not found (current value is bigger after finishing binary search), take the previous one to that
take that value and save it 
take the amout of bitcoin and save it 
multiply both values
print the aswer*/

#include "BitcoinExchange.hpp"
#include <fcntl.h>

void parseInputFile(std::string inputFile)
{

}

//necessary to cjeck if the file is empty?
//what does getline return?
void main(int argc, char **argv)
{
    BitcoinExchange BitcoinObject;

    if (argc != 2)
    {
        std::cout << "Error: wrong number of arguments. Usage: ./btc input.txt" << std::endl;
        return;
    }
    BitcoinObject.fillMap();
    parseInputFile(argv[1]);
    
    std::string line;// FirstWord, ValorStr, DataLine;
    std::string date;
    std::string bitcoins;
    float Valor; //, ValorData, Result; 
    std::ifstream inputFile(argv[1]);
    
    if(!inputFile.is_open())
    {
        return(std::cout << "Error: could not open file.\n", 1);
     if (inputFile.peek() == std::ifstream::traits_type::eof())
		{
			std::cerr << "Error: file is empty." << std::endl;
			return;
		}
    while(std::getline(inputFile, line))
    {
		    if (line.find('|') != std::string::npos)  
        {
	        std::istringstream parseLine(line);
	        std::getline(iss, FirstWord, '|');
	        if(valid_date(FirstWord) == true)
	        {
	            std::getline(iss, ValorStr);
	            Valor = strtod(ValorStr.c_str(), NULL);
	            ValorData = BitcoinData.GetRate(FirstWord);
	            Result = Valor * ValorData;
	            if(Result < 0)
	                std::cout << "Error: not a positive number.\n";
	            else if(Valor > 1000)
	                std::cout <<  "Error: too large a number.\n";
	            else if(Valor < 0)
	                std::cout <<  "Error: too litle a number.\n";
	            else 
	                std::cout << FirstWord << "=> " << Valor << " = " << Result << "\n";
	        }
	       }
    }
    return(0);
}
