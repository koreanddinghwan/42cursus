/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 03:32:14 by myukang           #+#    #+#             */
/*   Updated: 2022/07/25 00:36:48 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void test1()
{
	try {
		Bureaucrat test("Bob", 0);
	} catch (std::exception &e)
	{
		std::cout<<e.what()<<std::endl;
	}
}

void test2()
{
	try {
		Bureaucrat test1("pam", 2);
		test1.increGrade();
		test1.increGrade();

		std::cout<<test1<<std::endl;
	} catch (std::exception &e)
	{
		std::cout<<e.what()<<std::endl;
	}
}

void test3(void)
{
	try {
		Bureaucrat test2("map", 149);

		test2.decreGrade();
		test2.decreGrade();
		std::cout<<test2<<std::endl;
	} catch (std::exception &e)
	{
		std::cout<<e.what()<<std::endl;
	}
}

void test4(void)
{
	try {
		Bureaucrat *test = new Bureaucrat("Malloced", 151);
		std::cout<<*test<<std::endl;
		delete test;
	} catch (std::exception &e) {
		std::cout<<e.what()<<std::endl;
	}
}

int main(void)
{
	test1();
		std::cout<<std::endl<<std::endl<<std::endl;
	test2();
		std::cout<<std::endl<<std::endl<<std::endl;
	test3();
		std::cout<<std::endl<<std::endl<<std::endl;
	test4();
	return 0;
}
