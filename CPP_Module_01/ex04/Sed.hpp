/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:35:10 by mreynaud          #+#    #+#             */
/*   Updated: 2025/02/16 23:01:59 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

# include <string>

class Sed
{
	private:
		std::string _fileName;
		std::string _replaceFileName;
		std::string _s1;
		std::string _s2;

	public:
		Sed(std::string fileName, std::string s1, std::string s2);
		~Sed();

		std::string getFileName() const;
		std::string getReplaceFileName() const;
		std::string getS1() const;
		std::string getS2() const;
};

bool replace(int argc, char const *argv[]);

#endif
