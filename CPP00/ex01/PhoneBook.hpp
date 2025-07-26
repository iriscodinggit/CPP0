#ifndef PHONE_BOOK_H //importante incluir headguard
# define PHONE_BOOK_H
#include <iostream>
#include <iomanip>
#include <sstream>
//no deja usarlo porque es de c11 #include <string>

#include "Contact.hpp"

class PhoneBook
{
    public:
            PhoneBook(){}; //constructor para inicializar, no hace nada
            Contact users[8];
};

void    addContact(Contact &users);
void    addData(Contact &user, void (Contact::*function)(std::string), std::string message);
void    searchContact(PhoneBook &Book);
void    displayContact(PhoneBook &Book, int i);
void    truncate(std::string &data);
void    fullDisplay(PhoneBook &Book, int i);

#endif