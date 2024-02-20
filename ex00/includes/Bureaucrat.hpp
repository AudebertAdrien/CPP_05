/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:51:54 by motoko            #+#    #+#             */
/*   Updated: 2024/02/20 15:26:26 by motoko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class	Bureaucrat {
	public:
		Bureaucrat();	
		Bureaucrat(std::string name, int grade);	
		Bureaucrat(Bureaucrat const &src);	
		Bureaucrat& operator=(Bureaucrat const &src);
		~Bureaucrat();	
};
