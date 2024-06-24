/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 20:35:46 by bjacobs           #+#    #+#             */
/*   Updated: 2023/08/12 00:30:39 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <string>

class WrongAnimal {

	public:
		WrongAnimal(void);
		WrongAnimal(const std::string& type);
		WrongAnimal(const WrongAnimal& source);
		virtual ~WrongAnimal(void);

		WrongAnimal&	operator=(const WrongAnimal& rightSide);

		std::string		getType(void) const;
		void	makeSound(void) const;

	protected:
		std::string	type;
};

#endif // !WRONGANIMAL_HPP
