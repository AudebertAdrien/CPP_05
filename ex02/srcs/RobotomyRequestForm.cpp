/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:00:06 by motoko            #+#    #+#             */
/*   Updated: 2024/02/29 13:54:42 by motoko           ###   ########.fr       */
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
		int	randNumber;

		std::srand(time(NULL));
		randNumber = std::rand() % 100 + 1;
		//std::cout << "randNumber === " << randNumber << std::endl;
		if (randNumber <= 50 )
			std::cout << YELLOW << bc.getName() << " has been robotomized!" << RESET << std::endl;
		else
			std::cout << MAGENTA << "Fail to robotomized!" << bc.getName() << RESET << std::endl;
	}
	else 
		throw errMsg; 
}
