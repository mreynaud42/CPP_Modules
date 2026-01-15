/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 03:55:28 by mreynaud          #+#    #+#             */
/*   Updated: 2025/03/31 03:24:55 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.tpp"

int main()
{
	Array<int> a(5);
	Array<int> b;

	try
	{
		a[3] = 42;
		std::cout << a[3] << std::endl;
		b = a;
		std::cout << b[3] << std::endl;
		std::cout << a[5] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}


	return 0;
}
