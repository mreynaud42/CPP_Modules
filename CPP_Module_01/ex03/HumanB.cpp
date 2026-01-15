/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 23:46:34 by mreynaud          #+#    #+#             */
/*   Updated: 2025/02/16 22:52:23 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _weapon(NULL), _name(name){}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}

void HumanB::attack() const
{
	if (!_weapon)
		std::cout << _name << " attacks with their no weapon" << std::endl;
	else
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}
