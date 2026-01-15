/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:25:31 by mreynaud          #+#    #+#             */
/*   Updated: 2025/02/14 00:14:40 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	{
		Animal *animals[4];

		for (size_t i = 0; i < 4; i++)
		{
			if ( i % 2 == 0)
				animals[i] = new Dog();
			else
				animals[i] = new Cat();
		}
		for (size_t i = 0; i < 4; i++)
			delete animals[i];
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "----------------------------------" << std::endl;
	{
		const Animal* dog = new Dog();
		const Animal* cat = new Cat();

		std::cout << std::endl;

		std::cout << dog->getType() << std::endl;
		std::cout << cat->getType() << std::endl;

		std::cout << std::endl;

		cat->makeSound();
		dog->makeSound();

		std::cout << std::endl;

		delete dog;
		delete cat;
	}
	std::cout << "----------------------------------" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	{
		Dog* dog1 = new Dog();

		std::cout << std::endl;

		dog1->setBrainIdea("I think, therefore I am.");
		std::cout << "dog1: " << std::endl;
		dog1->printBrain();

		std::cout << std::endl;

		Dog* dog2 = new Dog();
		*dog2 = *dog1;

		std::cout << std::endl;

		dog2->setBrainIdea("Am I a good dog or a bad dog?");
		std::cout << "dog1: " << std::endl;
		dog1->printBrain();
		std::cout << "dog2: " << std::endl;
		dog2->printBrain();

		std::cout << std::endl;

		Dog* dog3 = new Dog(*dog1);

		std::cout << std::endl;

		dog3->setBrainIdea("bones are better than kibble");
		std::cout << "dog1: " << std::endl;
		dog1->printBrain();
		std::cout << "dog3: " << std::endl;
		dog3->printBrain();

		std::cout << std::endl;

		delete dog1;
		delete dog2;
		delete dog3;
	}
	return 0;
}
