/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 01:35:10 by bjacobs           #+#    #+#             */
/*   Updated: 2024/03/05 01:52:54 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Serializer.hpp"

int	main(void) {

	Data		data;
	Data*		deserializedData;
	uintptr_t	rawData;

	rawData = Serializer::serialize(&data);
	std::cout << "Variable address: " << &data << ", serialized address: " << rawData << std::endl;
	deserializedData = Serializer::deserialize(rawData);
	std::cout << "Variable address: " << &data << ", deserialized address: " << deserializedData << std::endl
			  << "Variable data: " << data << std::endl
			  << "Deserialized data: " << *deserializedData << std::endl;
	return (0);
}
