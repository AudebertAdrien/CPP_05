/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:51:54 by motoko            #+#    #+#             */
/*   Updated: 2024/02/20 18:24:41 by motoko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

#define RESET	"\033[0m"
#define RED 	"\033[31m"
#define GREEN	"\033[32m"

class	Bureaucrat {
	public:
		Bureaucrat();	
		Bureaucrat(std::string name, int grade);	
		Bureaucrat(Bureaucrat const &src);	
		Bureaucrat& operator=(Bureaucrat const &src);
		~Bureaucrat();	

		std::string getName();
		int			getGrade();
		void		incrementGrade();
		void		decrementGrade();

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("Too High");
				}
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("Too Low");
				}
		};

	private:
		std::string	_name;
		int			_grade;	
};

std::ostream & operator<<(std::ostream & o, Bureaucrat & rhs);

#endif
