/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 22:51:24 by mreynaud          #+#    #+#             */
/*   Updated: 2025/02/17 15:50:41 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Point.hpp"

Point::Point(){}

Point::Point(const Point &other)
{
	*this = other;
}

Point::Point(float x, float y) : _x(x), _y(y) {}

Point::Point(Fixed x, Fixed y) : _x(x), _y(y) {}

Point::~Point(){}

Point &Point::operator=(const Point &other)
{
	this->_x = other.getX();
	this->_y = other.getY();
	return *this;
}

Fixed Point::getX(void) const
{
	return _x;
}

Fixed Point::getY(void) const
{
	return _y;
}
