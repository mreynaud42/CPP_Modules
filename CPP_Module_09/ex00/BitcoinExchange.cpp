/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:05:00 by mreynaud          #+#    #+#             */
/*   Updated: 2025/07/22 06:09:59 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "BitcoinExchange.hpp"
#include "Date.hpp"

static float	convertToFloat(std::string sValue)
{
	float	value = 0;
	int		sign = 1;
	std::string::iterator	it = sValue.begin();

	if (it == sValue.end())
		throw NotANumber();
	if (*it == '-' || *it == '+')
	{
		if (*it == '-')
			sign = -1;
		it++;
	}
	while (it != sValue.end() && isdigit(*it))
	{
		value = value * 10 + *it - '0';
		it++;
	}
	if (it == sValue.end())
		return value * sign;
	if (*it != '.')
		throw NotANumber();
	std::string::iterator save_it = it;

	float	fraction = 0;
	it = sValue.end() - 1;
	while (isdigit(*it))
	{
		fraction = fraction / 10 + *it - '0';
		it--;
	}
	if (it != save_it)
		throw NotANumber();
	return (value + (fraction / 10)) * sign;
}

// BitcoinExchange

void BitcoinExchange::exchange(const Date date, float exchangeRate)
{
	std::map<Date, float>::reverse_iterator rit = _data.rbegin();
	while (rit != _data.rend() && rit->first > date)
		++rit;
	if (rit == _data.rend())
		throw NoData();
	std::cout << date << " => " << exchangeRate << " = " << exchangeRate * rit->second << std::endl;
}

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(std::string file)
{
	std::fstream csvFile;
	csvFile.open("./data.csv", std::fstream::in);
	if (!csvFile.is_open())
		throw NotOpenFile();

	std::fstream arg_file;
	arg_file.open(file.c_str(), std::fstream::in);
	if (!arg_file.is_open())
		throw NotOpenFile();

	std::string sDate;
	std::string sExchangeRate;
	getline(csvFile, sDate, '\n');
	while (getline(csvFile, sDate, ',') && getline(csvFile, sExchangeRate, '\n'))
		_data[Date(sDate)] = convertToFloat(sExchangeRate);

	std::string line;
	getline(arg_file, line, '\n');
	while (getline(arg_file, line, '\n'))
	{
		try
		{
			if (line.length() < 14)
				throw BadInput();
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: " << e.what() << " => "<< line << std::endl;
			continue;
		}
		try
		{
			Date date(line.substr(0, 10));
			float exchangeRate = convertToFloat(line.substr(13, line.length()));
			if (exchangeRate < 0)
				throw NotPostiveNumber();
			else if (exchangeRate >= 1000)
				throw LargeNumber();
			this->exchange(date, exchangeRate);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: " << e.what() << "." << std::endl;
		}
	}

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &) {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &)
{
	return *this;
}

// exception

const char* NotOpenFile::what() const throw()
{
	return "could not open file";
}

const char* BadInput::what() const throw()
{
	return "bad input";
}

const char* NotPostiveNumber::what() const throw()
{
	return "not a positive number";
}

const char* LargeNumber::what() const throw()
{
	return "too large a number";
}

const char* NoData::what() const throw()
{
	return "no data";
}
