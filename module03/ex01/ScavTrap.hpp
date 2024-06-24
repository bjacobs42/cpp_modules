/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 00:35:29 by bjacobs           #+#    #+#             */
/*   Updated: 2024/01/25 20:06:36 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	
	public:
		ScavTrap(void);
		ScavTrap(const std::string& name);
		ScavTrap(const ScavTrap& source);
		~ScavTrap(void);

		ScavTrap&	operator=(const ScavTrap& rightSide);

		void		guardGate(void);
		void		attack(const std::string & target);

	private:
		bool		gateKeeperMode;
};

#endif // !SCAVTRAP_HPP
