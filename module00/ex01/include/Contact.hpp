/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: bjacobs <bjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/26 18:31:56 by bjacobs       #+#    #+#                 */
/*   Updated: 2023/07/10 16:59:01 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

enum e_name_type {

	FIRST,
	LAST,
	NICK
};

class Contact {

	public:

		std::string	name[3];
		std::string	phoneNumber;
		std::string	darkSecret;

		int			initContact(void);
};

#endif
