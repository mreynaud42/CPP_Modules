/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:58:39 by mreynaud          #+#    #+#             */
/*   Updated: 2025/02/18 21:43:30 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = other;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
	std::cout << "Brain copy assignment operator called" << std::endl;

	for (size_t i = 0; i < 100; i++)
		_ideas[i] = other._ideas[i];

	return *this;
}

void Brain::setIdea(std::string idea)
{
	if (!_ideas[99].empty())
		std::cout << "I have no more room for a new idea" << std::endl;
	for (size_t i = 0; i < 100; i++)
	{
		if (_ideas[i].empty())
		{
			_ideas[i] = idea;
			break ;
		}
	}
}

void Brain::printIdeas() const
{
	for (size_t i = 0; !_ideas[i].empty(); i++)
		std::cout << _ideas[i] << std::endl;
}
