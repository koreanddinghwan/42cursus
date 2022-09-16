/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 03:32:14 by myukang           #+#    #+#             */
/*   Updated: 2022/07/25 02:34:13 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(int ac, char **av)
{
	Intern test;
	Form* tmp;
	Bureaucrat man("HI!!", 5);

	if (ac != 2)
		return 0;
	try {
		tmp = test.makeForm(av[1], "TEST1");
		std::cout<<*tmp<<std::endl;
		man.executeForm(*tmp);
		free(tmp);
	} catch (std::exception &e)
	{
		std::cout<<e.what()<<std::endl;
	}
	return 0;
}
