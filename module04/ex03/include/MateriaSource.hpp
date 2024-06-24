/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 23:46:02 by bjacobs           #+#    #+#             */
/*   Updated: 2023/08/17 00:52:11 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "AMateria.hpp"
# include "IMateriaSource.hpp"

# define MAX_MEMORY 4

class MateriaSource : public IMateriaSource {

	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource& source);
		virtual ~MateriaSource(void);

		MateriaSource&		operator=(const MateriaSource& rightSide);

		virtual void		learnMateria(AMateria* materia);
		virtual AMateria*	createMateria(const std::string& type);

	private:
		AMateria*	_memory[MAX_MEMORY];
};

#endif // !MATERIASOURCE_HPP
