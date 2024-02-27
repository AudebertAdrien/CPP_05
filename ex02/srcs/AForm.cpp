/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:06:50 by motoko            #+#    #+#             */
/*   Updated: 2024/02/27 15:19:33 by motoko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() {
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	std::cout << "AForm constructor with params called" << std::endl;
	_isSigned = false;
}

AForm::AForm(AForm const &src) {
	std::cout << "AForm constructor by copy called" << std::endl;
	*this = src; 
}

AForm&	AForm::operator=(AForm const &src) {
	std::cout << "AForm operator= constructor called" << std::endl;
	if (this != &src) {}
	return (*this);
}

AForm::~AForm() {
	std::cout << "AForm destructor called" << std::endl;
}

void	AForm::beSigned(Bureaucrat const &bc) {
	std::cout << "AForm beSigned called" << std::endl;

	AForm::GradeTooLowException errMsg;

	if (bc.getGrade() < this->_gradeToSign)
	{
		this->_isSigned = true;
		this->_signedBy = bc.getName();
	}
	else
		throw errMsg; 
}

/* == display == */
std::ostream & operator<<(std::ostream &o, AForm &rhs) {
	o << GREEN 
		<< rhs.getName() << ":" 
		<< "\n - getGradeToSign: " << rhs.getGradeToSign()
		<< "\n - getGradeToExecute: " << rhs.getGradeToExecute() 
		<< RESET;
	return (o);
}

/* == setter == */
void	AForm::setGradeToSign() {
	this->_gradeToSign = 0;
}

void	AForm::setGradeToExecute() {
	this->_gradeToExecute = 0;
}

/* == getter == */
std::string	AForm::getName() const {
	return (_name);
}

int	AForm::getGradeToSign() const {
	return (_gradeToSign);
}

int	AForm::getGradeToExecute() const {
	return (_gradeToExecute);
}

bool	AForm::getIsSigned() const {
	return (_isSigned);
}

std::string	AForm::getSignedBy() const {
	return (_signedBy);
}
