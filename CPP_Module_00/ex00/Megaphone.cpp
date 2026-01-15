/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:04:56 by mreynaud          #+#    #+#             */
/*   Updated: 2025/01/25 20:07:14 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cerr << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	std::string str;
	for (int i = 1; i < argc; i++)
		str.append(argv[i]);
	for (std::string::iterator it = str.begin(); it != str.end(); it++)
		*it = toupper(*it);
	std::cout << str << std::endl;
	return (0);
}
