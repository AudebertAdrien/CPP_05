/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:56:17 by motoko            #+#    #+#             */
/*   Updated: 2024/02/29 14:32:22 by motoko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string name, int gradeToSign, int gradeToExecute) : AForm(name, gradeToSign, gradeToExecute) {
	std::cout << "PresidentialPardonForm constructor with params called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : AForm(src.getName(), src.getGradeToSign(), src.getGradeToExecute()) {
	std::cout << "PresidentialPardonForm constructor by copy called" << std::endl;
	*this = src; 
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const &src) {
	std::cout << "PresidentialPardonForm operator= constructor called" << std::endl;
	if (this != &src) {}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

void	PresidentialPardonForm::execute(Bureaucrat const &bc) {
	std::cout << "PresidentialPardonForm execute called" << std::endl;

	PresidentialPardonForm::GradeTooLowException errMsg;

	if (bc.getGrade() < this->getGradeToExecute())
		std::cout << GREEN << this->getName() << " : Zaphod Beeblebrox pardon you ! " << std::endl;
	else 
		throw errMsg; 
}
