/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 20:43:50 by bjacobs           #+#    #+#             */
/*   Updated: 2023/08/12 23:23:55 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {

	public:
		Cat(void);
		Cat(const Cat& source);
		~Cat(void);

		Cat&			operator=(const Cat& rightSide);

		virtual void	makeSound(void) const;

	private:
		Brain*	_brain;
};

#endif // !CAT_HPP
