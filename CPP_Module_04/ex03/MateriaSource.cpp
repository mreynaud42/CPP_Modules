/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:08:53 by mreynaud          #+#    #+#             */
/*   Updated: 2025/02/18 21:46:29 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (size_t i = 0; i < 4; ++i)
		_inventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	for (size_t i = 0; i < 4; ++i)
	{
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
}

MateriaSource::~MateriaSource()
{
	for (size_t i = 0; i < 4; ++i)
	{
		if (_inventory[i])
		{
			delete _inventory[i];
			_inventory[i] = NULL;
		}
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	for (size_t i = 0; i < 4; ++i)
	{
		if (_inventory[i])
			delete _inventory[i];
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
	for (size_t i = 0; i < 4; ++i)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			break;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
	for (size_t i = 0; i < 4; ++i)
	{
		if (_inventory[i] && _inventory[i]->getType() == type)
			return _inventory[i]->clone();
	}
	return 0;
}
