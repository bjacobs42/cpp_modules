/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyFind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 04:59:33 by bjacobs           #+#    #+#             */
/*   Updated: 2024/07/05 18:45:30 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>

template <typename Container>
const typename Container::iterator	easyFind(Container& hay, const int& needle)
{
	return (std::find(hay.begin(), hay.end(), needle));
}

#endif // !EASYFIND_HPP
