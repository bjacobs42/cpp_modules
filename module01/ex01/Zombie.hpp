/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:10:07 by bjacobs           #+#    #+#             */
/*   Updated: 2023/07/12 16:39:15 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class	Zombie {

	public:
		void	announce(void);
		void	setName(std::string name);
		Zombie*	zombieHorde(int n, std::string name);

		Zombie(std::string name);
		Zombie(void);
		~Zombie(void);

	private:
		std::string	_name;
};

#endif
