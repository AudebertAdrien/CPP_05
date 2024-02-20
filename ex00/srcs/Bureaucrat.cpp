/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:51:33 by motoko            #+#    #+#             */
/*   Updated: 2024/02/20 18:23:26 by motoko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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

std::string	Bureaucrat::getName() {
	return (_name);
}

int	Bureaucrat::getGrade() {
	return (_grade);
}

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

std::ostream & operator<<(std::ostream & o, Bureaucrat & rhs) {
	o << GREEN << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << RESET;
	return (o);
}
