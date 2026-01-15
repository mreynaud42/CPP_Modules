/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:25:31 by mreynaud          #+#    #+#             */
/*   Updated: 2025/02/10 17:49:22 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap person1("Albert");

	person1.attack("Bernard");
	person1.beRepaired(10);
	person1.takeDamage(10);

	for (size_t i = 0; i < 10; i++)
		person1.beRepaired(1);

	person1.attack("Bernard");

	return 0;
}
