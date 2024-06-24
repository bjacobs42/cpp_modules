/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:57:35 by bjacobs           #+#    #+#             */
/*   Updated: 2024/02/03 23:36:25 by bjacobs          ###   ########.fr       */
/*                                                                           */
/* ************************************************************************** */

#ifndef BUEAUCRAT_HPP
# define BUEAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat {

	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat(void);
		Bureaucrat(const Bureaucrat& source);
		Bureaucrat(const std::string& name, const int& grade);
		~Bureaucrat(void);

		Bureaucrat&			operator=(const Bureaucrat& rightSide);

		std::string			getName(void) const;
		int					getGrade(void) const;

		void				incrementGrade(const int& amount);
		void				deincrementGrade(const int& amount);
		void				signForm(const std::string formName, bool gotSigned, std::string reason) const;

		class GradeTooLowException : public std::exception {

			public:
				virtual const char* what() const throw() {
					return ("Grade is too low");
				}
		};

		class GradeTooHighException : public std::exception {

			public:
				virtual const char* what() const throw() {
					return ("Grade is too high");
				}
		};
};
std::ostream&		operator<<(std::ostream& outStream, const Bureaucrat& rightSide);

#endif // !BUEAUCRAT_HPP
