/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 22:27:55 by mreynaud          #+#    #+#             */
/*   Updated: 2025/07/22 06:08:56 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <sstream>
#include "Date.hpp"

static unsigned int	convertToUInt(std::string sValue)
{
	unsigned int	value = 0;
	std::string::iterator	it = sValue.begin();

	if (it == sValue.end())
		throw NotANumber();
	while (it != sValue.end() && isdigit(*it))
	{
		value = value * 10 + *it - '0';
		it++;
	}
	if (it != sValue.end())
		throw NotANumber();
	return value;
}

// Date

Date::Date() : _year(0), _month(0), _day(0) {}

Date::Date(std::string date)
{
	std::string	v;
	std::stringstream	ssDate(date);

	getline(ssDate, v, '-');
	if (v.size() != 4)
		throw Date::InvalidDate();
	_year = convertToUInt(v);
	getline(ssDate, v, '-');
	if (v.size() != 2)
		throw Date::InvalidDate();
	_month = convertToUInt(v);
	getline(ssDate, v, '-');
	if (v.size() != 2)
		throw Date::InvalidDate();
	_day = convertToUInt(v);
	if (!isValidDate(_year, _month, _day))
		throw Date::InvalidDate();
}

Date::Date(const Date &other) : _year(other.getYear()), _month(other.getMonth()), _day(other.getDay()) {}

Date::~Date() {}

Date &Date::operator=(const Date &)
{
	return *this;
}

bool Date::operator>(const Date &other) const
{
	if (_year != other.getYear())
		return _year > other.getYear();
	if (_month != other.getMonth())
		return _month > other.getMonth();
	return _day > other.getDay();
}

bool Date::operator<(const Date &other) const
{
	if (_year != other.getYear())
		return _year < other.getYear();
	if (_month != other.getMonth())
		return _month < other.getMonth();
	return _day < other.getDay();
}

bool Date::operator>=(const Date &other) const
{
	if (_year != other.getYear())
		return _year >= other.getYear();
	if (_month != other.getMonth())
		return _month >= other.getMonth();
	return _day >= other.getDay();
}

bool Date::operator<=(const Date &other) const
{
	if (_year != other.getYear())
		return _year <= other.getYear();
	if (_month != other.getMonth())
		return _month <= other.getMonth();
	return _day <= other.getDay();
}

bool Date::operator==(const Date &other) const
{
	if (_year == other.getYear() && _month == other.getMonth() && _day == other.getDay())
		return true;
	return false;
}

bool Date::operator!=(const Date &other) const
{
	if (_year == other.getYear() && _month == other.getMonth() && _day == other.getDay())
		return false;
	return true;
}

unsigned int Date::getYear(void) const
{
	return _year;
}

unsigned int Date::getMonth(void) const
{
	return _month;
}

unsigned int Date::getDay(void) const
{
	return _day;
}

bool Date::isValidDate(const int year, const int month, const int day) const
{
    int days_in_month[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

    if( year % 4 == 0 )
        days_in_month[2] = 29;
    if ( month < 1 or month > 12 )
        return false;
    if ( day < 1 or day > days_in_month[month] )
        return false;
    return true;
}

std::ostream& operator<<(std::ostream &os, const Date &p)
{
	os << std::setfill('0') << std::setw(4) << p.getYear() << "-" << std::setw(2) << p.getMonth() << '-' << std::setw(2) << p.getDay();
	return os;
}

// exception

const char* Date::InvalidDate::what() const throw()
{
	return "Invalid Date";
}

const char* NotANumber::what() const throw()
{
	return "nan";
}
