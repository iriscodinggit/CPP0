#include "Serializer.hpp"

int main(void)
{
    Data A;
    Data *B;
    uintptr_t dataAddress;
    
    A.number = 42;
    std::cout << "The address before serialization is: " << &A << std::endl;
    dataAddress= Serializer::serialize(&A);
    std::cout << "The value stored in uintptr_t is: " << dataAddress << std::endl;
    B = Serializer::deserialize(dataAddress);
    std::cout << "The adress after deserialization  is: " << B << std::endl;
    if(&A == B)
        std::cout << "✅ Both addresses match!" << std::endl;
    else
        std::cout << "❌ The addresses don't match!" << std::endl;
    return(0);
}