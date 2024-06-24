/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 20:26:45 by bjacobs           #+#    #+#             */
/*   Updated: 2024/03/01 17:17:51 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

#include <string>

void	printImpossible(void);
void	printChar(const unsigned char c);
void	printDouble(const double d, int precision);
void	printFloat(const float f, int precision);

void	handleChar(const std::string& convertee);
void	handleInt(const std::string& convertee);
void	handleDouble(const std::string& convertee);
void	handleFloat(const std::string& convertee);

#endif // !UTILS_HPP
