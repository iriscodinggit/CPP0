#include "whatever.hpp"

struct Bank //this struct is for my tests
{
    int money;

    bool operator <(const Bank& otherBank) const
    {
        if (money < otherBank.money)
            return (true);
        else
            return (false);
    }

    bool operator >(const Bank& otherBank) const
    {
        if (money > otherBank.money)
            return (true);
        else
            return (false);
    }

    bool operator ==(const Bank& otherBank) const
    {
        if (money == otherBank.money)
            return (true);
        else
            return (false);
    }
};

std::ostream& operator<<(std::ostream& outputStream, const Bank& Bank)
{
    outputStream << "Money in the bank: " << Bank.money;
    return outputStream;
}

int main( void )
{
    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    std::cout << std::endl;
    
    //these are for my tests
    Bank BankPoor;
    Bank BankRich;

    BankPoor.money = 0;
    BankRich.money = 1000000;
    ::swap(BankPoor, BankRich);

    std::cout << "💰 BankPoor -> " << BankPoor << ", BankRich -> " << BankRich << std::endl;
    std::cout << "💰 min(BankPoor, BankRich) = " << ::min(BankPoor, BankRich) << std::endl;
    std::cout << "💰 max(BankPoor, BankRich) = " << ::max(BankPoor, BankRich) << std::endl;
    return 0;
}