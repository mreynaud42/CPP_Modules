/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 08:16:02 by mreynaud          #+#    #+#             */
/*   Updated: 2025/09/12 19:46:08 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"

int main()
{
	{
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	std::cout << std::endl;
	{
		Span sp = Span(1);

		sp.addNumber(42);
		try
		{
			sp.addNumber(1);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			std::cout << sp.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			std::cout << sp.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		Span sp = Span(5);

		sp.addNumber(1);
		sp.addNumber(-3);
		sp.addNumber(-17);
		sp.addNumber(-9);
		sp.addNumber(-1001);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	std::cout << std::endl;
	{
		Span largeSpan(100000);
		for (unsigned int i = 0; i < 100000; ++i) {
			largeSpan.addNumber(i);
		}
		std::cout << largeSpan.shortestSpan() << std::endl;
		std::cout << largeSpan.longestSpan() << std::endl;
	}
	std::cout << std::endl;
	{
		std::vector<int> a;
		Span b(10);

		a.push_back(6);
		a.push_back(3);
		a.push_back(17);
		a.push_back(9);
		a.push_back(11);

		// b.addNumber(42);
		b.addRange(a.begin(), a.end());

		std::cout << b.longestSpan() << std::endl;
		try
		{
			b.addRange(a.begin(), a.end());
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}
