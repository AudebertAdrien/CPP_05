/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:51:54 by motoko            #+#    #+#             */
/*   Updated: 2024/03/04 15:05:44 by motoko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <stdexcept>

#include "Bureaucrat.hpp"
class Bureaucrate;

#define RESET	"\033[0m"
#define RED 	"\033[31m"
#define GREEN	"\033[32m"
#define BLUE	"\033[94m"
#define YELLOW	"\033[93m"
#define MAGENTA	"\033[95m"
#define CYAN	"\033[96m"

class	Form {
	public:
		Form();	
		Form(std::string name, int gradeToSign, int gradeToExecute);	
		Form(Form const &src);	
		Form& operator=(Form const &src);
		~Form();	

		void		beSigned(Bureaucrat const &bc);

		/* == getter == */
		std::string getName() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;
		bool		getIsSigned() const;
		std::string getSignedBy() const;

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("<Form.hpp> Grade too low");
				}
		};

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("<Form.hpp> Grade too High");
				}
		};


	private:
		std::string	_name;
		int			_gradeToSign;	
		int			_gradeToExecute;	
		bool		_isSigned;
		std::string	_signedBy;
};

std::ostream & operator<<(std::ostream & o, Form & rhs);

#endif
