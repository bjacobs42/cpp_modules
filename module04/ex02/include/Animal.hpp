/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 20:35:46 by bjacobs           #+#    #+#             */
/*   Updated: 2023/08/14 16:04:23 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>

class Animal {

	public:
		Animal(void);
		Animal(const std::string& type);
		Animal(const Animal& source);
		virtual ~Animal(void);

		Animal&	operator=(const Animal& rightSide);

		std::string		getType(void) const;
		virtual void	makeSound(void) const = 0;

	protected:
		std::string	type;
};

#endif // !ANIMAL_HPP
