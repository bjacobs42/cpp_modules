/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:15:38 by bjacobs           #+#    #+#             */
/*   Updated: 2023/08/11 20:20:35 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap {

	public:
		DiamondTrap(void);
		DiamondTrap(const std::string& name);
		DiamondTrap(const DiamondTrap& source);
		~DiamondTrap(void);

		DiamondTrap&	operator=(const DiamondTrap& rightHand);

		using			FragTrap::_healthPoints;
		using			ScavTrap::_energyPoints;
		using			FragTrap::_attackDamage;
		using			ScavTrap::attack;

		void			whoAmI(void);
	
	private:
		std::string		_name;
};

#endif // !DIAMONDTRAP_HPP
