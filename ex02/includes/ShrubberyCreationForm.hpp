/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:27:10 by motoko            #+#    #+#             */
/*   Updated: 2024/02/29 12:47:47 by motoko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_HPP
# define SHRUBBERY_HPP

#include <iostream>
#include <fstream>
#include <stdexcept>

#include "AForm.hpp"

class Shrubbery : public AForm {
	public:
		Shrubbery();
		Shrubbery(std::string name, int gradeToSign, int gradeToExecute);	
		Shrubbery(Shrubbery const &src);	
		Shrubbery& operator=(Shrubbery const &src);
		~Shrubbery();	

		void	execute(Bureaucrat const &bc);

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("Grade too low");
				}
		};
};

#endif
