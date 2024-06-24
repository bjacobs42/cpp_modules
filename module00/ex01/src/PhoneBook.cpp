/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: bjacobs <bjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/26 19:09:25 by bjacobs       #+#    #+#                 */
/*   Updated: 2023/07/10 17:08:11 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>

#define CONTACT_CATEGORY_LINE "|    Index | FirstNa. | LastNam. | Nicknam. |"
#define	COLUMN_WIDTH 8

/* ----------------------- Utils Functions ----------------------- */

static std::string trimString(std::string s) {

	std::string	name;

	if (s.length() < COLUMN_WIDTH)
		return (s);
	name = s.substr(0, COLUMN_WIDTH);
	name.at(COLUMN_WIDTH - 1) = '.';
	return (name);
}

static size_t	biggestString(Contact cInfo) {

	size_t	max;
	size_t	nameLen;

	max = 0;
	for (int i = 0; i < 3; i++) {

		nameLen = cInfo.name[i].length();
		if (nameLen > max)
			max = nameLen;
	}
	nameLen = cInfo.phoneNumber.length();
	if (nameLen > max)
		max = nameLen;
	nameLen = cInfo.darkSecret.length();
	if (nameLen > max)
		max = nameLen;
	if (7 > max)
		return (7);
	return (max);
}

static void	printContent(const char *prefix, const char *content, size_t n) {

	std::cout << "| " << std::setfill(' ') << std::setw(14) << prefix << " | "
			  << std::setfill(' ') << std::setw(n) << content << " |" << std::endl;
}

/* ----------------------- Class Functions ----------------------- */

PhoneBook::PhoneBook(void) {

	this->_cIndex = 0;
}

void	PhoneBook::printContacts(void) {

	Contact		contact;
	std::string	borderLine (45u, '-');

	std::cout << borderLine << std::endl
			  << CONTACT_CATEGORY_LINE << std::endl
			  << borderLine << std::endl;
	for (size_t i = 0; i < MAX_CONTACTS && i < this->_cIndex; i++) {

		contact = this->_contacts[i];
		std::cout << "| " << std::setfill(' ') << std::setw(COLUMN_WIDTH) << i + 1 << " | "
				  << std::setfill(' ') << std::setw(COLUMN_WIDTH) << trimString(contact.name[FIRST]) << " | "
				  << std::setfill(' ') << std::setw(COLUMN_WIDTH) << trimString(contact.name[LAST]) << " | "
				  << std::setfill(' ') << std::setw(COLUMN_WIDTH) << trimString(contact.name[NICK]) << " |"
				  << std::endl;
	}
	std::cout << borderLine << std::endl;
}

void	PhoneBook::printOne(Contact cInfo) {

	std::string	borderLine;
	size_t		max;

	max = biggestString(cInfo);
	borderLine.append(21u + max, '-');
	std::cout << borderLine << std::endl;
	printContent("Category", "Content", max);
	std::cout << borderLine << std::endl;
	printContent("First Name", cInfo.name[FIRST].data(), max);
	printContent("Last Name", cInfo.name[LAST].data(), max);
	printContent("Nickname", cInfo.name[NICK].data(), max);
	printContent("Phone Number", cInfo.phoneNumber.data(), max);
	printContent("Darkest Secret", cInfo.darkSecret.data(), max);
	std::cout << borderLine << std::endl;
}

void	PhoneBook::searchContact(void) {

	std::string	buff;
	size_t		i;

	if (this->_cIndex < 1) {

		std::cout << "No contacts, try creating one!" << std::endl;
		return;
	}
	this->printContacts();
	while (true) {

		std::cout << "Enter index to display contact: ";
		if (!std::getline(std::cin, buff))
			return;
		i = atoi(buff.data());
		if (i < 1 || i > this->_cIndex || i > MAX_CONTACTS)
			std::cout << "Invalid index, try again" << std::endl;
		else
			break;
	}
	this->printOne(this->_contacts[i - 1]);
}

void	PhoneBook::addContact(void) {

	this->_contacts[this->_cIndex % MAX_CONTACTS].initContact();
	this->_cIndex++;
}
