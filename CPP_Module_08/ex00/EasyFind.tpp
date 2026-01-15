/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EasyFind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 05:54:41 by mreynaud          #+#    #+#             */
/*   Updated: 2025/09/12 18:21:32 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdexcept>
#include <algorithm>

template <typename T>
typename T::const_iterator EasyFind(const T &container, int value)
{
	typename T::const_iterator it = find(container.begin(), container.end(), value);
	if (it != container.end())
		return it;
    throw std::runtime_error("Element not found");
}
