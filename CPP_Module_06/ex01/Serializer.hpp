/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 22:17:10 by mreynaud          #+#    #+#             */
/*   Updated: 2025/03/26 23:18:06 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdint.h>
#include <iostream>

struct Data
{
	int value;
};

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer &other);
		~Serializer();

		Serializer &operator=(const Serializer &other);

	public:

		static uintptr_t serialize(Data* ptr);

		static Data* deserialize(uintptr_t raw);
};
