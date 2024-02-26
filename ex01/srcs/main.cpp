/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:50:53 by motoko            #+#    #+#             */
/*   Updated: 2024/02/26 14:35:06 by motoko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void) {

	try {
        std::cout << "------ Grade Form with Bureaucrat------" << std::endl << std::endl;

		Bureaucrat	b1("B1", 3);
		Bureaucrat	b2("B2", 6);

		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;

		Form		f1("Hiring form", 5, 10);	
		std::cout << f1 << std::endl;

		std::cout << BLUE << "isSigned: " << f1.getIsSigned() << RESET << std::endl;
		b1.signForm(f1);
		std::cout << BLUE << "isSigned: " << f1.getIsSigned() << RESET << std::endl;

		b2.signForm(f1);
		std::cout << BLUE << "isSigned: " << f1.getIsSigned() << RESET << std::endl;

		

	} catch (const std::exception& error) {
		std::cerr << RED << "Exception: " << error.what() << RESET << std::endl;
	}

	std::cout << std::string(50, '#') << std::endl;

	return (0);
}
