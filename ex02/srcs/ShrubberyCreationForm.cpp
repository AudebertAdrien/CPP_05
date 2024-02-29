/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:25:51 by motoko            #+#    #+#             */
/*   Updated: 2024/02/29 13:11:23 by motoko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

Shrubbery::Shrubbery(std::string name, int gradeToSign, int gradeToExecute) : AForm(name, gradeToSign, gradeToExecute) {
	std::cout << "Shrubbery constructor with params called" << std::endl;
}

Shrubbery::Shrubbery(Shrubbery const &src) : AForm(src.getName(), src.getGradeToSign(), src.getGradeToExecute()) {
	std::cout << "Shrubbery constructor by copy called" << std::endl;
	*this = src; 
}

Shrubbery&	Shrubbery::operator=(Shrubbery const &src) {
	std::cout << "Shrubbery operator= constructor called" << std::endl;
	if (this != &src) {}
	return (*this);
}

Shrubbery::~Shrubbery() {
	std::cout << "Shrubbery destructor called" << std::endl;
}

void	asciiTree(std::ofstream &ofs) {
    ofs << "    ^    " << std::endl;
    ofs << "   / \\   " << std::endl;
    ofs << "  /   \\  " << std::endl;
    ofs << " /     \\ " << std::endl;
    ofs << "/_______\\" << std::endl;
    ofs << "   |||   " << std::endl;
}

void	Shrubbery::execute(Bureaucrat const &bc) {
	std::cout << "Shrubbery execute called" << std::endl;

	Shrubbery::GradeTooLowException errMsg;

	if (bc.getGrade() < this->getGradeToExecute())
	{
		std::string outputFilename = std::string(bc.getName()) + "_shrubbery";
		std::ofstream ofs(outputFilename.c_str());
		if (!ofs.is_open())
		{
			std::cerr << "Error: unable to open file" << std::endl;
			return ;
		}
		asciiTree(ofs);
		ofs.close();
	}
	else 
		throw errMsg; 
}
