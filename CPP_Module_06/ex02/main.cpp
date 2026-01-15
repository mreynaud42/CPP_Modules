/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 23:15:04 by mreynaud          #+#    #+#             */
/*   Updated: 2025/04/04 07:19:43 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"

int main()
{
	srand(time(NULL));
	{
		std::cout << "Random test:" << std::endl;
		for (size_t i = 0; i < 10; ++i)
		{
			Base *base = Base::generate();
			Base::identify(base);
			delete base;
		}

		std::cout << "ABC test:" << std::endl;
		Base *a = new A;
		Base::identify(a);
		delete a;
		Base *b = new B;
		Base::identify(b);
		delete b;
		Base *c = new C;
		Base::identify(c);
		delete c;
	}
	std::cout << "##################" << std::endl;
	{
		std::cout << "Random test:" << std::endl;
		for (size_t i = 0; i < 10; ++i)
		{
			Base *base = Base::generate();
			Base &baseRef = *base;
			Base::identify(baseRef);
			delete base;
		}

		std::cout << "ABC test:" << std::endl;
		A a;
		Base &aRef = a;
		Base::identify(aRef);

		B b;
		Base &bRef = b;
		Base::identify(bRef);

		C c;
		Base &cRef = c;
		Base::identify(cRef);
	}
	return 0;
}
