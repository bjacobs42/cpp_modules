/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:21:03 by bjacobs           #+#    #+#             */
/*   Updated: 2023/08/17 23:31:36 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include "string"

class AMateria;

class ICharacter {

	public:
		virtual	~ICharacter(void) {}

		virtual	const std::string&	getName(void) const = 0;
		virtual	void				equip(AMateria* materia) = 0;
		virtual	void				unequip(int index) = 0;
		virtual	void				use(int index, ICharacter& target) = 0;
};

#endif // !ICHARACTER_HPP
