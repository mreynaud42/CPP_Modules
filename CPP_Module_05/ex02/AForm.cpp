/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:48:47 by mreynaud          #+#    #+#             */
/*   Updated: 2025/03/10 15:14:27 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AForm.hpp"

AForm::AForm() : _name("Default_Form"), _signed(false), _gradeSign(150), _gradeExecute(150) {}

AForm::AForm(const std::string name, const int gradeSign, const int gradeExecute) : _name(name), _signed(false), _gradeSign(gradeSign), _gradeExecute(gradeExecute)
{
	if (gradeSign < 1 || gradeExecute < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (gradeSign > 150|| gradeExecute > 150)
		throw Bureaucrat::GradeTooLowException();
}

AForm::AForm(const AForm &other) : _name(other._name), _signed(other._signed), _gradeSign(other._gradeSign), _gradeExecute(other._gradeExecute) {}

AForm::~AForm() {}

AForm &AForm::operator=(const AForm &other)
{
	_signed = other._signed;
	return *this;
}

std::string AForm::getName() const
{
	return _name;
}

bool AForm::getSigned() const
{
	return _signed;
}

int AForm::getGradeSign() const
{
	return _gradeSign;
}

int AForm::getGradeExecute() const
{
	return _gradeExecute;
}

void AForm::beSigned(const Bureaucrat bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeSign)
		throw Bureaucrat::GradeTooLowException();
	else if (_signed == true)
		throw AForm::AlreadySigned();
	else
		_signed = true;
}

const char* AForm::AlreadySigned::what() const throw()
{
	return "Already Signed";
}

const char* AForm::FormNotSigned::what() const throw()
{
	return "The Form is not signed";
}

std::ostream& operator<<(std::ostream &os, const AForm &p)
{
	os << p.getName() << " form, the grade required to sign it " << p.getGradeSign() << ", signed " << p.getSigned();
	return os;
}
