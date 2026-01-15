/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractAnimal.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:58:39 by mreynaud          #+#    #+#             */
/*   Updated: 2025/02/18 21:43:15 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AbstractAnimal.hpp"

AbstractAnimal::AbstractAnimal() : _type("Default_Animal")
{
	std::cout << "AbstractAnimal default constructor called" << std::endl;
}

AbstractAnimal::AbstractAnimal(std::string type) : _type(type)
{
	std::cout << "AbstractAnimal constructor called" << std::endl;
}

AbstractAnimal::AbstractAnimal(const AbstractAnimal &other)
{
	std::cout << "AbstractAnimal copy constructor called" << std::endl;
	*this = other;
}

AbstractAnimal::~AbstractAnimal()
{
	std::cout << "AbstractAnimal destructor called" << std::endl;
}

AbstractAnimal &AbstractAnimal::operator=(const AbstractAnimal &other)
{
	std::cout << "AbstractAnimal copy assignment operator called" << std::endl;
	_type = other._type;
	return *this;
}

std::string AbstractAnimal::getType() const
{
	return _type;
}
