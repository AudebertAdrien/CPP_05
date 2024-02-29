/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:00:06 by motoko            #+#    #+#             */
/*   Updated: 2024/02/29 13:09:21 by motoko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string name, int gradeToSign, int gradeToExecute) : AForm(name, gradeToSign, gradeToExecute) {
	std::cout << "RobotomyRequestForm constructor with params called" << std::endl;
}

void	RobotomyRequestForm::execute(Bureaucrat const &bc) {
	std::cout << "RobotomyRequestForm execute called" << std::endl;

	RobotomyRequestForm::GradeTooLowException errMsg;

	if (bc.getGrade() < this->getGradeToExecute())
	{
		std::cout << "test called" << std::endl;
	}
	else 
		throw errMsg; 
}
