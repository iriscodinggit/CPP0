#include "Array.hpp"

struct Bank //this struct is for my tests
{
    int money;
};

int main()
{ 
    try 
    {
        Array<int> NotebookA(5);
        for(unsigned int i = 0; i < NotebookA.size(); i++)
            NotebookA[i] = i + 1;
        std::cout << "🧙 An int array (NotebookA) has been built using a template." << std::endl << std::endl;
        for(unsigned int i = 0; i < NotebookA.size(); i++)
            std::cout << NotebookA[i] << std::endl;

        Array<int> NotebookB(NotebookA);
        std::cout << std::endl << "🧙 An int array (NotebookB) has been built from NoteBookA." << std::endl << std::endl;
        for(unsigned int i = 0; i < NotebookB.size(); i++)
            std::cout << NotebookB[i] << std::endl;
        Array<int> NotebookC(1);
        std::cout << std::endl << "🧙 An int array (NotebookC) has been built with an specific number of elements (1)." << std::endl;
        //std::cout << NotebookC[10] << std::endl; //try to throw an exception
        NotebookC = NotebookA;
        std::cout << "The contents have been copied from NotebookA." << std::endl << std::endl;
        for(unsigned int i = 0; i < NotebookC.size(); i++)
            std::cout << NotebookC[i] << std::endl;

        Array<Bank> BankArray(3);
        std::cout << std::endl << "🧙 A Bank array has been built from a template." << std::endl;
        BankArray[0].money = 500;
        BankArray[1].money = 1000;
        BankArray[2].money = 1500;

        for (unsigned int i = 0; i < 3; i++)
        std::cout << std::endl << "BankArray[" << i << "].money = " << BankArray[i].money << " euros" << std::endl;
    }
	catch (const std::exception &error)
	{
        std::cerr << "Exception caught: " << error.what() << std::endl;
    }

    return (0);
}

/*#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] == numbers[i])
        {
            std::cerr << " same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}*/