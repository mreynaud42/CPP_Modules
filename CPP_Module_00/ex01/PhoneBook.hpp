/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 22:18:04 by mreynaud          #+#    #+#             */
/*   Updated: 2025/02/12 15:08:24 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include "Contact.hpp"

class PhoneBook
{
private:
	Contact _contacts[9];
	int		_index;
	bool	_isIndex;
public:
	PhoneBook();
	~PhoneBook();

	Contact	getContact(int index) const;
	int		getIsIndex() const;

	void	setContact(Contact contact);

	void	displayPhoneBook() const;
};

#endif
