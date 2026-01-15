/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:04:31 by mreynaud          #+#    #+#             */
/*   Updated: 2025/03/10 16:39:11 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("no_target") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	_target = other._target;
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getGradeExecute())
		throw Bureaucrat::GradeTooLowException();
	else if (this->getSigned() == false)
		throw AForm::FormNotSigned();

	std::fstream shrubbery;
	shrubbery.open((_target + "_shrubbery").c_str(), std::fstream::out);
	if (!shrubbery.is_open())
		throw ShrubberyCreationForm::FileCannotOpened();

	shrubbery << "\
      /\\\n\
     /\\*\\\n\
    /\\O\\*\\\n\
   /*/\\/\\/\\\n\
  /\\O\\/\\*\\/\\\n\
 /\\*\\/\\*\\/\\/\\\n\
/\\O\\/\\/*/\\/O/\\\n\
      ||\n\
      ||\n\
      ||";

	shrubbery.close();
}

const char* ShrubberyCreationForm::FileCannotOpened::what() const throw()
{
	return "File cannot be opened";
}
