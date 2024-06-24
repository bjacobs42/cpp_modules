/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:18:09 by bjacobs           #+#    #+#             */
/*   Updated: 2023/08/17 23:15:51 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria {

	public:
		Cure(void);
		Cure(const Cure& source);
		virtual ~Cure(void);

		Cure&	operator=(const Cure& rightSide);

		virtual AMateria*	clone(void) const;
		virtual void		use(ICharacter& target);
};

#endif // !CURE_HPP
