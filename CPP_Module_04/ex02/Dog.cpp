/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:58:39 by mreynaud          #+#    #+#             */
/*   Updated: 2025/02/18 21:44:11 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : AbstractAnimal("Dog")
{
	std::cout << "Dog default constructor called" << std::endl;
	_brain = new Brain;
}

Dog::Dog(const Dog &other)
{
	std::cout << "Dog copy constructor called" << std::endl;
	_type = other._type;
	_brain = new Brain(*other._brain);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete _brain;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	_type = other._type;
	delete _brain;
	_brain = new Brain(*other._brain);
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Dog sound" << std::endl;
}

void Dog::setBrainIdea(std::string idea)
{
	_brain->setIdea(idea);
}

void Dog::printBrain() const
{
	_brain->printIdeas();
}
