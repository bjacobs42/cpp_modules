/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:06:18 by bjacobs           #+#    #+#             */
/*   Updated: 2023/08/17 23:32:22 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

# define MAX_INVENTORY 4

class Character : public ICharacter {

	public:
		Character(void);
		Character(const std::string& name);
		Character(const Character& source);
		~Character(void);

		Character&			operator=(const Character& rightSide);
		
		const std::string&	getName(void) const;
		void				equip(AMateria* materia);
		void				unequip(int index);
		void				use(int index, ICharacter& target);

	private:
		std::string	_name;
		AMateria*	_inventory[MAX_INVENTORY];
};

#endif // !CHARACTER_HPP
