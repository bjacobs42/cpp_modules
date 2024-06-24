/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:10:07 by bjacobs           #+#    #+#             */
/*   Updated: 2023/07/11 17:34:49 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class	Zombie {

	public:
		void	announce(void);
		void	randomChump(std::string name);
		Zombie*	newZombie(std::string name);

		Zombie(std::string name);
		~Zombie(void);

	private:
		std::string	_name;
};

#endif
