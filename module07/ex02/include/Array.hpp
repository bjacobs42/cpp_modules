/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 03:49:16 by bjacobs           #+#    #+#             */
/*   Updated: 2024/05/20 17:27:47 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <typename T>
class Array {

	private:
		size_t		_size;
		T*			_array;

	public:
		Array(void)
			: _size(0), _array(new T [_size]) {}
		Array(const size_t& n) : _size(n), _array(new T [_size]) {
			for (size_t i = 0; i < n; ++i)
				_array[i] = 0;
		}
		Array(const Array<T>& source)
			: _size(source._size), _array(new T [_size]) { *this = source; }
		~Array(void) { delete [] _array; }

		Array<T>&		operator=(const Array<T>& rightSide) {

			if (this == &rightSide)
				return (*this);
			if (_size != rightSide._size) {

				delete [] _array;
				_array = new T [rightSide._size];
				_size = rightSide._size;
			}
			for (size_t i = 0; i < _size; i++) {
				(*this)[i] = rightSide[i];
			}
			return (*this);
		}

		T&				operator[](size_t index) const {

			if (index >= _size)
				throw Array::outOfBounds();
			return (_array[index]);
		}
		
		size_t	size(void) const { return (_size); }


		class outOfBounds : public std::exception {

			public:
				virtual const char* what() const throw() {
					return ("Buffer overflow");
				}
		};
};
template <typename T>
std::ostream&	operator<<(std::ostream& outStream, const Array<T>& rightSide) {

	unsigned int	i;

	if (!rightSide.size()) {

		outStream << "{ }";
		return (outStream);
	}
	outStream << "{ ";
	for (i = 0; i + 1 < rightSide.size(); i++)
		outStream << rightSide[i] << ", ";
	outStream << rightSide[i] << " }";
	return (outStream);
};

#endif // !ARRAY_HPP
