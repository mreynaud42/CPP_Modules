/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 23:45:51 by mreynaud          #+#    #+#             */
/*   Updated: 2025/02/16 22:52:19 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) :  _weapon(weapon), _name(name) {}

HumanA::~HumanA() {}

void HumanA::setWeapon(Weapon &weapon)
{
	_weapon = weapon;
}

void HumanA::attack() const
{
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
