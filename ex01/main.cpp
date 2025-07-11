/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irlozano <irlozano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 19:21:33 by irlozano          #+#    #+#             */
/*   Updated: 2025/07/11 21:26:09 by irlozano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int main(void)
{
    PhoneBook   Book;
    std::string input;
    int         i = 0;

    std::cout << "📞 Ring, ring! Welcome to mini Phonebook! Once you exit the programme, all your contacts will be lost!\n";
    std::cout << "📞 Please type ADD, SEARCH or EXIT\n";
    while (true)
    {
        if (i == 8)
        {
            std::cout << "⚠️ Warning: You've reached the maximum number of contact slots available (8). If you add a new contact, it will be replaced for the least recent one.\n";
            i = 0;
        }
        std::getline(std::cin, input);
        if (input == "EXIT")
            break;
        else if (input == "ADD")
        {
            addContact(Book.users[i]);
            i++;
        }
        else if (input == "SEARCH")
            searchContact(Book);
    }
    std::cout << "📞 Bye, bye!\n";
    return (0);
}