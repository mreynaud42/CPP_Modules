/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:17:12 by mreynaud          #+#    #+#             */
/*   Updated: 2025/01/29 22:48:37 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main(void)
{
	Fixed a;

	std::cout << "a:\t" << a << std::endl;
	std::cout << "++a:\t" << ++a << std::endl;
	std::cout << "a:\t" << a << std::endl;
	std::cout << "a++:\t" << a++ << std::endl;
	std::cout << "a:\t" << a << std::endl << std::endl;

	std::cout << "a:\t" << a << std::endl;
	std::cout << "--a:\t" << --a << std::endl;
	std::cout << "a:\t" << a << std::endl;
	std::cout << "a--:\t" << a-- << std::endl;
	std::cout << "a:\t" << a << std::endl << std::endl;

	std::cout << "3 > 5:\t" << (Fixed(3) > Fixed(5)) << std::endl;
	std::cout << "3 < 5:\t" << (Fixed(3) < Fixed(5)) << std::endl;
	std::cout << "3 >= 5:\t" << (Fixed(3) >= Fixed(5)) << std::endl;
	std::cout << "3 <= 5:\t" << (Fixed(3) <= Fixed(5)) << std::endl;
	std::cout << "3 == 5:\t" << (Fixed(3) == Fixed(5)) << std::endl;
	std::cout << "3 != 5:\t" << (Fixed(3) != Fixed(5)) << std::endl << std::endl;

	std::cout << "3 + 5:\t" << (Fixed(3) + Fixed(5)) << std::endl;
	std::cout << "3 - 5:\t" << (Fixed(3) - Fixed(5)) << std::endl;
	std::cout << "3 * 5:\t" << (Fixed(3) * Fixed(5)) << std::endl;
	std::cout << "15 / 5:\t" << (Fixed(15) / Fixed(5)) << std::endl << std::endl;

	Fixed b(3);
	Fixed c(5);
	std::cout << "min(3, 5): " << Fixed::min(Fixed(3), Fixed(5)) << std::endl;
	std::cout << "min(5, 3): " << Fixed::min(Fixed(5), Fixed(3)) << std::endl;
	std::cout << "min(3, 5): " << Fixed::min(b, c) << std::endl;
	std::cout << "min(5, 3): " << Fixed::min(c, b) << std::endl;
	std::cout << "max(3, 5): " << Fixed::max(Fixed(3), Fixed(5)) << std::endl;
	std::cout << "max(5, 3): " << Fixed::max(Fixed(5), Fixed(3)) << std::endl;
	std::cout << "max(3, 5): " << Fixed::max(b, c) << std::endl;
	std::cout << "max(5, 3): " << Fixed::max(c, b) << std::endl;

	return 0;
}
