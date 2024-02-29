/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:50:53 by motoko            #+#    #+#             */
/*   Updated: 2024/02/29 16:45:12 by motoko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void) {

	try {
        std::cout << "------ Grade Form with Bureaucrat------" << std::endl << std::endl;

		{
			Intern someRandomIntern;
			//AForm* rrf;
			someRandomIntern.makeForm("robotomy request", "Bender");
			//rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		}

		std::cout << std::string(50, '#') << std::endl;

		/*
		Bureaucrat	b1("B1", 3);
		Bureaucrat	b2("B2", 146);

		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;

		AForm	*s1 = new Shrubbery("Home", 145, 137);	
		AForm	*s2 = new RobotomyRequestForm("Dog", 72, 45);	
		AForm	*s3 = new PresidentialPardonForm("Theo", 72, 45);	

		b1.signForm(*s1);
		b2.signForm(*s1);

		std::cout << std::string(50, '#') << std::endl;

		b1.executeForm(s1);
		b2.executeForm(s1);

		std::cout << std::string(50, '#') << std::endl;

		b1.executeForm(s2);
		b2.executeForm(s2);

		std::cout << std::string(50, '#') << std::endl;

		b1.executeForm(s3);
		b2.executeForm(s3);
		*/

	} catch (const std::exception& error) {
		std::cerr << RED << "Exception: " << error.what() << RESET << std::endl;
	}

	std::cout << std::string(50, '#') << std::endl;

	return (0);
}
