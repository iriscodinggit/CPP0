#include "Array.hpp"

int main()
{ //?
    try 
    {
        Array<char> B(15);
        for(unsigned int i = 0; i < B.size(); i++)
            B[i] = i + '0';
        std::cout << "Array builted\n";
        for(unsigned int i = 0; i < B.size(); i++)
            std::cout << B[i] << "\n";
        std::cout << " ---------------- \n";
        Array<char> C(B);
        std::cout << "New object created, testing his content that got copied\n";
        for(unsigned int i = 0; i < C.size(); i++)
            std::cout << C[i] << "\n";
        Array<char> D(1);
        std::cout << "Object D empty, using = to fill the content\n";
            D = B;
        std::cout << "Testing the content\n";
        for(unsigned int i = 0; i < D.size(); i++)
            std::cout << D[i] << "\n";
    }
	catch (const std::exception &e)
	{
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}