/*check if input is exit (return)
add (call add fucntion)
search (call search function)
*/
#include "Phonebook.hpp"

int main(void)
{
    PhoneBook   Book;
    std::string input;
    int         i = 0;

    std::cout << "☎️ Ring, ring! Welcome to the free Phonebook version! Once you exit the programme, all your contacts (max. 8) will get lost. LOL!\n";
    std::cout << "☎️ Please type ADD, SEARCH or EXIT\n";
    while (true)
    {
        if (i == 8)
        {
            std::cout << "⚠️ Warning: You've reached the maximum number of contact slots available (8). If you add a new contact, it will be replaced for the least recent one.\n"
            i = 0;
        }
        std::getline(std::cin, input);
        if (input == "EXIT")
            break;
        else if (input == "ADD")
        {
            addContact(&Book.users[i]);
            i++;
        }
        else if (input == "SEARCH")
            search(&Book);
    }
    std::cout << "☎️ Bye, bye!\n";
    return (0);
}