/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:24:45 by mreynaud          #+#    #+#             */
/*   Updated: 2025/02/25 13:59:50 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string _name;

	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(std::string name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDamage);
		DiamondTrap(const DiamondTrap &other);
		~DiamondTrap();

		DiamondTrap	&operator=(const DiamondTrap &other);

		void whoAmI();
};

#endif
