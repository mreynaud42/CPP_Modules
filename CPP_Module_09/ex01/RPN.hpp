/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:10:53 by mreynaud          #+#    #+#             */
/*   Updated: 2025/07/17 00:54:50 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <stdexcept>

class RPN
{
	private:
		RPN();
		RPN(const RPN &);
		~RPN();

		RPN &operator=(const RPN &);

	public:

		static double calcRPN(const char *argv);
};

class DivByZero : public std::exception
{
	const char* what() const throw();
};

class CharNotAccept : public std::exception
{
	const char* what() const throw();
};

class MissDigit : public std::exception
{
	const char* what() const throw();
};

class MissOp : public std::exception
{
	const char* what() const throw();
};

#endif
