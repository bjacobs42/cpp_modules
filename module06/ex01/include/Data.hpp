/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 06:38:03 by bjacobs           #+#    #+#             */
/*   Updated: 2024/03/05 01:49:10 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>

class Data {

	private:
		char	_c;
		int		_i;
		double	_d;
		float	_f;

	public:
		Data(void);
		Data(const char& c, const int& i, const double& d, const float& f);
		Data(const Data& source);
		~Data(void);

		Data&	operator=(const Data& rightSide);

		char	getChar(void) const;
		int		getInt(void) const;
		double	getDouble(void) const;
		float	getFloat(void) const;
};
std::ostream&	operator<<(std::ostream& outStream, const Data& rightSide);

#endif // !DATA_HPP
