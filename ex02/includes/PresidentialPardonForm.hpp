/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:56:32 by motoko            #+#    #+#             */
/*   Updated: 2024/02/29 14:09:43 by motoko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDON_HPP
# define PRESIDENTIALPARDON_HPP

#include <iostream>

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	public:
		PresidentialPardonForm(std::string name, int gradeToSign, int gradeToExecute);	
		PresidentialPardonForm(PresidentialPardonForm const &src);	
		PresidentialPardonForm& operator=(PresidentialPardonForm const &src);
		~PresidentialPardonForm();	

		void	execute(Bureaucrat const &bc);

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("Grade too low");
				}
		};
};

#endif
