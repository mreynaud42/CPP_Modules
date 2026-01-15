/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 22:28:09 by mreynaud          #+#    #+#             */
/*   Updated: 2025/07/19 22:46:00 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATE_HPP
# define DATE_HPP

#include <fstream>

class Date
{
	private:
		unsigned int	_year;
		unsigned int	_month;
		unsigned int	_day;

		Date();

		Date	&operator=(const Date &);

	public:
		Date(std::string date);
		Date(const Date &other);
		~Date();

		bool operator>(const Date &other) const;
		bool operator<(const Date &other) const;
		bool operator>=(const Date &other) const;
		bool operator<=(const Date &other) const;
		bool operator==(const Date &other) const;
		bool operator!=(const Date &other) const;

		unsigned int	getYear(void) const;
		unsigned int	getMonth(void) const;
		unsigned int	getDay(void) const;

		bool isValidDate(const int year, const int month, const int day) const;

		class InvalidDate : public std::exception
		{
			const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, const Date &p);

class NotANumber : public std::exception
{
	const char* what() const throw();
};

#endif
