/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 00:45:57 by bjacobs           #+#    #+#             */
/*   Updated: 2023/08/13 22:03:43 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

class Brain {

	public:
		Brain(void);
		Brain(const Brain& source);
		~Brain(void);

		Brain&	operator=(const Brain& rightSide);

		std::string	ideas[100];
};

#endif // !BRAIN_HPP
