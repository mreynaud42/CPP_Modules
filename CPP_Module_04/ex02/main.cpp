/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:25:31 by mreynaud          #+#    #+#             */
/*   Updated: 2025/02/18 21:44:29 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	AbstractAnimal *animal = new Dog();
	// AbstractAnimal *animal = new AbstractAnimal();
	// AbstractAnimal animal;
	Dog dog;
	Cat cat;

	std::cout << std::endl;

	std::cout << dog.getType() << std::endl;
	dog.makeSound();

	std::cout << std::endl;

	std::cout << cat.getType() << std::endl;
	cat.makeSound();

	std::cout << std::endl;

	std::cout << animal->getType() << std::endl;
	animal->makeSound();

	std::cout << std::endl;

	return 0;
}
