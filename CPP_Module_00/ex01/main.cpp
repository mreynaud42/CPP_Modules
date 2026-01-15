/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 22:19:39 by mreynaud          #+#    #+#             */
/*   Updated: 2025/01/26 21:40:26 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

bool	add(PhoneBook *phoneBook)
{
	Contact		contact;
	std::string	str;

	while (str.empty())
	{
		std::cout << "enter the contact's first name: ";
		std::getline(std::cin, str);
		if (std::cin.eof())
			return (false);
	}
	contact.setFirstName(str);
	str.clear();
	while (str.empty())
	{
		std::cout << "enter the contact's last name: ";
		std::getline(std::cin, str);
		if (std::cin.eof())
			return (false);
	}
	contact.setLastName(str);
	str.clear();
	while (str.empty())
	{
		std::cout << "enter the contact's nickname: ";
		std::getline(std::cin, str);
		if (std::cin.eof())
			return (false);
	}
	contact.setNickname(str);
	str.clear();
	while (str.empty())
	{
		std::cout << "enter the contact's phone number: ";
		std::getline(std::cin, str);
		if (std::cin.eof())
			return (false);
	}
	contact.setPhoneNumber(str);
	str.clear();
	while (str.empty())
	{
		std::cout << "enter the contact's darkest secret: ";
		std::getline(std::cin, str);
		if (std::cin.eof())
			return (false);
	}
	contact.setDarkestSecret(str);
	phoneBook->setContact(contact);
	return (true);
}

bool	search(PhoneBook phoneBook)
{
	std::string	strIndexPrompt;

	if (!phoneBook.getIsIndex())
	{
		std::cout << "No contact" << std::endl;
		return (true);
	}
	phoneBook.displayPhoneBook();
	while (true) {
		std::cout << "Enter contact index: ";
		std::getline(std::cin, strIndexPrompt);
		if (std::cin.eof())
			return (false);
		else if (strIndexPrompt.size() == 1 && strIndexPrompt[0] >= '0' && strIndexPrompt[0] < '8' && !phoneBook.getContact(strIndexPrompt[0] - '0').getFirstName().empty())
		{
			phoneBook.getContact(strIndexPrompt[0] - '0').printContact();
			return (true);
		}
		else
		{
			std::cout << "Invalid index" << std::endl;
			phoneBook.displayPhoneBook();
		}
	}
	return (false);
}

int	main(void)
{
	PhoneBook	phoneBook;
	std::string	strPrompt;

	while (true) {
		std::cout << "Enter a command: ";
		std::getline(std::cin, strPrompt);
		if (!strPrompt.compare("EXIT") || std::cin.eof())
			return (1);
		else if (!strPrompt.compare("ADD"))
		{
			if (!add(&phoneBook))
				return (1);
		}
		else if (!strPrompt.compare("SEARCH"))
		{
			if (!search(phoneBook))
				return (1);
		}
		else
			std::cout << "Valid command is : ADD, SEARCH, EXIT" << std::endl;
	}
	return (0);
}
