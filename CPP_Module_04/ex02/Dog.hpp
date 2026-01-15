/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:54:56 by mreynaud          #+#    #+#             */
/*   Updated: 2025/02/18 21:44:18 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AbstractAnimal.hpp"
# include "Brain.hpp"

class Dog : public AbstractAnimal
{
	private:
		Brain *_brain;

	public:
		Dog();
		Dog(const Dog &other);
		~Dog();

		Dog &operator=(const Dog &other);

		void makeSound() const;
		void setBrainIdea(std::string idea);
		void printBrain() const;
};

#endif
