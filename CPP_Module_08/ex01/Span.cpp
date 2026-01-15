/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 08:16:59 by mreynaud          #+#    #+#             */
/*   Updated: 2025/09/12 19:46:20 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <stdexcept>
#include "Span.hpp"

Span::Span() : _size_max(0) {}

Span::Span(unsigned int size) : _size_max(size) {}

Span::Span(const Span &other)
{
	*this = other;
}

Span::~Span() {}

Span &Span::operator=(const Span &other)
{
	_vec = other._vec;
	_size_max = other._size_max;
	return *this;
}

void Span::addNumber(int number)
{
	if (_vec.size() >= _size_max)
		throw std::out_of_range("Maximum number of elements reached");
	_vec.push_back(number);
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (_vec.size() + (end - 1 - begin) >= _size_max)
		throw std::out_of_range("Maximum number of elements reached");
	_vec.insert(_vec.end(), begin, end);
}

int Span::shortestSpan()
{
	if (_vec.size() < 2)
		throw std::logic_error("At least two numbers are required");
	std::sort(_vec.begin(), _vec.end());

	int shortest = *(_vec.begin() + 1) - *_vec.begin();
	for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end() - 1; it++)
	{
		if (shortest > *(it + 1) - *it)
			shortest = abs(*(it + 1) - *it);
	}
	return shortest;
}

int Span::longestSpan()
{
	if (_vec.size() < 2)
		throw std::logic_error("At least two numbers are required");
	std::sort(_vec.begin(), _vec.end());

	int longest = abs(*(_vec.end() - 1) - *_vec.begin());
	return longest;
}
