/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:04:50 by mreynaud          #+#    #+#             */
/*   Updated: 2025/07/19 22:34:25 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <stdexcept>
#include <fstream>
#include <string>

class Date;

class BitcoinExchange
{
	private:
		std::map<Date, float>	_data;

		BitcoinExchange(const BitcoinExchange &);
		BitcoinExchange();

		BitcoinExchange &operator=(const BitcoinExchange &);

	public:
		BitcoinExchange(std::string file);
		~BitcoinExchange();

		void	exchange(const Date d, float exchangeRate);
};

class NotOpenFile : public std::exception
{
	const char* what() const throw();
};

class BadInput : public std::exception
{
	const char* what() const throw();
};

class NotPostiveNumber : public std::exception
{
	const char* what() const throw();
};

class LargeNumber : public std::exception
{
	const char* what() const throw();
};

class NoData : public std::exception
{
	const char* what() const throw();
};

#endif
