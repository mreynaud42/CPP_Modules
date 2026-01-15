/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:43:36 by mreynaud          #+#    #+#             */
/*   Updated: 2025/03/10 15:23:04 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeSign;
		const int			_gradeExecute;

	public:
		AForm();
		AForm(const std::string name, const int gradeSign, const int gradeExecute);
		AForm(const AForm &other);
		virtual ~AForm();

		AForm &operator=(const AForm &other);

		std::string getName() const;
		bool getSigned() const;
		int getGradeSign() const;
		int getGradeExecute() const;

		void beSigned(const Bureaucrat bureaucrat);

		virtual void execute(Bureaucrat const &executor) const = 0;

		class AlreadySigned : public std::exception
		{
			const char* what() const throw();
		};
		class FormNotSigned : public std::exception
		{
			const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream &os, const AForm &p);

#endif
