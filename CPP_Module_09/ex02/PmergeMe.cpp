/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:04:50 by mreynaud          #+#    #+#             */
/*   Updated: 2025/09/03 11:59:43 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include "PmergeMe.hpp"

size_t jacobsthal_number(const size_t n) {
	return (pow(2, n) - pow(-1, n)) / 3;
}

//------------------------------------------------- vector -------------------------------------------------//

/*
#include <iostream>

void printv(std::vector<int> vec)
{
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
}

void	printvpv(std::vector<std::pair<std::vector<int>, std::vector<int> > > vpv)
{
	std::cout << "-----------------------------------------------------" << std::endl;
	for (size_t i = 0; i < vpv.size(); ++i)
	{
		std::cout << "b: ";
		printv(vpv[i].second);
		std::cout << "| a: ";
		printv(vpv[i].first);
		std::cout << std::endl;
	}
	std::cout << "-----------------------------------------------------" << std::endl;
}
*/

void	swapWithRange(std::vector<int> &vec, const int it, const size_t range)
{
	for (size_t i = it - range + 1; it - i < range; ++i)
		std::swap(vec[i], vec[range + i]);
}


std::vector<std::pair<std::vector<int>, std::vector<int> > > vecToVecPairVec(const std::vector<int> &vec, const size_t size)
{
	std::vector<std::pair<std::vector<int>, std::vector<int> > > vecPairVec;

	size_t i = 0;
	while (i < vec.size() / size + 1)
	{
		if (((vec.begin() + size * i) + size - 1) < vec.end())
		{
			vecPairVec.push_back(std::pair<std::vector<int>, std::vector<int> >( \
								std::vector<int>((vec.begin() + size * i) + (size / 2), (vec.begin() + size * i) + size), \
								std::vector<int>((vec.begin() + size * i), (vec.begin() + size * i) + (size / 2))));

		}
		else if ((vec.begin() + size * i + size / 2 - 1) < vec.end())
		{
			vecPairVec.push_back(std::pair<std::vector<int>, std::vector<int> >( \
								std::vector<int>((vec.begin() + size * i) + (size / 2), vec.end()), \
								std::vector<int>((vec.begin() + size * i), (vec.begin() + size * i) + (size / 2))));
		}
		else
		{
			vecPairVec.push_back(std::pair<std::vector<int>, std::vector<int> >( \
								std::vector<int>((vec.begin() + size * i), vec.end()), \
								std::vector<int>()));
		}
		i++;
	}

	return vecPairVec;
}

void	dichotomy(std::vector<std::vector<int> > &mainChain, const std::pair<std::vector<int>, std::vector<int> > &pair)
{
	size_t	max = 0;

	while (max < mainChain.size() && mainChain[max] != pair.first)
		++max;
	size_t	min = 0;
	while (max - min > 1)
	{
		if (mainChain[min + (max - min) / 2].back() > pair.second.back())
		{
			max = min + (max - min) / 2;
		}
		else
		{
			min = min + (max - min) / 2;
		}
	}
	if (mainChain[min].back() < pair.second.back())
		mainChain.insert(mainChain.begin() + max, pair.second);
	else
		mainChain.insert(mainChain.begin() + min, pair.second);
}

std::vector<int>  mergeInsertionSort(std::vector<int> vec)
{
	size_t j = 1;

	while (j * 2 <= vec.size())
	{
		for (size_t i = j - 1;i < vec.size() - j; i += j * 2)
			if (vec[i] > vec[i + j])
				swapWithRange(vec, i, j);
		j *= 2;
	}

	while (j > 1)
	{
		std::vector<std::pair<std::vector<int>, std::vector<int> > > ab = vecToVecPairVec(vec, j);
		std::vector<std::vector<int> > mainChain;

		mainChain.push_back(ab[0].second);
		for (size_t i = 0; i < ab.size() - 1; ++i)
			mainChain.push_back(ab[i].first);

		size_t n = 3;
		size_t old_jacobsthal_nb = jacobsthal_number(n - 1);
		while (old_jacobsthal_nb < ab.size())
		{
			size_t jacobsthal_res = jacobsthal_number(n) - 1;
			if (jacobsthal_res >= ab.size())
				jacobsthal_res = ab.size() - 1;
			while (jacobsthal_res >= old_jacobsthal_nb)
			{
				if (ab[jacobsthal_res].second.size() == j / 2)
					dichotomy(mainChain, ab[jacobsthal_res]);
				--jacobsthal_res;
			}
			old_jacobsthal_nb = jacobsthal_number(n);
			++n;
		}

		vec.clear();
		for (size_t i = 0; i < mainChain.size(); ++i)
		{
			vec.insert(vec.end(), mainChain[i].begin(), mainChain[i].end());
		}
		vec.insert(vec.end(), ab.back().first.begin(), ab.back().first.end());

		j /= 2;
	}
	return vec;
}

