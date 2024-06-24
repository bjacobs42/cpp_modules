/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 06:33:14 by bjacobs           #+#    #+#             */
/*   Updated: 2024/03/05 01:24:11 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <cstdint>
#include "Data.hpp"

class Serializer {

	private:
		Serializer(void);
		Serializer(const Serializer& source);
		~Serializer(void);

		Serializer&	operator=(const Serializer& rightSide);

	public:
		static uintptr_t	serialize(Data* pointer);
		static Data*		deserialize(uintptr_t raw);
};

#endif // !SERIALIZER_HPP
