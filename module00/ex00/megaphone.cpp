/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: bjacobs <bjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/23 17:34:23 by bjacobs       #+#    #+#                 */
/*   Updated: 2023/09/28 16:47:55 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

static void	stou(char *s) {

	for (int i = 0; s[i]; i++)
		s[i] = std::toupper(s[i]);
}

int	main(int ac, char **av) {

	if (ac < 2)
		std::cout << " * LOUD AND UNBEARABLE NOISE * ";
	else {

		for (int i = 1; av[i]; i++) {
			stou(av[i]);
			std::cout << av[i];
		}
	}
	std::cout << std::endl;
	return (0);
}
