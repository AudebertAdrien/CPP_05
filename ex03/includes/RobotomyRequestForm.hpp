/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:59:41 by motoko            #+#    #+#             */
/*   Updated: 2024/02/29 14:04:54 by motoko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUEST_HPP
# define ROBOTOMYREQUEST_HPP

#include <iostream>
#include <cstdlib>

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	public:
		RobotomyRequestForm(std::string name, int gradeToSign, int gradeToExecute);	
		RobotomyRequestForm(RobotomyRequestForm const &src);	
		RobotomyRequestForm& operator=(RobotomyRequestForm const &src);
		~RobotomyRequestForm();	

		void	execute(Bureaucrat const &bc);

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("Grade too low");
				}
		};


	private:
};

#endif
