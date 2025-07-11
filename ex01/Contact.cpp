/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irlozano <irlozano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 20:29:01 by irlozano          #+#    #+#             */
/*   Updated: 2025/07/11 21:26:19 by irlozano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

//RETURN FUNCTIONS

std::string Contact::retName(void)
{
	return(p_name);
}
std::string Contact::retLastName(void)
{
	return(p_lastname);
}
std::string Contact::retNickname(void)
{
	return(p_nickname);
}
std::string Contact::retPhoneNumber(void)
{
	return(p_phone_number);
}
std::string Contact::retSecret(void)
{
	return(p_secret);
}

//SET FUNCTIONS

void Contact::setName(std::string u_name)
{
	p_name = u_name;
}
void Contact::setLastName(std::string u_LastName)
{
	p_lastname = u_LastName;
}
void Contact::setNickname(std::string u_nickname)
{
	p_nickname = u_nickname;
}
void Contact::setPhoneNumber(std::string u_PhoneNum)
{
	p_phone_number = u_PhoneNum;
}
void Contact::setSecret(std::string u_secret)
{
	p_secret = u_secret;
}