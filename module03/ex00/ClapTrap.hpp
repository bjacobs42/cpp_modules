/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:15:02 by bjacobs           #+#    #+#             */
/*   Updated: 2023/07/21 21:44:44 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>

class ClapTrap {

	public:
		ClapTrap(void);
		ClapTrap(const std::string name);
		ClapTrap(const ClapTrap & source);
		~ClapTrap(void);

		std::string		getName(void) const;
		unsigned int	getHealthPoints(void) const;
		unsigned int	getEnergyPoints(void) const;
		unsigned int	getAttackDamage(void) const;

		ClapTrap &		operator=(const ClapTrap & rightSide);

		void			attack(const std::string & target);
		void			takeDamage(unsigned int amount);
		void			beRepaied(unsigned int amount);
	
	private:
		std::string		_name;
		unsigned int	_healthPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
};

#endif // !CLAPTRAP_HPP
