/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 18:39:11 by mreynaud          #+#    #+#             */
/*   Updated: 2025/03/07 14:19:17 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
	{
		try
		{
			Bureaucrat albert("Albert", 150);
			Bureaucrat bernard("Bernard", 1);
			Bureaucrat christian("Christian", 75);

			Form form1("form1", 1, 1);
			Form form150("form150", 150, 1);

			albert.signForm(form1);
			form150.beSigned(bernard);
			std::cout << form150 << std::endl;
			christian.signForm(form150);
			form1.beSigned(christian);
		}
		catch (std::exception & e)
		{
			std::cerr << "Erreur: " << e.what() << std::endl;
		}
	}
	return 0;
}
