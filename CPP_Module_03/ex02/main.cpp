/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:25:31 by mreynaud          #+#    #+#             */
/*   Updated: 2025/02/10 18:13:24 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ClapTrap person1("Albert");
	ScavTrap person2("Bruno");
	FragTrap person3("Christian");

	std::cout << std::endl;
	person1.attack("Bernard");
	person2.attack("Bernard");
	person3.attack("Bernard");

	std::cout << std::endl;
	person1.beRepaired(10);
	person2.beRepaired(10);
	person3.beRepaired(10);

	std::cout << std::endl;
	person1.takeDamage(10);
	person2.takeDamage(10);
	person3.takeDamage(10);

	std::cout << std::endl;
	person2.guardGate();
	person3.highFivesGuys();

	std::cout << std::endl;
	return 0;
}
