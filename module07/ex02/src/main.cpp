/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 04:46:50 by bjacobs           #+#    #+#             */
/*   Updated: 2024/06/14 18:22:16 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Array.hpp"
#include <ctime>

#define	DEFAULT_SIZE 10

static size_t	initSize(const int ac, const char **av) {
	if (ac != 2)
		return  (DEFAULT_SIZE);
	if (av[1][0] == '-') {
		std::cout << "negative number: " << av[1] << ", using default size (" << DEFAULT_SIZE << ")" << std::endl;
		return  (DEFAULT_SIZE);
	}
	try {
		return (std::stoi(av[1]));
	}
	catch (const std::exception &e) {
		std::cout << "invalid integer: " << av[1] << ", using default size (" << DEFAULT_SIZE << ")" << std::endl;
		return  (DEFAULT_SIZE);
	}
}

int	main(int const ac, const char **av) {
	size_t			size = initSize(ac, av);
	Array<int>		array(size);
	Array<int>		temp;

	std::srand(std::time(NULL));
	std::cout << "uninitialized array: " << array << std::endl;
	for (size_t i = 0; i < size; i++) {

		array[i] = std::rand() % 33;
	}
	std::cout << "initialized array: " << array << std::endl;

	try {

		std::cout << "Accessing index 4 in array (buffer size: " << array.size() << ")" << std::endl;
		array[4] = 5;
	}
	catch (Array<int>::outOfBounds& e) {
	
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "Empty array: " << temp << std::endl;
	temp = array;
	std::cout << "Filled array: " << temp << std::endl;
	return (0);
}

/* ---------------------------[ SUBJECT MAIN ]--------------------------- */

//#define MAX_VAL 750
//int main(int, char**)
//{
//	Array<int> numbers(MAX_VAL);
//	int* mirror = new int[MAX_VAL];
//	srand(time(NULL));
//	for (int i = 0; i < MAX_VAL; i++)
//	{
//		const int value = rand();
//		numbers[i] = value;
//		mirror[i] = value;
//	}
//	//SCOPE
//	{
//		Array<int> tmp = numbers;
//		Array<int> test(tmp);
//	}
//
//	for (int i = 0; i < MAX_VAL; i++)
//	{
//		if (mirror[i] != numbers[i])
//		{
//			std::cerr << "didn't save the same value!!" << std::endl;
//			return 1;
//		}
//	}
//	try
//	{
//		numbers[-2] = 0;
//	}
//	catch(const std::exception& e)
//	{
//		std::cerr << e.what() << '\n';
//	}
//	try
//	{
//		numbers[MAX_VAL] = 0;
//	}
//	catch(const std::exception& e)
//	{
//		std::cerr << e.what() << '\n';
//	}
//
//	for (int i = 0; i < MAX_VAL; i++)
//	{
//		numbers[i] = rand();
//	}
//	delete [] mirror;//
//	return 0;
//	}
