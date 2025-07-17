#include "Harl.hpp"

int findCase(std::string str)
{
	if(str == "DEBUG")
		return(1);
	else if(str == "INFO")
		return(2);
	else if(str == "WARNING")
		return(3);
	else if(str == "ERROR")
		return(4);
	return(5);
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
         std::cout << "👨‍💻 Oops! Please follow this structure: ./harlFilter DEBUG/INFO/WARNING/ERROR" << std::endl;
        return (1);
    }
    
    Harl    angryClient;
    int     caseNumber = findCase(argv[1]);

    switch (caseNumber)
    {
        case 1:
                angryClient.complain("DEBUG");
                // fall through 
        case 2:
                angryClient.complain("INFO");
                // fall through 
        case 3:
                angryClient.complain("WARNING");
                // fall through 
        case 4:
                angryClient.complain("ERROR");
                break;
    default:
            std::cout << "This guy never stops complaning!" << std::endl;
            break;
    }
    return (0);
}