/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 00:26:34 by bjacobs           #+#    #+#             */
/*   Updated: 2024/02/03 23:00:54 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Form {

	private:
		const std::string	_name;
		const int			_signGrade;
		const int			_executeGrade;
		bool				_isSigned;
	
	public:
		Form(void);
		Form(const std::string& name, const int& signGrade, const int& execGrade);
		Form(const Form& source);
		~Form(void);

		Form&				operator=(const Form& rightSide);

		std::string			getName(void) const;
		int					getSignGrade(void) const;
		int					getExecuteGrade(void) const;
		bool				getIsSigned(void) const;

		void				beSigned(const Bureaucrat& signer);

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
std::ostream&		operator<<(std::ostream& outStream, const Form& rightSide);

#endif // !FORM_HPP
