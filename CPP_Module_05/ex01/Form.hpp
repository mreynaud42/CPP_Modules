/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:43:36 by mreynaud          #+#    #+#             */
/*   Updated: 2025/03/10 15:04:39 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeSign;
		const int			_gradeExecute;

	public:
		Form();
		Form(const std::string name, const int gradeSign, const int gradeExecute);
		Form(const Form &other);
		~Form();

		Form &operator=(const Form &other);

		std::string getName() const;
		bool getSigned() const;
		int getGradeSign() const;
		int getGradeExecute() const;

		void beSigned(const Bureaucrat bureaucrat);

		class AlreadySigned : public std::exception
		{
			const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream &os, const Form &p);

#endif
