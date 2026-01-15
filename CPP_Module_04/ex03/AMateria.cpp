/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:16:34 by mreynaud          #+#    #+#             */
/*   Updated: 2025/02/18 21:46:50 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(std::string const &type) : _type(type) {}

AMateria::AMateria(const AMateria &other) : _type(other._type) {}

AMateria::~AMateria() {}

AMateria &AMateria::operator=(const AMateria &other)
{
	_type = other.getType();
	return *this;
}

std::string const &AMateria::getType() const
{
	return _type;
}

void AMateria::use(ICharacter &target)
{
	std::cout << "Materia default use" << target.getName() << std::endl;
}
