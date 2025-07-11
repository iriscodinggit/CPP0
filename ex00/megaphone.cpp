#include <iostream>

int main(int argc, char **argv)
{
    int i = 1;
    long unsigned int j = 0; //to avoid warnings when comparing j to arg.length()

    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl; //we use cout instead of printf for c++ style
    else
    {
        for (i = 1; i < argc; i++)
        {
            std::string str = argv[i]; //we use std::string instead of argv[i][j] to make it more c++ style
            for (j = 0; j < str.length(); j++)
                std::cout << (char)std::toupper(str[j]); //to upper is also c++ style (function from std)
        }
        std::cout << std::endl;
    }
    return (0);
}
