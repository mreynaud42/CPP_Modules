/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:25:31 by mreynaud          #+#    #+#             */
/*   Updated: 2025/02/10 17:55:38 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap person1("Albert");
	ScavTrap person2("Bruno");

	std::cout << std::endl;
	person1.attack("Bernard");
	person2.attack("Bernard");

	std::cout << std::endl;
	person1.beRepaired(10);
	person2.beRepaired(10);

	std::cout << std::endl;
	person1.takeDamage(10);
	person2.takeDamage(10);

	std::cout << std::endl;
	person2.guardGate();

	std::cout << std::endl;
	return 0;
}
