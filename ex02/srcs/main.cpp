/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:50:53 by motoko            #+#    #+#             */
/*   Updated: 2024/02/27 16:16:58 by motoko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void) {

	try {
        std::cout << "------ Grade Form with Bureaucrat------" << std::endl << std::endl;

		Bureaucrat	b1("B1", 3);
		Bureaucrat	b2("B2", 146);

		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;

		AForm	*s1 = new Shrubbery("Shrubbery form", 145, 137);	

		b1.signForm(*s1);
		b2.signForm(*s1);

		b1.executeForm(s1);
		b2.executeForm(s1);

	} catch (const std::exception& error) {
		std::cerr << RED << "Exception: " << error.what() << RESET << std::endl;
	}

	std::cout << std::string(50, '#') << std::endl;

	return (0);
}
