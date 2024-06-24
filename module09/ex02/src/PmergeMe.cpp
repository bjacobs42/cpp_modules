/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 23:43:38 by bjacobs           #+#    #+#             */
/*   Updated: 2024/03/28 00:21:45 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {}
PmergeMe::PmergeMe(const PmergeMe& source) { *this = source; }
PmergeMe::~PmergeMe(void) {}

PmergeMe&	PmergeMe::operator=(const PmergeMe& rightSide) {
	if (this != &rightSide)
		return (*this);
	return (*this);
}

static void	merge(std::vector<unsigned int>& leftVector,
		std::vector<unsigned int>& rightVector, 
		std::vector<unsigned int>& origin) {
	unsigned int	leftSize = leftVector.size();
	unsigned int	rightSize = rightVector.size();
	unsigned int	i = 0, leftIndex = 0, rightIndex = 0;

	while (leftIndex < leftSize && rightIndex < rightSize) {
		if (leftVector[leftIndex] <= rightVector[rightIndex]) {
			origin[i] = leftVector[leftIndex];
			++leftIndex;
		}
		else {
			origin[i] = rightVector[rightIndex];
			++rightIndex;
		}
		++i;
	}
	while (leftIndex < leftSize) {
		origin[i] = leftVector[leftIndex];
		++leftIndex;
		++i;
	}
	while (rightIndex < rightSize) {
		origin[i] = rightVector[rightIndex];
		++rightIndex;
		++i;
	}
}

static void	merge(std::list<unsigned int>& leftList,
		std::list<unsigned int>& rightList, 
		std::list<unsigned int>& origin) {
	std::list<unsigned int>::iterator	leftIt, leftIte;
	std::list<unsigned int>::iterator	rightIt, rightIte;
	std::list<unsigned int>::iterator	originIt;

	originIt = origin.begin();
	leftIt = leftList.begin(); 
	leftIte = leftList.end();
	rightIt = rightList.begin(); 
	rightIte = rightList.end();
	while (leftIt != leftIte && rightIt != rightIte) {
		if (*leftIt <= *rightIt) {
			*originIt = *leftIt;
			++leftIt;
		}
		else {
			*originIt = *rightIt;
			++rightIt;
		}
		++originIt;
	}
	while (leftIt != leftIte) {
		*originIt = *leftIt;
		++leftIt;
		++originIt;
	}
	while (rightIt != rightIte) {
		*originIt = *rightIt;
		++rightIt;
		++originIt;
	}
}

void	PmergeMe::mergeSort(std::vector<unsigned int>& vector) {
	if (vector.size() < 2) return;

	unsigned int				middle = vector.size() / 2;
	std::vector<unsigned int>	leftVector(middle);
	std::vector<unsigned int>	rightVector(vector.size() - middle);

	unsigned int	i = 0;
	for (; i < middle; ++i)
		leftVector[i] = vector[i];
	for (; i < vector.size(); ++i)
		rightVector[i - middle] = vector[i];
	mergeSort(leftVector);
	mergeSort(rightVector);
	merge(leftVector, rightVector, vector);
}

void	PmergeMe::mergeSort(std::list<unsigned int>& list) {
	if (list.size() < 2) return;

	unsigned int						middle = list.size() / 2;
	std::list<unsigned int>				leftList(middle);
	std::list<unsigned int>				rightList(list.size() - middle);
	std::list<unsigned int>::iterator	it, originIt, ite;

	originIt = list.begin();
	ite = leftList.end();
	for (it = leftList.begin(); it != ite; ++it)
		*it = *originIt++;
	ite = rightList.end();
	for (it = rightList.begin(); it != ite; ++it)
		*it = *originIt++;
	mergeSort(leftList);
	mergeSort(rightList);
	merge(leftList, rightList, list);
}
