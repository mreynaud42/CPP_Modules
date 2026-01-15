/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 20:20:21 by mreynaud          #+#    #+#             */
/*   Updated: 2025/02/16 22:44:46 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie *ptrZombie;
	int nb = 3;

	ptrZombie = zombieHorde(nb, "Thiery");
	for (int i = 0; i < nb; i++)
		ptrZombie[i].announce();

	delete [] ptrZombie;
	return (0);
}
