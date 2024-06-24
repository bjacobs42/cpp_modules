/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 02:26:27 by bjacobs           #+#    #+#             */
/*   Updated: 2024/03/06 03:37:01 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>

template <typename T, typename returnT = void>
void	iter(T* array, const size_t& len, returnT (*func)(T&)) {

	for (size_t i = 0; i < len; i++)
		func(array[i]);
}

#endif // !ITER_HPP
