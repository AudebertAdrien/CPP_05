/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:17:19 by motoko            #+#    #+#             */
/*   Updated: 2024/03/04 14:13:26 by motoko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include "AForm.hpp"

class Intern {
	public:
		Intern();
		Intern(Intern const &src);	
		Intern& operator=(Intern const &src);
		~Intern();	

		AForm*	makeForm(std::string form_name, std::string target_name);
};

#endif
