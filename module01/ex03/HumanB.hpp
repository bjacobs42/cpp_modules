/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:20:15 by bjacobs           #+#    #+#             */
/*   Updated: 2023/07/12 20:16:11 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class	HumanB {

	public:
		void	attack(void);
		void	setWeapon(Weapon& type);

		HumanB(std::string name);

	private:
		std::string	_name;
		Weapon*		_equipment;
};

#endif
