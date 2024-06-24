/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:15:01 by bjacobs           #+#    #+#             */
/*   Updated: 2024/02/06 03:07:05 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "ICharacter.hpp"
# include <string>

class AMateria {

	public:
		AMateria(void);
		AMateria(const std::string& type);
		AMateria(const AMateria& source);
		virtual ~AMateria(void);

		AMateria&			operator=(const AMateria& rightSide);
		
		const std::string&	getType(void) const;

		virtual AMateria*	clone(void) const = 0;
		virtual void		use(ICharacter& target);

	protected:
		std::string	type;
};

#endif // !AMATERIA_HPP
