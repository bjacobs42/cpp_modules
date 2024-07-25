/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 07:30:33 by bjacobs           #+#    #+#             */
/*   Updated: 2024/07/24 16:26:11 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <algorithm>
#include <iostream>

void	printStack(const int n)
{
	std::cout << n << " ";
}

int	main(void) {
	MutantStack<int>			mstack;
	MutantStack<int>			mstack2;
	MutantStack<int>::iterator	it;
	MutantStack<int>::iterator	ite;

	mstack.push(5);
	mstack.push(17);
	mstack.push(420);
	mstack.push(93);
	mstack.push(05);
	std::cout << "mstack top: " << mstack.top() << std::endl;
	std::cout << "mstack size: " << mstack.size() << std::endl;
	mstack.pop();
	std::cout << "mstack top after pop: " << mstack.top() << std::endl;
	std::cout << "mstack size after pop: " << mstack.size() << std::endl;

	it = mstack.begin();
	ite = mstack.end();
	++it; --it;
	std::cout << "mstack elements { ";
	std::for_each(it, ite, printStack);
	std::cout << "}" << std::endl;

	mstack2 = mstack;
	it = mstack2.begin();
	ite = mstack2.end();
	std::fill(it, ite, 42);
	std::cout << "mstack2 elements { ";
	std::for_each(it, ite, printStack);
	std::cout << "}" << std::endl;

	mstack2.swap(mstack);
	it = mstack2.begin();
	ite = mstack2.end();
	std::cout << "mstack2 elements after swap { ";
	std::for_each(it, ite, printStack);
	std::cout << "}" << std::endl;
	std::cout << "mstack elements after swap { ";
	std::for_each(mstack.begin(), mstack.end(), printStack);
	std::cout << "}" << std::endl;

	std::stack<int> s(mstack);
	return (0);
}
