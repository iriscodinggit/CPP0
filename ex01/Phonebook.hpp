#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H
#include <iostream>
#include <string.h>

class Contact
{
    public:
            Contact(){};
            std::string getName(void);
            std::string getLastName(void);
            std::string getNickname(void);
            std::string getPhoneNumber(void);
            std::string getSecret(void);
            
            void setName(std::string name);
            void setLastName(std::string last_name);
            void setNickname(std::string nickname);
            void setPhoneNum(std::string PhoneNum);
            void setSecret(std::string secret);
    private:
            std::string p_name;
            std::string p_lastname;
            std::string p_nickname;
            std::string p_phone_number;
            std::string p_secret;
};

class Phonebok
{
    public:
            Phonebook(){};
            Contact users[8];
};

void    addContact(Contact &user_slot);
void    addData(Contact &user, void (Contact::*function)(std::string), std::string message);
void    searchContact(PhoneBook &Book);
void    displayContact(Phonebook &Book, int i);
void    truncate(std::string data);
void    fullDisplay(Phonebook &Book, int i);

#endif