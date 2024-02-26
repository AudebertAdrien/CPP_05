/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:06:50 by motoko            #+#    #+#             */
/*   Updated: 2024/02/26 14:27:50 by motoko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() {
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	std::cout << "Form constructor with params called" << std::endl;
	_isSigned = false;
}

Form::Form(Form const &src) {
	std::cout << "Form constructor by copy called" << std::endl;
	*this = src; 
}

Form&	Form::operator=(Form const &src) {
	std::cout << "Form operator= constructor called" << std::endl;
	if (this != &src) {}
	return (*this);
}

Form::~Form() {
	std::cout << "Form destructor called" << std::endl;
}

void	Form::beSigned(Bureaucrat const &bc) {
	std::cout << "Form beSigned called" << std::endl;

	Form::GradeTooLowException errMsg;

	if (bc.getGrade() <= this->_gradeToSign)
	{
		this->_isSigned = true;
		this->_signedBy = bc.getName();
	}
	else
		throw errMsg; 
}

/* == display == */
std::ostream & operator<<(std::ostream & o, Form & rhs) {
	o << GREEN 
		<< rhs.getName() << ":" 
		<< "\n - getGradeToSign: " << rhs.getGradeToSign()
		<< "\n - getGradeToExecute: " << rhs.getGradeToExecute() 
		<< RESET;
	return (o);
}

/* == getter == */
std::string	Form::getName() const {
	return (_name);
}

int	Form::getGradeToSign() const {
	return (_gradeToSign);
}

int	Form::getGradeToExecute() const {
	return (_gradeToExecute);
}

bool	Form::getIsSigned() const {
	return (_isSigned);
}

std::string	Form::getSignedBy() const {
	return (_signedBy);
}
