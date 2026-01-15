/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:19:10 by mreynaud          #+#    #+#             */
/*   Updated: 2025/02/18 14:35:06 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	private:
		int _fixedPointNumberValue;
		static const int _numberOfFractionalBits = 8;

	public:
		Fixed();
		Fixed(const Fixed &other);
		~Fixed();

		Fixed &operator=(const Fixed &other);

		void setRawBits(int const raw);

		int getRawBits(void) const;
};

#endif
