/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 00:30:17 by myukang           #+#    #+#             */
/*   Updated: 2022/07/07 01:47:17 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook	phonebook;
	std::string	cmd;

	while (1)
	{
		std::cout<<"*****************"<<std::endl;
		std::cout<<"===Phone  Book==="<<std::endl;
		std::cout<<"====operation===="<<std::endl;
		std::cout<<"*1->ADD=========="<<std::endl;
		std::cout<<"*2->SEARCH======="<<std::endl;
		std::cout<<"*3->EXIT========="<<std::endl;
		std::cout<<"================="<<std::endl;
		std::getline(std::cin, cmd);
		if (std::cin.eof())
		{
			std::cin.clear();
			clearerr(stdin);
			continue ;
		}
		if (cmd.compare("ADD") == 0)
			phonebook.add();
		else if (cmd.compare("SEARCH") == 0)
			phonebook.search();
		else if (cmd.compare("EXIT") == 0)
			phonebook._exit();
		else
			std::cout<<"항상 사용자의 입력을 믿지 마세요...그래서 이 입력은 무시됩니다."<<std::endl;
		std::cin.clear();
		clearerr(stdin);
	}
	return (0);
}
