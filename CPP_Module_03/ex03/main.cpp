/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:25:31 by mreynaud          #+#    #+#             */
/*   Updated: 2025/02/10 19:03:28 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap person("Albert");

	std::cout << std::endl;
	person.attack("Bernard");
	person.beRepaired(10);
	person.takeDamage(10);

	std::cout << std::endl;
	person.guardGate();
	person.highFivesGuys();
	person.whoAmI();

	std::cout << std::endl;
	return 0;
}
