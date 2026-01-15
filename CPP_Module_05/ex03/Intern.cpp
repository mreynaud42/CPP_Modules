/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 21:32:35 by mreynaud          #+#    #+#             */
/*   Updated: 2025/03/10 16:40:52 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other)
{
	*this = other;
}

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return *this;
}

AForm *Intern::makeForm(std::string form, std::string target)
{
	std::string forms[3] = {"Presidential Pardon", "Robotomy Request", "Shrubbery Creation"};

	int i = 0;
	while (i < 3 && forms[i] != form)
		++i;
	switch (i)
	{
		case 0:
			std::cout << "Intern creates " << form << std::endl;
			return new PresidentialPardonForm(target);

		case 1:
			std::cout << "Intern creates " << form << std::endl;
			return new RobotomyRequestForm(target);

		case 2:
			std::cout << "Intern creates " << form << std::endl;
			return new ShrubberyCreationForm(target);

		default:
			throw Intern::FormDoesNotExist();
	}
	return 0;
}

const char* Intern::FormDoesNotExist::what() const throw()
{
	return "This Form does not exist";
}
