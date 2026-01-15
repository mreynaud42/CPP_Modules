/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:10:38 by mreynaud          #+#    #+#             */
/*   Updated: 2025/07/17 01:00:45 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <cctype>
#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &) {}

RPN::~RPN() {}

RPN	&RPN::operator=(const RPN &)
{
	return *this;
}

double RPN::calcRPN(const char *argv)
{
	std::stack<double>	nbs;

	for (size_t i = 0; argv[i]; ++i)
	{
		if (argv[i] == ' ')
			;
		else if (isdigit(argv[i]))
			nbs.push(argv[i] - '0');
		else if (argv[i] == '+' || argv[i] == '-' || argv[i] == '/' || argv[i] == '*')
		{
			if (nbs.size() < 2)
				throw MissDigit();
			double nb = nbs.top();
			nbs.pop();
			switch (argv[i])
			{
				case '+':
					nbs.top() += nb;
					break;
				case '-':
					nbs.top() = nbs.top() - nb;
					break;
				case '/':
					if (nb == 0)
						throw DivByZero();
					nbs.top() = nbs.top() / nb;
					break;
				case '*':
					nbs.top() *= nb;
					break;
			}
		}
		else
			throw CharNotAccept();
	}
	if (nbs.size() != 1)
		throw MissOp();
	return nbs.top();
}

const char* DivByZero::what() const throw()
{
	return "Error: division by 0 not possible";
}

const char* CharNotAccept::what() const throw()
{
	return "Error: A charatere isn't accepted";
}

const char* MissDigit::what() const throw()
{
	return "Error: Missing digit";
}

const char* MissOp::what() const throw()
{
	return "Error: Missing Operation";
}
