/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:34:54 by mreynaud          #+#    #+#             */
/*   Updated: 2025/02/16 23:32:23 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "Sed.hpp"

Sed::Sed(std::string fileName, std::string s1, std::string s2) : _fileName(fileName), _replaceFileName(fileName + ".replace"), _s1(s1), _s2(s2) {}

Sed::~Sed() {}

std::string Sed::getFileName() const
{
	return _fileName;
}

std::string Sed::getReplaceFileName() const
{
	return _replaceFileName;
}

std::string Sed::getS1() const
{
	return _s1;
}

std::string Sed::getS2() const
{
	return _s2;
}

bool replace(int argc, char const *argv[])
{
	if (argc != 4)
	{
		std::cerr << "please follow this: ./Sed <filename> <s1> <s2>" << std::endl;
		return false;
	}
	else if (!*argv[2])
	{
		std::cerr << "<s1> cannot be null" << std::endl;
		return false;
	}

	Sed	sed(argv[1], argv[2], argv[3]);
	std::fstream file;
	file.open(sed.getFileName().c_str(), std::fstream::in);
	if (!file.is_open())
	{
		std::cerr << "Error in opening file!" << std::endl;
		return false;
	}
	std::fstream replace;
	replace.open(sed.getReplaceFileName().c_str(), std::fstream::out);
	if (!replace.is_open())
	{
		file.close();
		std::cerr << "Error in creating file!" << std::endl;
		return false;
	}

	std::string str;
	getline(file, str, '\0');

	std::size_t found = str.find(sed.getS1());
	while (found!=std::string::npos)
	{
		str.erase(found, sed.getS1().size());
		str.insert(found, sed.getS2());
		found += sed.getS2().size();
		found = str.find(sed.getS1(), found);
	}
	replace << str;
	file.close();
	replace.close();
	return true;
}
