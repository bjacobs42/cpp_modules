/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: bjacobs <bjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/23 20:52:19 by bjacobs       #+#    #+#                 */
/*   Updated: 2023/07/10 17:02:30 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

int	main(void) {

	PhoneBook	phoneBook;
	std::string	buff;

	while (true) {

		std::cout << "Enter command: ";
		std::getline(std::cin, buff);
		if (!buff.compare(0, 5, "EXIT"))
			break;
		else if (!buff.compare(0, 4, "ADD"))
			phoneBook.addContact();
		else if (!buff.compare(0, 7, "SEARCH"))
			phoneBook.searchContact();
		if (!std::cin.good()) {

			std::cout << std::endl;
			break;
		}
	}
	return (EXIT_SUCCESS);
}
