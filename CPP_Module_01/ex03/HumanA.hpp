/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 23:45:35 by mreynaud          #+#    #+#             */
/*   Updated: 2025/02/16 22:44:00 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
	private:
		Weapon &_weapon;
		std::string _name;

	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA();

		void setWeapon(Weapon &weapon);
		void attack() const;
};

#endif
