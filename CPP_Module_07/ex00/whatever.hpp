/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 20:52:34 by mreynaud          #+#    #+#             */
/*   Updated: 2025/03/30 21:01:35 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template<typename T>
void swap(T &a, T &b)
{
	T tmp = a;

	a = b;
	b = tmp;
}

template<typename T>
T min(const T &a, const T &b)
{
	if (a < b)
		return a;
	return b;
}

template<typename T>
T max(const T &a, const T &b)
{
	if (a > b)
		return a;
	return b;
}
