/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:55:19 by mreynaud          #+#    #+#             */
/*   Updated: 2025/05/13 16:12:11 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>

static std::string	char_convertible(std::string value)
{
	char	char_convert;
	std::string	convert;

	if (value.length() == 1 && !isdigit(value[0]))
	{
		char_convert = value[0];
		while (char_convert != 0)
		{
			convert.insert(convert.begin(), (char_convert % 10) + '0');
			char_convert /= 10;
		}
		return convert;
	}
	else
		return value;
}

static double	convert_to_double(std::string value)
{
	double	value_double = 0;
	int		sign = 1;
	std::string::iterator	it = value.begin();

	if (it == value.end())
		throw NotANumber();
	if (*it == '-' || *it == '+')
	{
		if (*it == '-')
			sign = -1;
		it++;
	}
	while (it != value.end() && isdigit(*it))
	{
		value_double = value_double * 10 + *it - '0';
		it++;
	}
	if (it == value.end())
		return value_double * sign;
	if (*it != '.')
		throw NotANumber();
	std::string::iterator save_it = it;

	double fraction = 0;
	it = value.end() - 1;
	while (isdigit(*it))
	{
		fraction = fraction / 10 + *it - '0';
		it--;
	}
	if (it != save_it)
		throw NotANumber();
	return (value_double + (fraction / 10)) * sign;
}

static int	get_precision(double nb)
{
	size_t i = 0;

	nb = (nb - static_cast<int>(nb)) * 10;
	while (static_cast<int>(nb) != 0 && i < 50)
	{
		nb = (nb - static_cast<int>(nb)) * 10;
		i++;
	}
	if (i == 0)
		i = 1;
	return i;
}

static void display_char(double c)
{
	if (c < 0 || c > 255)
		std::cout << "char: impossible" << std::endl;
	else if (isprint(static_cast<int>(c)))
		std::cout << "char: '" << static_cast<char>(c) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

static void display_int(double nb)
{
	std::cout << "int: " << static_cast<int>(nb) << std::endl;
}

static void display_float(double nb)
{
	std::cout << std::fixed << std::setprecision(get_precision(static_cast<float>(nb))) << "float: " << static_cast<float>(nb) << "f" << std::endl;
}

static void display_double(double nb)
{
	std::cout << std::fixed << std::setprecision(get_precision(nb)) << "double: " << nb << std::endl;
}

void ScalarConverter::convert(std::string value)
{
	std::string	convert = char_convertible(value);
	if (convert[convert.length() - 1] == 'f')
		convert.erase(convert.end() - 1, convert.end());
	try
	{
		double	value_double = convert_to_double(convert);

		display_char(value_double);
		display_int(value_double);
		display_float(value_double);
		display_double(value_double);
	}
	catch(const std::exception &e)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
}

const char* NotANumber::what() const throw()
{
	return "nan";
}
