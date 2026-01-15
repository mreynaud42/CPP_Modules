/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 04:10:03 by mreynaud          #+#    #+#             */
/*   Updated: 2025/07/19 22:36:36 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error: could not open file" << std::endl;
		return 1;
	}
	try
	{
		std::string file = argv[1];

		BitcoinExchange test(file);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << "." << std::endl;
		return 1;
	}
	return 0;
}
