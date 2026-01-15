/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:17:12 by mreynaud          #+#    #+#             */
/*   Updated: 2025/02/05 17:58:27 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void)
{
	/* test on the triangle :
	Point const a(5, 5);
	Point const b(8, 2);
	Point const c(2, 2);
	*/
	{
		Point const a(5, 5);
		Point const b(8, 2);
		Point const c(2, 2);
		Point const point(5, 3);

		if (bsp(a, b, c, point))
			std::cout << "[\033[32mOK\033[0m] The point is in the triangle" << std::endl;
		else
			std::cout << "[X][\033[31mKO\033[0m] The point is not in the triangle" << std::endl;
	}
	{
		Point const a(5, 5);
		Point const b(8, 2);
		Point const c(2, 2);
		Point const point(5, 5);

		if (bsp(a, b, c, point))
			std::cout << "[X][\033[32mOK\033[0m] The point is in the triangle" << std::endl;
		else
			std::cout << "[\033[31mKO\033[0m] The point is not in the triangle" << std::endl;
	}
	{
		Point const a(5, 5);
		Point const b(8, 2);
		Point const c(2, 2);
		Point const point(8, 2);

		if (bsp(a, b, c, point))
			std::cout << "[X][\033[32mOK\033[0m] The point is in the triangle" << std::endl;
		else
			std::cout << "[\033[31mKO\033[0m] The point is not in the triangle" << std::endl;
	}
	{
		Point const a(5, 5);
		Point const b(8, 2);
		Point const c(2, 2);
		Point const point(2, 2);

		if (bsp(a, b, c, point))
			std::cout << "[X][\033[32mOK\033[0m] The point is in the triangle" << std::endl;
		else
			std::cout << "[\033[31mKO\033[0m] The point is not in the triangle" << std::endl;
	}
	{
		Point const a(5, 5);
		Point const b(8, 2);
		Point const c(2, 2);
		Point const point(6, 4);

		if (bsp(a, b, c, point))
			std::cout << "[X][\033[32mOK\033[0m] The point is in the triangle" << std::endl;
		else
			std::cout << "[\033[31mKO\033[0m] The point is not in the triangle" << std::endl;
	}
	{
		Point const a(5, 5);
		Point const b(8, 2);
		Point const c(2, 2);
		Point const point(3, 3);

		if (bsp(a, b, c, point))
			std::cout << "[X][\033[32mOK\033[0m] The point is in the triangle" << std::endl;
		else
			std::cout << "[\033[31mKO\033[0m] The point is not in the triangle" << std::endl;
	}
	{
		Point const a(5, 5);
		Point const b(8, 2);
		Point const c(2, 2);
		Point const point(5, 2);

		if (bsp(a, b, c, point))
			std::cout << "[X][\033[32mOK\033[0m] The point is in the triangle" << std::endl;
		else
			std::cout << "[\033[31mKO\033[0m] The point is not in the triangle" << std::endl;
	}
	{
		Point const a(5, 5);
		Point const b(8, 2);
		Point const c(2, 2);
		Point const point(7.5, 2.25);

		if (bsp(a, b, c, point))
			std::cout << "[\033[32mOK\033[0m] The point is in the triangle" << std::endl;
		else
			std::cout << "[X][\033[31mKO\033[0m] The point is not in the triangle" << std::endl;
	}

	// test specific case
	std::cout << std::endl << "test specific case" << std::endl;
	{
		Point const a(3.5, 5);
		Point const b(8, 2);
		Point const c(2, 3);
		Point const point(3.5, 3);

		if (bsp(a, b, c, point))
			std::cout << "[\033[32mOK\033[0m] The point is in the triangle" << std::endl;
		else
			std::cout << "[X][\033[31mKO\033[0m] The point is not in the triangle" << std::endl;
	}
	{
		Point const a(3.5, 5);
		Point const b(8, 2);
		Point const c(2, 3);
		Point const point(9.5, 4);

		if (bsp(a, b, c, point))
			std::cout << "[X][\033[32mOK\033[0m] The point is in the triangle" << std::endl;
		else
			std::cout << "[\033[31mKO\033[0m] The point is not in the triangle" << std::endl;
	}

	// random test with positive numbers
	std::cout << std::endl << "random test" << std::endl;
	{
		Point const a(4.41, 2.48);
		Point const b(5.57, 1.94);
		Point const c(1.89, 6.79);
		Point const point(2.06, 4.75);

		if (bsp(a, b, c, point))
			std::cout << "[X][\033[32mOK\033[0m] The point is in the triangle" << std::endl;
		else
			std::cout << "[\033[31mKO\033[0m] The point is not in the triangle" << std::endl;
	}
	{
		Point const a(4.41, 2.48);
		Point const b(5.57, 1.94);
		Point const c(1.89, 6.79);
		Point const point(3.69, 3.28);

		if (bsp(a, b, c, point))
			std::cout << "[X][\033[32mOK\033[0m] The point is in the triangle" << std::endl;
		else
			std::cout << "[\033[31mKO\033[0m] The point is not in the triangle" << std::endl;
	}
	{
		Point const a(4.41, 2.48);
		Point const b(5.57, 1.94);
		Point const c(1.89, 6.79);
		Point const point(3.14, 4.93);

		if (bsp(a, b, c, point))
			std::cout << "[\033[32mOK\033[0m] The point is in the triangle" << std::endl;
		else
			std::cout << "[X][\033[31mKO\033[0m] The point is not in the triangle" << std::endl;
	}
	// random test with positive and negative numbers
	{
		Point const a(-0.69, -0.49);
		Point const b(-1.16, 8.10);
		Point const c(3.94, 1.32);
		Point const point(-3.57, 4.30);

		if (bsp(a, b, c, point))
			std::cout << "[X][\033[32mOK\033[0m] The point is in the triangle" << std::endl;
		else
			std::cout << "[\033[31mKO\033[0m] The point is not in the triangle" << std::endl;
	}
	{
		Point const a(-0.69, -0.49);
		Point const b(-1.16, 8.10);
		Point const c(3.94, 1.32);
		Point const point(-0.55, 6.46);

		if (bsp(a, b, c, point))
			std::cout << "[\033[32mOK\033[0m] The point is in the triangle" << std::endl;
		else
			std::cout << "[X][\033[31mKO\033[0m] The point is not in the triangle" << std::endl;
	}
	// random test with negative numbers
	{
		Point const a(-1.45, -9.16);
		Point const b(-5.20, -0.93);
		Point const c(-2.18, -4.65);
		Point const point(-0.22, -6.21);

		if (bsp(a, b, c, point))
			std::cout << "[X][\033[32mOK\033[0m] The point is in the triangle" << std::endl;
		else
			std::cout << "[\033[31mKO\033[0m] The point is not in the triangle" << std::endl;
	}
	{
		Point const a(-1.45, -9.16);
		Point const b(-5.20, -0.93);
		Point const c(-2.18, -4.65);
		Point const point(-2.22, -6.21);

		if (bsp(a, b, c, point))
			std::cout << "[\033[32mOK\033[0m] The point is in the triangle" << std::endl;
		else
			std::cout << "[X][\033[31mKO\033[0m] The point is not in the triangle" << std::endl;
	}

	// other test
	std::cout << std::endl << "other test" << std::endl;
	{
		Point const a(3.5, 5);
		Point const b(8, 2);
		Point const c(2, 3);
		Point const point(9.5, 4);

		if (bsp(a, b, c, point))
			std::cout << "[\033[32mOK\033[0m] The point is in the triangle" << std::endl;
		else
			std::cout << "[\033[31mKO\033[0m] The point is not in the triangle" << std::endl;
	}
	return 0;
}
