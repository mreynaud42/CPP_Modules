/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 22:52:01 by mreynaud          #+#    #+#             */
/*   Updated: 2025/02/17 15:46:36 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Point findIntersection(Point const a, Point const b, Point const c, Point const d)
{
	Fixed slopeAB, slopeCD;
	Fixed yInterceptAB, yInterceptCD;
	Fixed x, y;

	if (a.getX() != b.getX())
	{
		slopeAB = (b.getY() - a.getY()) / (b.getX() - a.getX());
		yInterceptAB = (b.getX() * a.getY() - b.getY() * a.getX()) / (b.getX() - a.getX());
	}
	if (c.getX() != d.getX())
	{
		slopeCD = (d.getY() - c.getY()) / (d.getX() - c.getX());
		yInterceptCD = (d.getX() * c.getY() - d.getY() * c.getX()) / (d.getX() - c.getX());
	}
	if (a.getX() == b.getX() && c.getX() == d.getX())
	{
		x = d.getX();
		y = d.getY();
	}
	else if (a.getX() == b.getX())
	{
		x = a.getX();
		y = (slopeCD * x + yInterceptCD);
	}
	else if (c.getX() == d.getX())
	{
		x = c.getX();
		y = (slopeAB * x + yInterceptAB);
	}
	else if (slopeAB != slopeCD)
	{
		x = (yInterceptCD - yInterceptAB) / (slopeAB - slopeCD);
		y = (slopeAB * x + yInterceptAB);
	}
	else
	{
		x = d.getX();
		y = d.getY();
	}
	Point inter(x, y);
	return inter;
}

bool isPointMinOrMaxY(Point const intersection[2], Point const point)
{
	if (point.getY() <= intersection[0].getY() && \
			point.getY() <= intersection[1].getY() && \
			point.getY() <= intersection[2].getY())
		return true;
	if (point.getY() >= intersection[0].getY() && \
			point.getY() >= intersection[1].getY() && \
			point.getY() >= intersection[2].getY())
		return true;
	return false;

}

bool isPointMinOrMaxX(Point const intersection[2], Point const point)
{
	if (point.getX() <= intersection[0].getX() && \
			point.getX() <= intersection[1].getX() && \
			point.getX() <= intersection[2].getX())
		return true;
	if (point.getX() >= intersection[0].getX() && \
			point.getX() >= intersection[1].getX() && \
			point.getX() >= intersection[2].getX())
		return true;
	return false;

}

bool isEqualX(Point const intersection[2], Point const point)
{
	if (point.getX() == intersection[0].getX() && \
			point.getX() == intersection[1].getX() && \
			point.getX() == intersection[2].getX())
		return true;
	return false;

}

bool isEqualY(Point const intersection[2], Point const point)
{
	if (point.getY() == intersection[0].getY() && \
			point.getY() == intersection[1].getY() && \
			point.getY() == intersection[2].getY())
		return true;
	return false;

}

bool isPointMinOrMax(Point const intersection[2], Point const point)
{
	if (isPointMinOrMaxX(intersection, point) && !isEqualX(intersection, point))
		return true;
	if (isPointMinOrMaxY(intersection, point) && !isEqualY(intersection, point))
		return true;
	return false;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Point intersection[3][3];

	intersection[0][0] = findIntersection(a, b, a, point);
	intersection[0][1] = findIntersection(b, c, a, point);
	intersection[0][2] = findIntersection(c, a, a, point);

	intersection[1][0] = findIntersection(a, b, b, point);
	intersection[1][1] = findIntersection(b, c, b, point);
	intersection[1][2] = findIntersection(c, a, b, point);

	intersection[2][0] = findIntersection(a, b, c, point);
	intersection[2][1] = findIntersection(b, c, c, point);
	intersection[2][2] = findIntersection(c, a, c, point);

	if (isPointMinOrMax(intersection[0], point) || isPointMinOrMax(intersection[1], point) || isPointMinOrMax(intersection[2], point))
		return false;
	return true;
}
