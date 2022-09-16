/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 03:32:14 by myukang           #+#    #+#             */
/*   Updated: 2022/07/25 01:32:38 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void test1(void)
{
	try {
	Bureaucrat test1("pam", 2);
	Form form("tester", 1, 10);
	test1.signForm(form);
	test1.increGrade();
	test1.signForm(form);

	} catch (std::exception &e)
	{
		std::cout<<e.what()<<std::endl;
	}
}

void test2(void)
{
	try {
	Bureaucrat test2("map", 2);
	Form form("tester1", 3, 10);
	Form form2("tester2", 3, 10);

	test2.signForm(form);
	test2.decreGrade();
	test2.decreGrade();
	test2.signForm(form2);
	} catch (std::exception &e)
	{
		std::cout<<e.what()<<std::endl;
	}
}

int main(void)
{
//	Bureaucrat test("Bob", 0);

	test1();
	std::cout<<std::endl<<std::endl<<std::endl;
	test2();
	std::cout<<std::endl<<std::endl<<std::endl;
	return 0;
}
