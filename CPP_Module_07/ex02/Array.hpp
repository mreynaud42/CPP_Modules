/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 03:59:12 by mreynaud          #+#    #+#             */
/*   Updated: 2025/03/30 22:09:12 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
class Array
{
	private:
		T *_data;
		unsigned int _size;

	public:
		Array();
		Array(unsigned int size);
		Array(Array &other);
		~Array();

		Array &operator=(const Array &other);
		T &operator[](unsigned int index);

		unsigned int size() const;
};
