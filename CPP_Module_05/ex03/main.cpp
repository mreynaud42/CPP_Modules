/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 18:39:11 by mreynaud          #+#    #+#             */
/*   Updated: 2025/03/10 16:40:21 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	{
		try
		{
			Bureaucrat bernard("Bernard", 1);

			Intern denis;

			AForm* form;

			form = denis.makeForm("Presidential Pardon", "Bob");
			bernard.signForm(*form);
			form->execute(bernard);
			delete form;

			std::cout << std::endl;

			form = denis.makeForm("Robotomy Request", "Bob");
			bernard.signForm(*form);
			form->execute(bernard);
			delete form;

			std::cout << std::endl;

			form = denis.makeForm("Shrubbery Creation", "Bob");
			bernard.signForm(*form);
			form->execute(bernard);
			delete form;

			std::cout << std::endl;

			form = denis.makeForm("not form", "Bob");
			bernard.signForm(*form);
			form->execute(bernard);
			delete form;
		}
		catch (std::exception & e)
		{
			std::cerr << "Erreur: " << e.what() << std::endl;
		}
	}
	return 0;
}
