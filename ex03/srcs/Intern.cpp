/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:18:12 by motoko            #+#    #+#             */
/*   Updated: 2024/03/01 14:26:56 by motoko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(Intern const &src) {
	std::cout << "Intern constructor by copy called" << std::endl;
	*this = src; 
}

Intern&	Intern::operator=(Intern const &src) {
	std::cout << "Intern operator= constructor called" << std::endl;
	if (this != &src) {}
	return (*this);
}

Intern::~Intern() {
	std::cout << "Intern destructor called" << std::endl;
}

int     find_index_form(std::string form_name)
 {
	const char *forms[] = {"Shrubbery", "robotomy request", "presidential pardon"};
 
     for (int i = 0; i < 3; i++)
     {
         if (forms[i] == form_name)
             return (i);
     }
     return (-1);
}

AForm*	Intern::makeForm(std::string form_name, std::string target_name) {
	std::cout << "Intern creates " << form_name << std::endl;	
	
	AForm *form = NULL;
	int	form_index = find_index_form(form_name);

	switch (form_index) 
	{
		case 0:
			form = new Shrubbery(target_name, 145, 137);	
			break;
		case 1:
			form = new RobotomyRequestForm(target_name, 72, 45);	
			break;
		case 2:
			form = new PresidentialPardonForm(target_name, 72, 45);	
			break;
		default:
			std::cout << form_name << " doesn't exist !" << std::endl;
	}
	return (form);
}
