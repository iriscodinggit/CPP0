#include <iostream>

int main(void)
{
	std::string greeting = "HI THIS IS BRAIN";
	std::string *stringPTR = &greeting;
	std::string &stringREF = greeting;

    std::cout << std::endl << "🧟 Memory addresses:" << std::endl << std::endl;
	std::cout << "🧠 stringVAR -> " << &greeting << std::endl;
	std::cout << "🧠 stringPTR -> " << stringPTR << std::endl;
	std::cout << "🧠 stringREF -> " << &stringREF << std::endl;
	std::cout << " --------------------------------- " << std::endl;
    std::cout << "🧟 Values:" << std::endl << std::endl;
	std::cout << "🧠 stringVAR -> " << greeting << std::endl;
	std::cout << "🧠 stringPTR -> " << *stringPTR << std::endl;
	std::cout << "🧠 stringREF -> " << stringREF << std::endl;	 
}