/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 20:20:21 by mreynaud          #+#    #+#             */
/*   Updated: 2025/01/26 22:37:55 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie *zombie1;
	Zombie zombie;

	zombie1 = newZombie("TYWEN");
	zombie1->announce();
	zombie.announce();

	randomChump("TYANNA");
	delete (zombie1);
	return (0);
}
