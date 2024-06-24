/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 02:32:30 by bjacobs           #+#    #+#             */
/*   Updated: 2024/05/14 20:43:18 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>

class Base { public: virtual ~Base(void) {} };
class A : public Base {};
class B : public Base {};
class C : public Base {};

Base*	generate(void) {

	std::srand(std::time(NULL));
	switch (std::rand() % 3) {
	
		case 0:
			return (new A);
	
		case 1:
			return (new B);

		default:
			return (new C);
	}
}

void	identify(Base* p) {

	if (dynamic_cast<A*>(p))
		std::cout << "Base object is an A class" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Base object is a B class" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Base object is a C class" << std::endl;
	else
		std::cout << "Base object is unknown" << std::endl;
}

void	identify(Base& p) {

	try {
		if (&dynamic_cast<A&>(p))
			std::cout << "Base object is an A class" << std::endl;
		return;
	}
	catch (...) {

	}
	try {
		if (&dynamic_cast<B&>(p))
			std::cout << "Base object is a B class" << std::endl;
		return;
	}
	catch (...) {

	}
	try {
		if (&dynamic_cast<C&>(p))
			std::cout << "Base object is a C class" << std::endl;
		return;
	}
	catch (...) {

	}
}

int	main(void) {

	Base*	random;

	random = generate();
	std::cout << "Identify pointer;" << std::endl;
	identify(random);
	std::cout << std::endl << "Identify reference;" << std::endl;
	identify(*random);
	delete random;
	return (0);
}
