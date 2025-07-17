#include "Harl.hpp"

int main(void)
{
	Harl	angryClient;

    std::cout << std::endl;
	angryClient.complain("DEBUG");
    std::cout << std::endl;
	angryClient.complain("INFO");
    std::cout << std::endl;
	angryClient.complain("WARNING");
    std::cout << std::endl;
	angryClient.complain("ERROR");
    std::cout << std::endl;
    angryClient.complain("ERRORNOTFOUND");
	return(0);
}