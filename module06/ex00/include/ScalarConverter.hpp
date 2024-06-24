/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:31:34 by bjacobs           #+#    #+#             */
/*   Updated: 2024/02/27 20:19:42 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

typedef enum e_types {

	CHAR,
	INT,
	DOUBLE,
	FLOAT,
	UNKNOWN
}		t_types;

#include <string>

class ScalarConverter {

	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& source);
		~ScalarConverter(void);

		ScalarConverter&	operator=(const ScalarConverter& rightSide);

	public:
		static void	convert(const std::string& convertee);
};

#endif // !SCALARCONVERTER_HPP
