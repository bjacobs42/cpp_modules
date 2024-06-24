/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 00:26:34 by bjacobs           #+#    #+#             */
/*   Updated: 2024/02/21 20:46:22 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class AForm {

	private:
		const std::string	_name;
		const int			_signGrade;
		const int			_executeGrade;
		bool				_isSigned;
	
	public:
		AForm(void);
		AForm(const std::string& name, const int& signGrade, const int& execGrade);
		AForm(const AForm& source);
		virtual	~AForm(void) = 0;

		AForm&				operator=(const AForm& rightSide);

		std::string			getName(void) const;
		int					getSignGrade(void) const;
		int					getExecuteGrade(void) const;
		bool				getIsSigned(void) const;

		void				beSigned(const Bureaucrat& signer);
		virtual void		execute(const Bureaucrat& executor) const;

		class FormNotSigned : public std::exception {

			public:
				virtual const char* what() const throw() {
					return ("Form has not been signed");
				}
		};

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
std::ostream&		operator<<(std::ostream& outStream, const AForm& rightSide);

#endif // !FORM_HPP
