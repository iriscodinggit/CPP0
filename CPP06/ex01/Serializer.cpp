#include "Serializer.hpp"

//static_cast is used for conversions between related types, like int to float. but here we pass from a Data struct (that has an int member) to a uintptr_t. reinterpret cast is considered unsafe
uintptr_t   Serializer::serialize(Data* ptr)
{
    return(reinterpret_cast<uintptr_t>(ptr)); //we convert to uintptr, which is an integer capable of holding a pointer. For example, a normal pointer would be something in hexadecimal starting with 0x but if you convert it to int it would be a big integer like 14595098309405
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return(reinterpret_cast<Data *>(raw));
}