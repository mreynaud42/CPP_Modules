/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:48:47 by mreynaud          #+#    #+#             */
/*   Updated: 2025/03/10 15:06:24 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Form.hpp"

Form::Form() : _name("Default_Form"), _signed(false), _gradeSign(150), _gradeExecute(150) {}

Form::Form(const std::string name, const int gradeSign, const int gradeExecute) : _name(name), _signed(false), _gradeSign(gradeSign), _gradeExecute(gradeExecute)
{
	if (gradeSign < 1 || gradeExecute < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (gradeSign > 150|| gradeExecute > 150)
		throw Bureaucrat::GradeTooLowException();
}

Form::Form(const Form &other) : _name(other._name), _signed(other._signed), _gradeSign(other._gradeSign), _gradeExecute(other._gradeExecute) {}

Form::~Form() {}

Form &Form::operator=(const Form &other)
{
	_signed = other._signed;
	return *this;
}

std::string Form::getName() const
{
	return _name;
}

bool Form::getSigned() const
{
	return _signed;
}

int Form::getGradeSign() const
{
	return _gradeSign;
}

int Form::getGradeExecute() const
{
	return _gradeExecute;
}

void Form::beSigned(const Bureaucrat bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeSign)
		throw Bureaucrat::GradeTooLowException();
	else if (_signed == true)
		throw Form::AlreadySigned();
	else
		_signed = true;
}

const char* Form::AlreadySigned::what() const throw()
{
	return "Already Signed";
}

std::ostream& operator<<(std::ostream &os, const Form &p)
{
	os << p.getName() << " form, the grade required to sign it " << p.getGradeSign() << ", signed " << p.getSigned();
	return os;
}
