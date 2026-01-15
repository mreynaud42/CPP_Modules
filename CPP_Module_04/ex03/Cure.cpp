/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:59:44 by mreynaud          #+#    #+#             */
/*   Updated: 2025/02/18 21:45:35 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
#include "ICharacter.hpp"
#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(std::string const &type) : AMateria(type) {}

Cure::Cure(const Cure &other): AMateria(other.getType()) {}

Cure::~Cure() {}

Cure &Cure::operator=(const Cure &other)
{
	_type = other.getType();
	return *this;
}

Cure *Cure::clone() const
{
	return new Cure();
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
