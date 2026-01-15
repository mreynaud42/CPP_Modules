/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 21:31:30 by mreynaud          #+#    #+#             */
/*   Updated: 2025/07/22 06:05:58 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <iostream>

// class Awesome
// {
//   public:
//     Awesome( void ) : _n( 42 ) { return; }
//     int get( void ) const { return this->_n; }
//   private:
//     int _n;
// };

// std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
// {
//   o << rhs.get();
//   return o;
// }

template<typename T>
void print(const T &a)
{
	std::cout << a;
}

void f1(const int &a)
{
	if (a == 1)
		std::cout << "Hey" << std::endl;
}

void f2(char &a)
{
	a = std::toupper(a);
}

int main()
{
	{
		const int table_int[] = {0, 1, 2};

		::iter(table_int, 3, f1);
		::iter(table_int, 3, print);
		std::cout << std::endl;
	}
	{
		char str[] = "Hello World!";

		::iter(str, 13, f2);
		::iter(str, 13, print);
		std::cout << std::endl;
	}
	{
		char str[] = "Hello World!";

		::iter(str, 13, f2);
		::iter(str, 13, print);
		std::cout << std::endl;
	}
	// {
	// 	int tab[] = { 0, 1, 2, 3, 4 };
	// 	Awesome tab2[5];

	// 	iter( tab, 5, print<const int> );
	// 	std::cout << std::endl;
	// 	iter( tab2, 5, print<Awesome> );
	// 	std::cout << std::endl;
	// }
	return 0;
}
