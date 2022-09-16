/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 03:32:14 by myukang           #+#    #+#             */
/*   Updated: 2022/07/25 02:14:32 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

void test1(void)
{
	Bureaucrat test1("pam", 2);
	Bureaucrat test2("map", 149);
	Form *ptr = new ShrubberyCreationForm("docs");

	try {
		test1.executeForm(*ptr);
		test2.executeForm(*ptr);
		test2.increGrade();
		test2.increGrade();
		test2.executeForm(*ptr);
	} catch (std::exception &e) {
		std::cout<<e.what()<<std::endl;
	}
	delete ptr;
}

void test2(void)
{
	Bureaucrat test3("myukang", 46);
	Form *ptr2 = new RobotomyRequestForm("docs");
	try {
		test3.executeForm(*ptr2);
		test3.increGrade();
		test3.executeForm(*ptr2);
		delete ptr2;
	} catch (std::exception &e) {
		std::cout<<e.what()<<std::endl;
		delete ptr2;
	}
}

void test3(void)
{
	Bureaucrat test4("6급 행정직", 6);
	Form *ptr = new PresidentialPardonForm("docs");
	try {
		test4.executeForm(*ptr);
		test4.increGrade();
		test4.executeForm(*ptr);
	} catch (std::exception &e) {
		std::cout<<e.what()<<std::endl;
	}
	delete ptr;
}

int main(void)
{
	test1();
	std::cout<<std::endl<<std::endl<<std::endl<<std::endl;
	test2();
	std::cout<<std::endl<<std::endl<<std::endl<<std::endl;
	test3();
	return 0;
}
