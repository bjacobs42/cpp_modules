/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 23:32:56 by bjacobs           #+#    #+#             */
/*   Updated: 2024/03/28 00:21:39 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <list>
#include <vector>
#include <iostream>

class PmergeMe {
	private:
		PmergeMe(void);
		PmergeMe(const PmergeMe& source);
		~PmergeMe(void);

		PmergeMe&	operator=(const PmergeMe& rightSide);

	public:

		template <typename Cont>
		static bool	initCont(char** args, Cont& container) {
			for (std::size_t i = 0; args[i]; ++i) {
				for (std::size_t j = 0; args[i][j]; ++j) {
					if (std::isspace(args[i][j]))
						continue;
					try {
						container.push_back(std::stoi(&args[i][j]));
					}
					catch (const std::exception& e) {
						std::cout << "Error" <<  std::endl;
						return (false);
					}
					while (std::isdigit(args[i][j]) && args[i][j+1]) {
						++j;
					}
				}
			}
			if (container.empty()) {
				std::cout << "Error" <<  std::endl;
				return (false);
			}
			return (true);
		}

		static void	mergeSort(std::vector<unsigned int>& vector);
		static void	mergeSort(std::list<unsigned int>& list);
};

