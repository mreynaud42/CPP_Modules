/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 18:39:11 by mreynaud          #+#    #+#             */
/*   Updated: 2025/03/10 16:37:40 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	{
		try
		{
			Bureaucrat albert("Albert", 150);
			Bureaucrat bernard("Bernard", 1);
			Bureaucrat christian("Christian", 75);

			ShrubberyCreationForm form1("Bob");
			RobotomyRequestForm form2("Bob");
			PresidentialPardonForm form3("Bob");

			bernard.signForm(form1);
			bernard.signForm(form2);
			bernard.signForm(form3);

			form1.execute(bernard);
			form2.execute(bernard);
			form3.execute(bernard);
			bernard.executeForm(form1);
		}
		catch (std::exception & e)
		{
			std::cout << "Erreur: " << e.what() << std::endl;
		}
		std::cerr << std::endl;
		try
		{

			Bureaucrat bernard("Bernard", 1);

			ShrubberyCreationForm form1("Bob");

			form1.execute(bernard);
		}
		catch (std::exception & e)
		{
			std::cout << "Erreur: " << e.what() << std::endl;
		}
		std::cerr << std::endl;
		try
		{

			Bureaucrat christian("Christian", 50);

			RobotomyRequestForm form1("Bob");

			christian.signForm(form1);

			form1.execute(christian);
		}
		catch (std::exception & e)
		{
			std::cerr << "Erreur: " << e.what() << std::endl;
		}
	}
	return 0;
}
