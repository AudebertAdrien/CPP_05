/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:51:33 by motoko            #+#    #+#             */
/*   Updated: 2024/02/26 14:36:53 by motoko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() {
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
	std::cout << "Bureaucrat constructor with params called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) {
	std::cout << "Bureaucrat constructor by copy called" << std::endl;
	*this = src; 
}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const &src) {
	std::cout << "Bureaucrat operator= constructor called" << std::endl;
	if (this != &src) {}
	return (*this);
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destructor called" << std::endl;
}

/*
void	Bureaucrat::signForm(Form const &form) {
	std::cout << "Form signForm called" << form.getIsSigned() << std::endl;

	if (form.getIsSigned() && (this->getName() == form.getSignedBy()))
		std::cout << YELLOW << form.getSignedBy() << " signed " << form.getName() << RESET << std::endl;
	else
		std::cout << YELLOW << this->_name << " couldn’t sign " << form.getName() << " because " << "it is already sign" << RESET << std::endl;
}
*/

void	Bureaucrat::signForm(Form &form) {
	try {
		form.beSigned(*this);
		std::cout << YELLOW << this->_name << " signed " << form.getName() << RESET << std::endl;
	} catch (std::exception &e) {
		std::cout << YELLOW << this->_name << " couldn’t sign " << form.getName() << " because " << e.what() << RESET << std::endl;
	}
}


/* == check grade == */
void Bureaucrat::incrementGrade() {
	std::cout << "Bureaucrate increment grade" << std::endl;
	Bureaucrat::GradeTooHighException error;

	if (_grade - 1 < 1)
		throw error;
	else
		_grade--;
}

void Bureaucrat::decrementGrade() {
	std::cout << "Bureaucrate decrement grade" << std::endl;
	Bureaucrat::GradeTooHighException error;

	if (_grade + 1 > 150)
		throw error;
	else
		_grade++;
}

/* == display == */
std::ostream & operator<<(std::ostream & o, Bureaucrat & rhs) {
	o << MAGENTA << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << RESET;
	return (o);
}

/* == getter == */
std::string	Bureaucrat::getName() const {
	return (_name);
}

int	Bureaucrat::getGrade() const {
	return (_grade);
}

