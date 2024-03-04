/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:00:06 by motoko            #+#    #+#             */
/*   Updated: 2024/03/04 14:23:33 by motoko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string name, int gradeToSign, int gradeToExecute) : AForm(name, gradeToSign, gradeToExecute) {
	std::cout << "RobotomyRequestForm constructor with params called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : AForm(src.getName(), src.getGradeToSign(), src.getGradeToExecute()) {
	std::cout << "RobotomyRequestForm constructor by copy called" << std::endl;
	*this = src; 
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm const &src) {
	std::cout << "RobotomyRequestForm operator= constructor called" << std::endl;
	if (this != &src) {}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void	RobotomyRequestForm::execute(Bureaucrat const &bc) {
	std::cout << "RobotomyRequestForm execute called" << std::endl;

	RobotomyRequestForm::GradeTooLowException errMsg;

	if (bc.getGrade() < this->getGradeToExecute())
	{
		int	randNumber;

		std::srand(time(NULL));
		randNumber = std::rand() % 100 + 1;
		if (randNumber <= 50 )
			std::cout << YELLOW << this->getName() << " has been robotomized!" << RESET << std::endl;
		else
			std::cout << MAGENTA << "Fail to robotomized " << this->getName() << RESET << std::endl;
	}
	else 
		throw errMsg; 
}
