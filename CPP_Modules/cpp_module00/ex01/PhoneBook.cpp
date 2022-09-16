/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 22:09:49 by myukang           #+#    #+#             */
/*   Updated: 2022/07/11 14:51:03 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : size(0)
{}

int	PhoneBook::is_empty(std::string obj) const
{
	int			i;
	const char *str;

	str = obj.data();
	i = 0;
	while (str[i])
	{
		if (isprint(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int PhoneBook::exist_string(std::string obj) const
{
	int			i;
	const char *str;

	str = obj.data();
	i = 0;
	while (str[i])
	{
		if (isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void PhoneBook::add(void)
{
	if (size == 8)
		update();
	else
	{
		contacts[size].make_contact();
		size++;
	}
}

void PhoneBook::search(void) const
{
	std::string buffer;

	std::cout.setf(std::ios::right, std::ios::adjustfield);
	std::cout.setf(std::ios::showbase);
	for (int i = 0; i < size; i++)
	{
		std::cout<<"|";
		std::cout<<std::setw(10)<<i;
		std::cout<<"|";
		std::cout<<std::setw(10)<<contacts[i].get_first_name(buffer);
		std::cout<<"|";
		std::cout<<std::setw(10)<<contacts[i].get_last_name(buffer);
		std::cout<<"|";
		std::cout<<std::setw(10)<<contacts[i].get_nick_name(buffer);
		std::cout<<"|";
		std::cout<<std::endl;
	}
	std::cout.unsetf(std::ios::showbase);
	print_index();
}

void PhoneBook::_exit(void) const
{
	std::cout<<"프로그램 종료...."<<std::endl;
	exit(0);
}

void PhoneBook::update(void)
{
	for (int i = 0;i < 7; i++)
	{
		contacts[i] = contacts[i+1];
	}
	size--;
	add();
}

void PhoneBook::print_index(void) const
{
	std::string str;

	std::cout<<"인덱스로 상세정보 출력"<<std::endl;
	while (1)
	{
		std::getline(std::cin, str);
		if (std::cin.eof() || is_empty(str) || exist_string(str))
		{
			std::cout<<"***다시 입력***"<<std::endl;
			std::cin.clear();
			clearerr(stdin);
			continue ;
		}
		else
		{
			int	i;

			i = atoi(str.data());
			if (i >= size || i < 0)
			{
				std::cout<<"***다시 입력***"<<std::endl;
				std::cin.clear();
				clearerr(stdin);
				continue ;
			}
			else
				contacts[i].printall();
			break ;
		}
	}
}
