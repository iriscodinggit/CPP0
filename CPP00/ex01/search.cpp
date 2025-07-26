/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irlozano <irlozano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 20:28:55 by irlozano          #+#    #+#             */
/*   Updated: 2025/07/11 21:26:03 by irlozano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

void truncate(std::string data)
{
    std::cout << "|";

    if (data.length() > 10)
    {
        // Too long: truncate and add dot
        std::cout << data.substr(0, 9) + ".";
    }
    else
    {
        // Short or exact: right-align with spaces
        std::cout << std::right << std::setw(10) << data;
    }
}

void displayContact(PhoneBook &Book, int id)
{
	std::cout << "|" << std::setw(10) << id; 
	truncate(Book.users[id].retName());
	truncate(Book.users[id].retLastName());
	truncate(Book.users[id].retNickname());
	std::cout << "|\n";
}

void fullDisplay(PhoneBook &Book, int id)
{
	std::cout << "------------------------------------\n";
	std::cout << "Name : " << Book.users[id].retName() << "\n";
	std::cout << "Last Name : " << Book.users[id].retLastName() << "\n";
	std::cout << "Nickname : " << Book.users[id].retNickname() << "\n";
	std::cout << "Phone number : " << Book.users[id].retPhoneNumber() << "\n";
	std::cout << "Darkest secret : " << Book.users[id].retSecret() << "\n";
	std::cout << "------------------------------------\n";
}

void searchContact(PhoneBook &Book)
{
	int empty_slots = 0; //empty contact slots
	int id = 0;
	std::string input = "";

	std::cout << "---------------------------------------------\n";
	std::cout << "|        id|      Name| Last Name| Nick Name|" << "\n---------------------------------------------\n";
	while (id < 8)
	{
		if(Book.users[id].retName() == "")
			empty_slots++; //empty contacts, change for blank_slots
		else
			displayContact(Book, id);
		id++;
	}
	std::cout << "---------------------------------------------\n";
	int used_slots = 8 - empty_slots;
	if (used_slots == 0) 
	{
		std::cout << "🌌 You have 0 contacts! Why not signing up for a networking event?\n"; 
		return ;
	}
	while (input.size() != 1 || !isdigit(input[0]) || input[0] < '0' || input[0] > (used_slots - 1 + '0'))
	{
		std::cout << "☎️ Select an ID from 0 to " << used_slots - 1 << ":\n"; 
		std::getline(std::cin, input);
	}
	std::istringstream converted(input); //crea un flujo a la string input, como leer desde cin o stdin
    converted >> id;  //convertimos el index a int
	fullDisplay(Book, id);
	return ;
}