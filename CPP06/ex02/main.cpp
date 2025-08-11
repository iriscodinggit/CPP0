#include "Base.hpp"

Base* generate(void)
{
    srand(time(NULL));
    int randomValue = rand() % 3;
    switch (randomValue)
    {
        case 0:
            std::cout << "Object A has been created." << std::endl;
            return(new A());
        case 1:
            std::cout << "Object B has been created." << std::endl;
            return(new B());
        case 2:
            std::cout << "Object C has been created." << std::endl;
            return(new C());
        default:
            std::cout << "No objects have been created." << std::endl;
            return(NULL);
    }
}

void identify(Base* p)
{
    if(dynamic_cast<A*>(p)) //it returns a pointer if it was able to convert it or NULL if the converssion was not possible. We use A* and not A because we convert from pointer to pointer, not to pointer to object
        std::cout << "The object has been identified from a pointer, it's: Class A." << std::endl;
    else if(dynamic_cast<B*>(p))
        std::cout << "The object has been identified from a pointer, it's: Class B." << std::endl;
    else if(dynamic_cast<C*>(p))
        std::cout << "The object has been identified from a pointer, it's: Class C." << std::endl;
    else
        std::cout << "The object has not been identified." << std::endl;
}

void identify(Base& p)
{
    try //if we use dynamic_cast with references, it throws an exception on error, that's why we use try and catch
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "The object has been identified from an address, it's: Class A." << std::endl; //we use A& because we convert from reference to reference not from reference to object
        return ;
    }
    catch(...){} //i tried using a filled cast based on catching bad_cast exceeption, becase dynamic_cast returns bad_cast exception by default if the cast failed, but it's not 98++
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "The object has been identified from an address, it's: Class B." << std::endl;
        return ;
    }
    catch(...){}
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "The object has been identified from an address, it's: Class C." << std::endl;
        return ;
    }
    catch(...){}
    std::cout << "The object has not been identified." << std::endl;
}

int main()
{
    Base *Meta;
    std::cout << "🧙 Let's generate a random object..." << std::endl << std::endl;
    Meta = generate();
    if(!Meta)
    {
        std::cout << "Error: Object hasn't been created" << std::endl;
        return(1);
    }
    identify(Meta);
    identify(*Meta);
    delete(Meta);
    return(0);
}