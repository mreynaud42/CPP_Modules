/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 05:53:34 by mreynaud          #+#    #+#             */
/*   Updated: 2025/09/12 18:21:50 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include "EasyFind.tpp"

int main()
{

	std::vector<int> nums;
    nums.push_back(6);
    nums.push_back(12);
    nums.push_back(21);
    nums.push_back(24);
    nums.push_back(42);
    nums.push_back(4242);
    nums.push_back(0);
	try
	{
		std::cout << *EasyFind(nums, 42) << std::endl;
		std::cout << *EasyFind(nums, 0) << std::endl;
		std::cout << *EasyFind(nums, 5) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
