/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 20:20:21 by mreynaud          #+#    #+#             */
/*   Updated: 2025/02/15 14:48:57 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HarlFilter.hpp"

int main(int argc, char const *argv[])
{
	HarlFilter harl;

	if (argc < 2)
	{
		std::cerr << "./HarlFilter <level>..." << std::endl;
		return 1;
	}
	for (int i = 1; i < argc; ++i)
	{
		harl.complain(argv[i]);
		std::cout << std::endl;
	}
	return 0;
}

