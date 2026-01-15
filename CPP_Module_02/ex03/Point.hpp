/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 22:51:08 by mreynaud          #+#    #+#             */
/*   Updated: 2025/02/18 15:20:23 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		Fixed _x;
		Fixed _y;

	public:
		Point();
		Point(const Point &other);
		Point(float x, float y);
		Point(Fixed x, Fixed y);
		~Point();

		Point &operator=(const Point &other);

		Fixed getX(void) const;
		Fixed getY(void) const;
};



#endif
