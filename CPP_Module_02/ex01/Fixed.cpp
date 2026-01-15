/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:18:58 by mreynaud          #+#    #+#             */
/*   Updated: 2025/02/18 14:35:10 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointNumberValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : _fixedPointNumberValue(value << _numberOfFractionalBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : _fixedPointNumberValue(roundf(value * (1 << _numberOfFractionalBits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	_fixedPointNumberValue = other.getRawBits();
	return *this;
}

void Fixed::setRawBits(int const raw)
{
	_fixedPointNumberValue = raw;
}

int Fixed::getRawBits(void) const
{
	return _fixedPointNumberValue;
}

float Fixed::toFloat(void) const
{
	return (float)_fixedPointNumberValue / (1 << _numberOfFractionalBits);
}

int Fixed::toInt(void) const
{
	return _fixedPointNumberValue >> _numberOfFractionalBits;
}

std::ostream& operator<<(std::ostream &os, const Fixed &p)
{
	os << p.toFloat();
	return os;
}
