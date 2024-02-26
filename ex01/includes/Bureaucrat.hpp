/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:51:54 by motoko            #+#    #+#             */
/*   Updated: 2024/02/26 14:36:30 by motoko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

class Form;

#define RESET	"\033[0m"
#define RED 	"\033[31m"
#define GREEN	"\033[32m"
#define BLUE	"\033[94m"
#define YELLOW	"\033[93m"
#define MAGENTA	"\033[95m"

class	Bureaucrat {
	public:
		Bureaucrat();	
		Bureaucrat(std::string name, int grade);	
		Bureaucrat(Bureaucrat const &src);	
		Bureaucrat& operator=(Bureaucrat const &src);
		~Bureaucrat();	

		void		signForm(Form &form);

		void		incrementGrade();
		void		decrementGrade();

		std::string getName() const;
		int			getGrade() const;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("<Bureaucrate> Grade too high");
				}
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("<Bureaucrate> Grade too low");
				}
		};

	private:
		std::string	_name;
		int			_grade;	
};

std::ostream & operator<<(std::ostream & o, Bureaucrat & rhs);

#endif
