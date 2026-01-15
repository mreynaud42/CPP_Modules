/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:58:39 by mreynaud          #+#    #+#             */
/*   Updated: 2025/02/18 21:43:55 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : AbstractAnimal("Cat")
{
	std::cout << "Cat default constructor called" << std::endl;
	_brain = new Brain;
}

Cat::Cat(const Cat &other)
{
	std::cout << "Cat copy constructor called" << std::endl;
	_type = other._type;
	_brain = new Brain(*other._brain);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete _brain;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	_type = other._type;
	delete _brain;
	_brain = new Brain(*other._brain);
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Cat sound" << std::endl;
}

void Cat::setBrainIdea(std::string idea)
{
	_brain->setIdea(idea);
}

void Cat::printBrain() const
{
	_brain->printIdeas();
}
