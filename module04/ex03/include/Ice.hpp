/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:18:09 by bjacobs           #+#    #+#             */
/*   Updated: 2023/08/17 00:58:23 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria {

	public:
		Ice(void);
		Ice(const Ice& source);
		~Ice(void);

		Ice&	operator=(const Ice& rightSide);

		virtual AMateria*	clone(void) const;
		virtual void		use(ICharacter& target);
};

#endif // !ICE_HPP
