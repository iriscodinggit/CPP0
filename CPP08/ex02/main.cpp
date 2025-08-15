#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17); //pushes to the top
    std::cout << mstack.top() << std::endl; //top returns a reference to the top element, prints the top element (17)
    mstack.pop(); //removes the top element, so now we only have 5
    std::cout << mstack.size() << std::endl; //prints the size (1)
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin(); //it points at the start of the list
    MutantStack<int>::iterator ite = mstack.end(); //ite points past the end of the list
    ++it;
    --it;
    while (it != ite) //while we don't reach the end, iterate and print
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack); //crea un stack a partir de mstack
   
   //extra

    std::cout << std::endl << "⭐ Let's try with a list!" << std::endl;
    std::list<int> myList;
    myList.push_back(5);
    myList.push_back(17);
    std::cout << std::endl << myList.back() << std::endl;
    myList.pop_back();
    std::cout << myList.size() << std::endl;
    myList.push_back(3);
    myList.push_back(5);
    myList.push_back(737);
    myList.push_back(0);

    std::list<int>::iterator i = myList.begin();
    std::list<int>::iterator end = myList.end();
    while (i != end)
    {
        std::cout << *i << std::endl;
        ++i;
    }
    return 0;
}