/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 08:17:12 by mreynaud          #+#    #+#             */
/*   Updated: 2025/09/12 19:39:39 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>

class Span
{
	private:
		std::vector<int> _vec;
		unsigned int _size_max;

	public:
		Span();
		Span(unsigned int n);
		Span(const Span &other);
		~Span();

		Span &operator=(const Span &other);

		void addNumber(int number);

		int shortestSpan();
		int longestSpan();

		void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
};
