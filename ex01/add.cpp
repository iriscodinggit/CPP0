/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irlozano <irlozano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 20:28:48 by irlozano          #+#    #+#             */
/*   Updated: 2025/07/11 20:28:48 by irlozano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

void addData(Contact &users, void (Contact::*function)(std::string), std::string field) //el 2º argumento es un puntero a una función de tipo void que devuelve un string
{
    std::string input;

    while(input.length() == 0) //si el user pulsa ENTER para intentar skippear rellenar los detalles del contacto, el bucle sigue preguntando hasta que introduzca algo
    {
        std::cout << field; //Imprime el mensaje, como "Name: "
        std::getline(std::cin, input); //espera y guarda el input del usuario
    }
    (users.*function)(input); //puntero equivalente a decir users.setName(input) o setNickname, setPhoneNumber...
    return ;
}

void    addContact(Contact &users)
{
    std::cout << "☎️ Your social circle is getting bigger! Please add your new contact's details.\n";
    addData(users, &Contact::setName, "Name:");
    addData(users, &Contact::setLastName, "Last name:");
    addData(users, &Contact::setNickname, "Nickname:");
    addData(users, &Contact::setPhoneNumber, "Phone Number:");
    addData(users, &Contact::setSecret, "Secret:");
    std::cout << "☎️ Contact has been added!\n";
    return ;
}