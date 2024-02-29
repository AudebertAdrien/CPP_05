/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:51:54 by motoko            #+#    #+#             */
/*   Updated: 2024/02/29 13:08:30 by motoko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

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

class	AForm {
	public:
		AForm(std::string name, int gradeToSign, int gradeToExecute);	
		AForm(AForm const &src);	
		AForm& operator=(AForm const &src);
		~AForm();	

		void			beSigned(Bureaucrat const &bc);
		virtual void	execute(Bureaucrat const &bc) = 0;

		/* == setter == */
		void	setGradeToSign();
		void	setGradeToExecute();

		/* == getter == */
		std::string getName() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;
		bool		getIsSigned() const;
		std::string getSignedBy() const;

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("Grade too low");
				}
		};

	private:
		std::string	_name;
		int			_gradeToSign;	
		int			_gradeToExecute;	
		bool		_isSigned;
		std::string	_signedBy;
};

std::ostream & operator<<(std::ostream & o, AForm & rhs);

#endif
