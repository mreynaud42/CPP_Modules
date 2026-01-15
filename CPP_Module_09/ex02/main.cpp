/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 04:10:03 by mreynaud          #+#    #+#             */
/*   Updated: 2025/09/03 11:53:32 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <limits.h>
#include <ctime>
#include <stdexcept>
#include "PmergeMe.hpp"

std::vector<int>	getVec(int argc, char const *argv[])
{
	std::vector<int> v;
	char* endptr;
	long val = 0;

	for (int i = 1; i < argc; ++i)
	{
		val = std::strtol( argv[i], &endptr, 10 );
		if (*endptr != '\0')
		{
			throw std::invalid_argument( std::string( "'" ) + argv[i] + "' isn't an int" );
		}
		else if (val > INT_MAX)
		{
			throw std::invalid_argument( std::string( "greater than max int" ) );
		}
		else if (val < 0)
		{
			throw std::invalid_argument( std::string( "negative integer find" ) );
		}
		else
		{
			v.push_back(static_cast<int>(val));
    	}
	}
	return v;
}

void printVec(std::vector<int> vec)
{
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
}

void printDeque(std::deque<int> vec)
{
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
	try
	{

		std::vector<int> vec = getVec(argc, argv);

		std::cout << "Before:\t";

		printVec(vec);

		//-------------------------------------------------//
		std::time_t timeStartVec = std::clock();

		// merge vector
		vec = mergeInsertionSort(vec);

		std::time_t timeEndVec = std::clock();

		//-------------------------------------------------//
		std::deque<int> deque(vec.begin(), vec.end());

		std::time_t timeStartDeque = std::clock();

		// merge deque
		deque = mergeInsertionSort(deque);

		std::time_t timeEndDeque = std::clock();

		//-------------------------------------------------//

		std::cout << "After:\t";
		printVec(vec);

		// std::cout << "After vec:\t";
		// printVec(vec);

		// std::cout << "After deq:\t";
		// printDeque(deque);

		//-------------------------------------------------//

		std::cout << "Time to process a range of " << vec.size() << " elements with std::vector\t:\t" << 1000.0 * (timeEndVec - timeStartVec) / CLOCKS_PER_SEC << " ms" << std::endl;

		std::cout << "Time to process a range of " << deque.size() << " elements with std::deque\t:\t" << 1000.0 * (timeEndDeque - timeStartDeque) / CLOCKS_PER_SEC << " ms" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}
