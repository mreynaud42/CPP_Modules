/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 21:31:44 by mreynaud          #+#    #+#             */
/*   Updated: 2025/07/22 06:05:18 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>

template<typename T>
void iter(T* table, size_t size, void (*f)(T&))
{
	for (size_t i = 0; i < size; ++i)
		f(table[i]);
}

template<typename T>
void iter(const T* table, size_t size, void (*f)(const T&))
{
	for (size_t i = 0; i < size; ++i)
		f(table[i]);
}
