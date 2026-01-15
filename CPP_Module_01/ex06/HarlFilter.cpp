/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harlFilter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:10:32 by mreynaud          #+#    #+#             */
/*   Updated: 2025/01/29 12:51:16 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HarlFilter.hpp"

HarlFilter::HarlFilter() {}

HarlFilter::~HarlFilter()
{
}

void HarlFilter::_debug(void)
{
	std::cout << "[DEBUG]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void HarlFilter::_info(void)
{
	std::cout << "[INFO]\nI cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void HarlFilter::_warning(void)
{
	std::cout << "[WARNING]\nI think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void HarlFilter::_error(void)
{
	std::cout << "[ERROR]\nThis is unacceptable! I want to speak to the manager now." << std::endl;
}

void HarlFilter::complain(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (HarlFilter::*functions[4]) (void) = {&HarlFilter::_debug, &HarlFilter::_info, &HarlFilter::_warning, &HarlFilter::_error};

	size_t i = 0;

	while (i < 4 && level != levels[i])
		++i;

	switch(i)
	{
		case 0 :
			(this->*functions[0])();

		case 1 :
			(this->*functions[1])();

		case 2 :
			(this->*functions[2])();

		case 3 :
			(this->*functions[3])();
			break;

		default:
			std::cerr << "<level> = DEBUG, INFO, WARNING or ERROR" << std::endl;
			break;
	}
}
