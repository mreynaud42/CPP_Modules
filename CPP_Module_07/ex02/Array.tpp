/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 04:18:05 by mreynaud          #+#    #+#             */
/*   Updated: 2025/03/30 22:17:36 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdexcept>
#include "Array.hpp"

template <typename T>
Array<T>::Array() : _data(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int size) : _size(size)
{
	_data = new T[size];
}

template <typename T>
Array<T>::Array(Array &other)
{
	*this = other;
}

template <typename T>
Array<T>::~Array()
{
	delete [] _data;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
	_data = new T[other._size];
	for (unsigned int i = 0; i < other._size; ++i)
		_data[i] = other._data[i];
	_size = other._size;
	return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw std::out_of_range("Index out of range");
	return _data[index];
}


template <typename T>
unsigned int Array<T>::size() const
{
	return _size;
}
