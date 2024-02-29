/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:51:33 by motoko            #+#    #+#             */
/*   Updated: 2024/02/29 12:52:58 by motoko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

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

void	Bureaucrat::signForm(AForm &form) {
	std::cout << "Bureaucrate signForm beSigned called" << std::endl;

	try {
		form.beSigned(*this);
		std::cout << YELLOW << this->_name << " signed " << form.getName() << RESET << std::endl;
	} catch (std::exception &e) {
		std::cout << YELLOW << this->_name << " couldn’t sign " << form.getName() << " because " << e.what() << RESET << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm *form) {
	std::cout << "Bureaucrate executeForm beSigned called" << std::endl;

	try {
		form->execute(*this);
		std::cout << YELLOW << this->_name << " execute " << form->getName() << RESET << std::endl;
	} catch (std::exception &e) {
		std::cout << YELLOW << this->_name << " couldn’t execute " << form->getName() << " because " << e.what() << RESET << std::endl;
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


