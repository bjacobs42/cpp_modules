/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 20:43:50 by bjacobs           #+#    #+#             */
/*   Updated: 2023/08/13 00:19:10 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {

	public:
		Dog(void);
		Dog(const Dog& source);
		~Dog(void);

		Dog&	operator=(const Dog& rightSide);

		virtual void	makeSound(void) const;
	
	private:
		Brain*	_brain;
};

#endif // !DOG_HPP
