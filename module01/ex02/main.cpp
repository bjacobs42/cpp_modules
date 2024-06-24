/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:47:27 by bjacobs           #+#    #+#             */
/*   Updated: 2023/07/12 17:01:25 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void) {

	std::string		str = "HI THIS IS BRAIN";
	std::string*	stringPTR = &str;
	std::string&	stringREF = str;

	std::cout << "String address: " << &str << std::endl
			  << "Address held by pointer : " << stringPTR << std::endl
			  << "Reference address: " << &stringREF << std::endl
			  << "String Value: " << str << std::endl
			  << "Value pointed to by pointer: " << *stringPTR << std::endl
			  << "Value pointed to by reference: " << stringREF << std::endl;
	return (0);
}
