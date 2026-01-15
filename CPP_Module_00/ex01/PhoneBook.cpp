/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:04:56 by mreynaud          #+#    #+#             */
/*   Updated: 2025/02/12 15:08:23 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _index(0), _isIndex(false) {}

PhoneBook::~PhoneBook() {}

Contact	PhoneBook::getContact(int index) const
{
	return _contacts[index];
}

int	PhoneBook::getIsIndex() const
{
	return _isIndex;
}

void	PhoneBook::setContact(Contact contact)
{
	_index = _index % 8;
	_contacts[_index] = contact;
	_index++;
	if (_isIndex == false)
		_isIndex = true;
}

void	PhoneBook::displayPhoneBook() const
{
	std::cout << "|" << std::setw(44) << std::right << std::setfill('-') << "|";
	std::cout << std::setfill(' ') << std::endl;
	std::cout << "|" << std::setw(10) << "index";
	std::cout << "|" << std::setw(10) << "first name";
	std::cout << "|" << std::setw(10) << "last name";
	std::cout << "|" << std::setw(10) << "nickname";
	std::cout << "|" << std::endl;
	std::cout << "|" << std::setw(44) << std::setfill('-') << "|";
	std::cout << std::setfill(' ') << std::endl;
	for (unsigned int i = 0; !this->_contacts[i].getFirstName().empty(); i++)
	{
		std::cout << "|" << std::setw(10) << i;
		if (this->_contacts[i].getFirstName().size() > 10)
			std::cout << "|" << std::setw(9) << this->_contacts[i].getFirstName().substr(0, 9) << ".";
		else
			std::cout << "|" << std::setw(10) << this->_contacts[i].getFirstName();
		if (this->_contacts[i].getLastName().size() > 10)
			std::cout << "|" << std::setw(9) << this->_contacts[i].getLastName().substr(0, 9) << ".";
		else
			std::cout << "|" << std::setw(10) << this->_contacts[i].getLastName();
		if (this->_contacts[i].getNickname().size() > 10)
			std::cout << "|" << std::setw(9) << this->_contacts[i].getNickname().substr(0, 9) << ".";
		else
			std::cout << "|" << std::setw(10) << this->_contacts[i].getNickname();
		std::cout << "|" << std::endl;
	}
	std::cout << "|" << std::setw(44) << std::setfill('-') << "|";
	std::cout << std::endl << std::endl;
}
