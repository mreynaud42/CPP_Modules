/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:25:31 by mreynaud          #+#    #+#             */
/*   Updated: 2025/02/16 01:35:49 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "AMateria.hpp"

int main()
{
	{
		IMateriaSource* src = new MateriaSource();

		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");
		AMateria* tmp;

		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter* bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}
	std::cout << std::endl;
	{
		IMateriaSource* src = new MateriaSource();

		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");
		AMateria* tmp;

		ICharacter* bob = new Character("bob");
		me->use(0, *bob);

		tmp = src->createMateria("ice");
		me->equip(tmp);
		me->unequip(0);

		me->use(0, *bob);
		delete tmp;

		me->unequip(0);

		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		delete tmp;


		me->use(0, *bob);
		me->use(1, *bob);
		me->use(2, *bob);
		me->use(3, *bob);
		me->use(4, *bob);

		delete bob;
		delete me;
		delete src;
	}
	std::cout << std::endl;
	{
		AMateria* ice = new Ice();
		AMateria* cure = new Cure();
		AMateria* ice2 = ice->clone();
		AMateria* cure2;

		std::cout << ice->getType() << std::endl;
		std::cout << cure->getType() << std::endl;
		std::cout << ice2->getType() << std::endl;
		cure2 = cure;
		std::cout << cure2->getType() << std::endl;

		delete ice;
		delete ice2;
		delete cure;
	}
	std::cout << std::endl;
	{
		IMateriaSource* materiaSource = new MateriaSource();
		IMateriaSource* materiaSource2;

		materiaSource->createMateria("wuhfiw");
		materiaSource->learnMateria(new Ice());
		materiaSource->learnMateria(new Cure());

		materiaSource2 = materiaSource;

		AMateria* ice = materiaSource2->createMateria("ice");

		ICharacter* bob = new Character("bob");

		ice->use(*bob);

		delete bob;
		delete ice;
		delete materiaSource;
	}
	std::cout << std::endl;
	{
		AMateria* ice = new Ice();
		Character* bob = new Character("bob");

		std::cout << bob->getName() << std::endl;
		bob->equip(ice);
		Character bob2(*bob);
		std::cout << bob2.getName() << std::endl;
		bob2.use(0, *bob);
		bob->unequip(0);
		bob2.unequip(1);
		bob2.use(0, bob2);

		delete ice;
		delete bob;
	}
	return 0;
}
