/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: bjacobs <bjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/26 15:19:56 by bjacobs       #+#    #+#                 */
/*   Updated: 2023/07/10 17:02:44 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

# define MAX_CONTACTS 8

class	PhoneBook {

	private:

		size_t	_cIndex;
		Contact	_contacts[MAX_CONTACTS];
	public:

		void	printContacts(void);
		void	printOne(Contact cInfo);
		void	searchContact(void);
		void	addContact(void);

		PhoneBook(void);
};

#endif
