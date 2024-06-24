/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:27:55 by bjacobs           #+#    #+#             */
/*   Updated: 2024/02/22 20:42:40 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"

typedef enum t_formIndex {
	
	SHRUBBERY,
	PARDON,
	ROBOTOMY,
	NOT_FOUND
} e_fI;

class Intern {

	public:
		Intern(void);
		~Intern(void);

		Intern&	operator=(const Intern& source);

		AForm*	makeForm(const std::string& formName, const std::string& target) const;
};

#endif // !INTERN_HPP
