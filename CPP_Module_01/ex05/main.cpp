/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 20:20:21 by mreynaud          #+#    #+#             */
/*   Updated: 2025/02/15 14:49:03 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int main(int argc, char const *argv[])
{
	Harl harl;

	if (argc < 2)
	{
		std::cerr << "./Harl <level>..." << std::endl;
		return 1;
	}
	for (int i = 1; i < argc; ++i)
	{
		harl.complain(argv[i]);
		std::cout << std::endl;
	}
	return 0;
}
