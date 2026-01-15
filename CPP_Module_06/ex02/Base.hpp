/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 23:16:42 by mreynaud          #+#    #+#             */
/*   Updated: 2025/03/27 18:08:55 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Base
{
	public:
		virtual ~Base();

		static Base *generate(void);
		static void identify(Base* p);
		static void identify(Base& p);
};

class A : public Base {};

class B : public Base {};

class C : public Base {};
