/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:18:58 by mreynaud          #+#    #+#             */
/*   Updated: 2025/02/18 14:35:36 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointNumberValue(0){}

Fixed::Fixed(const int value) : _fixedPointNumberValue(value << _numberOfFractionalBits){}

Fixed::Fixed(const float value) : _fixedPointNumberValue(roundf(value * (1 << _numberOfFractionalBits))){}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed::~Fixed(){}

Fixed &Fixed::operator=(const Fixed &other)
{
	_fixedPointNumberValue = other.getRawBits();
	return *this;
}

bool Fixed::operator>(const Fixed &other)
{
	return _fixedPointNumberValue > other.getRawBits();
}

bool Fixed::operator<(const Fixed &other)
{
	return _fixedPointNumberValue < other.getRawBits();
}

bool Fixed::operator>=(const Fixed &other)
{
	return _fixedPointNumberValue >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed &other)
{
	return _fixedPointNumberValue <= other.getRawBits();
}

bool Fixed::operator==(const Fixed &other)
{
	return _fixedPointNumberValue == other.getRawBits();
}

bool Fixed::operator!=(const Fixed &other)
{
	return _fixedPointNumberValue != other.getRawBits();
}

Fixed Fixed::operator+(const Fixed &other)
{
	return ((float)(_fixedPointNumberValue + other.getRawBits()) / (1 << _numberOfFractionalBits));
}

Fixed Fixed::operator-(const Fixed &other)
{
	return ((float)(_fixedPointNumberValue - other.getRawBits()) / (1 << _numberOfFractionalBits));
}

Fixed Fixed::operator*(const Fixed &other)
{
	return ((float)(_fixedPointNumberValue * other.getRawBits()) / (1 << _numberOfFractionalBits * 2));
}

Fixed Fixed::operator/(const Fixed &other)
{
	return this->toFloat() / other.toFloat();
}

Fixed &Fixed::operator++()
{
	++_fixedPointNumberValue;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;

	this->_fixedPointNumberValue++;
	return temp;
}

Fixed &Fixed::operator--()
{
	--_fixedPointNumberValue;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;

	_fixedPointNumberValue--;
	return temp;
}

Fixed &Fixed::min(Fixed &first, Fixed &seconde)
{
	return first <= seconde ? first : seconde;
}

const Fixed &Fixed::min(const Fixed &first, const Fixed &seconde)
{
	return (first.getRawBits() <= seconde.getRawBits() ? first : seconde);
}

Fixed &Fixed::max(Fixed &first, Fixed &seconde)
{
	return (first >= seconde ? first : seconde);
}

const Fixed &Fixed::max(const Fixed &first, const Fixed &seconde)
{
	return (first.getRawBits() >= seconde.getRawBits() ? first : seconde);
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

std::ostream &operator<<(std::ostream &os, const Fixed &p)
{
	os << (p.toFloat());
	return os;
}
