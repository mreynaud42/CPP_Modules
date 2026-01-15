/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractAnimal.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:54:56 by mreynaud          #+#    #+#             */
/*   Updated: 2025/02/18 21:43:22 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACTANIMAL_HPP
# define ABSTRACTANIMAL_HPP

# include <iostream>

class AbstractAnimal
{
	protected:
		std::string _type;

		AbstractAnimal(std::string type);

	public:
		AbstractAnimal();
		AbstractAnimal(const AbstractAnimal &other);
		virtual ~AbstractAnimal();

		AbstractAnimal &operator=(const AbstractAnimal &other);

		std::string getType() const;

		virtual void makeSound() const = 0;
};

#endif
