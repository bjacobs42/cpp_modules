/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:41:01 by bjacobs           #+#    #+#             */
/*   Updated: 2023/08/11 19:10:51 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

	public:
		FragTrap(void);
		FragTrap(const FragTrap& source);
		FragTrap(const std::string& name);
		~FragTrap(void);

		FragTrap&	operator=(const FragTrap& rightSide);

		void		highFivesGuys(void);
		void		attack(const std::string& target);
};

#endif // !FRAGTRAP_HPP
