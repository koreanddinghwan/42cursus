/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 00:34:58 by myukang           #+#    #+#             */
/*   Updated: 2022/07/14 14:45:00 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

int	Contact::is_empty(std::string str) const
{
	int			i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 33 && str[i] <= 126)
			return (0);
		i++;
	}
	return (1);
}

void Contact::set_string(std::string &obj, const char *str)
{
	std::cout<<str<<std::endl<<">";
	while (1)
	{
		std::getline(std::cin, obj);
		if (std::cin.eof() || is_empty(obj))
		{
			std::cout<<"***다시 입력***"<<std::endl<<">";
			std::cin.clear();
			clearerr(stdin);
			continue ;
		}
		else
			break ;
	}
}

void Contact::make_contact(void)
{
	set_string(first_name, "성을 입력하세요");
	set_string(last_name, "이름을 입력하세요");
	set_string(nick_name, "별명을 입력하세요");
	set_string(phone_number, "전화번호를 입력하세요");
	set_string(darkest_secret, "개인정보를 입력하세요");
}

const std::string Contact::get_first_name(std::string &buffer) const
{
	if (first_name.length() > 10)
		buffer.assign(first_name, 0, 9).append(".");
	else
		buffer.assign(first_name);
	return (buffer);
}

const std::string Contact::get_last_name(std::string &buffer) const
{
	if (last_name.length() > 10)
		buffer.assign(last_name, 0, 9).append(".");
	else
		buffer.assign(last_name);
	return (buffer);
}

const std::string Contact::get_nick_name(std::string &buffer) const
{
	if (nick_name.length() > 10)
		buffer.assign(nick_name, 0, 9).append(".");
	else
		buffer.assign(nick_name);
	return (buffer);
}

void Contact::printall(void) const
{
	std::cout<<"성"<<first_name<<std::endl;
	std::cout<<"이름"<<last_name<<std::endl;
	std::cout<<"별명"<<nick_name<<std::endl;
	std::cout<<"전화번호"<<phone_number<<std::endl;
	std::cout<<"개인정보"<<darkest_secret<<std::endl;
}