//------------------------------------------------- deque -------------------------------------------------//

void	swapWithRange(std::deque<int> &deque, const int it, const size_t range)
{
	for (size_t i = it - range + 1; it - i < range; ++i)
		std::swap(deque[i], deque[range + i]);
}

std::deque<std::pair<std::deque<int>, std::deque<int> > > dequeToDequePairDeque(const std::deque<int> &deque, const size_t size)
{
	std::deque<std::pair<std::deque<int>, std::deque<int> > > dequePairDeque;

	size_t i = 0;
	while (i < deque.size() / size + 1)
	{
		if (((deque.begin() + size * i) + size - 1) < deque.end())
		{
			dequePairDeque.push_back(std::pair<std::deque<int>, std::deque<int> >( \
								std::deque<int>((deque.begin() + size * i) + (size / 2), (deque.begin() + size * i) + size), \
								std::deque<int>((deque.begin() + size * i), (deque.begin() + size * i) + (size / 2))));

		}
		else if ((deque.begin() + size * i + size / 2 - 1) < deque.end())
		{
			dequePairDeque.push_back(std::pair<std::deque<int>, std::deque<int> >( \
								std::deque<int>((deque.begin() + size * i) + (size / 2), deque.end()), \
								std::deque<int>((deque.begin() + size * i), (deque.begin() + size * i) + (size / 2))));
		}
		else
		{
			dequePairDeque.push_back(std::pair<std::deque<int>, std::deque<int> >( \
								std::deque<int>((deque.begin() + size * i), deque.end()), \
								std::deque<int>()));
		}
		i++;
	}

	return dequePairDeque;
}

void	dichotomy(std::deque<std::deque<int> > &mainChain, const std::pair<std::deque<int>, std::deque<int> > &pair)
{
	size_t	max = 0;

	while (max < mainChain.size() && mainChain[max] != pair.first)
		++max;
	size_t	min = 0;
	while (max - min > 1)
	{
		if (mainChain[min + (max - min) / 2].back() > pair.second.back())
		{
			max = min + (max - min) / 2;
		}
		else
		{
			min = min + (max - min) / 2;
		}
	}
	if (mainChain[min].back() < pair.second.back())
		mainChain.insert(mainChain.begin() + max, pair.second);
	else
		mainChain.insert(mainChain.begin() + min, pair.second);
}

std::deque<int>  mergeInsertionSort(std::deque<int> deque)
{
	size_t j = 1;

	while (j * 2 <= deque.size())
	{
		for (size_t i = j - 1;i < deque.size() - j; i += j * 2)
			if (deque[i] > deque[i + j])
				swapWithRange(deque, i, j);
		j *= 2;
	}

	while (j > 1)
	{
		std::deque<std::pair<std::deque<int>, std::deque<int> > > ab = dequeToDequePairDeque(deque, j);
		std::deque<std::deque<int> > mainChain;

		mainChain.push_back(ab[0].second);
		for (size_t i = 0; i < ab.size() - 1; ++i)
			mainChain.push_back(ab[i].first);

		size_t n = 3;
		while (jacobsthal_number(n - 1) < ab.size())
		{
			size_t jacobsthal_res = jacobsthal_number(n) - 1;
			if (jacobsthal_res >= ab.size())
				jacobsthal_res = ab.size() - 1;
			while (jacobsthal_res >= jacobsthal_number(n - 1))
			{
				if (ab[jacobsthal_res].second.size() == j / 2)
					dichotomy(mainChain, ab[jacobsthal_res]);
				--jacobsthal_res;
			}
			++n;
		}
		deque.clear();
		for (size_t i = 0; i < mainChain.size(); ++i)
		{
			deque.insert(deque.end(), mainChain[i].begin(), mainChain[i].end());
		}
		deque.insert(deque.end(), ab.back().first.begin(), ab.back().first.end());
		j /= 2;
	}
	return deque;
}
