/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyFind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 04:59:33 by bjacobs           #+#    #+#             */
/*   Updated: 2024/03/08 06:36:31 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

template <typename Container>
const typename Container::iterator	easyFind(Container& hay, const int& needle) {

	typename Container::iterator	it;
	typename Container::iterator	ite;

	ite = hay.end();
	for (it = hay.begin(); it != ite; ++it) {

		if (static_cast<int>(*it) == needle)
			return (it);
	}
	return (ite);
}

#endif // !EASYFIND_HPP
