/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 18:39:11 by mreynaud          #+#    #+#             */
/*   Updated: 2025/03/05 15:52:53 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	{
		Bureaucrat *a = NULL;

		try
		{
			Bureaucrat albert("Albert", 149);
			std::cout << albert << std::endl;
			albert.decrementGrade();
			std::cout << albert << std::endl;
			a = new Bureaucrat(albert);
		}
		catch (std::exception & e)
		{
			std::cerr << "Erreur: " << e.what() << std::endl;
		}
		if (a)
		{
			std::cout << *a << std::endl;
			delete a;
		}
	}
	std::cout << std::endl << std::endl;
	{
		try
		{
			Bureaucrat albert("Albert", 150);
			std::cout << albert << std::endl;
			albert.decrementGrade();
			std::cout << albert << std::endl;
		}
		catch (std::exception & e)
		{
			std::cerr << "Erreur: " << e.what() << std::endl;
		}
	}
	std::cout << std::endl << std::endl;
	{
		try
		{
			Bureaucrat albert("Albert", 1);
			std::cout << albert << std::endl;
			albert.incrementGrade();
			std::cout << albert << std::endl;
		}
		catch (std::exception & e)
		{
			std::cerr << "Erreur: " << e.what() << std::endl;
		}
	}
	std::cout << std::endl << std::endl;
	{
		try
		{
			Bureaucrat albert("Albert", 151);
			std::cout << albert << std::endl;
		}
		catch (std::exception & e)
		{
			std::cerr << "Erreur: " << e.what() << std::endl;
		}
	}
	std::cout << std::endl << std::endl;
	{
		try
		{
			Bureaucrat albert("Albert", -1);
			std::cout << albert << std::endl;
		}
		catch (std::exception & e)
		{
			std::cerr << "Erreur: " << e.what() << std::endl;
		}
	}
	return 0;
}
