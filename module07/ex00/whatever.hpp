/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 01:10:29 by bjacobs           #+#    #+#             */
/*   Updated: 2024/03/06 01:17:20 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATES_HPP
# define TEMPLATES_HPP

template <typename type>
const type&	max(const type& x, const type& y) {

	return (x > y ? x : y);
}

template <typename type>
const type&	min(const type& x, const type& y) {

	return (x < y ? x : y);
}

template <typename type>
void	swap(type& a, type& b) {

	type	temp = a;

	a = b;
	b = temp;
}

#endif // !TEMPLATES_HPP
