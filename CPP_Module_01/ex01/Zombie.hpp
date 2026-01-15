/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 20:21:00 by mreynaud          #+#    #+#             */
/*   Updated: 2025/02/16 22:49:29 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie
{
	private:
		std::string _name;

	public:
		~Zombie();
		Zombie();
		Zombie(std::string name);

		void setName(std::string name);
		void announce();
};

Zombie* zombieHorde(int N, std::string name);

#endif
