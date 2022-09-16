/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 21:57:42 by myukang           #+#    #+#             */
/*   Updated: 2022/07/11 23:24:06 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	table[0].key.assign("DEBUG");
	table[1].key.assign("INFO");
	table[2].key.assign("WARNING");
	table[3].key.assign("ERROR");
	table[0].fp = &Harl::debug;
	table[1].fp = &Harl::info;
	table[2].fp = &Harl::warning;
	table[3].fp = &Harl::error;
}

void Harl::debug(void)
{
	std::cout<<"[DEBUG]"<<std::endl;
	std::cout<<"I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"<<std::endl;
}

void Harl::info(void)
{
	std::cout<<"[INFO]"<<std::endl;
	std::cout<<"I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!"<<std::endl;
}

void Harl::warning(void)
{
	std::cout<<"[WARNING]"<<std::endl;
	std::cout<<"I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."<<std::endl;
}

void Harl::error(void)
{
	std::cout<<"[ERROR]"<<std::endl;
	std::cout<<"This is unacceptable! I want to speak to the manager now."<<std::endl;
}

void Harl::complain(std::string level)
{
	int	i;
	void (Harl::*print)(void);

	i = 0;
	while (i < 4)
	{
		if (level.compare(table[i].key) == 0)
		{
			print = table[i].fp;
			/*
			 * 멤버함수 포인터와 일반함수 포인터는 차이가 있음.
			 * this->*로 바인딩해야하는 이유는 함수포인터에게는 this가 없음.
			 * 함수를 찾아낼 객체를 모르기때문에 this를 bind해줘야함.
			 * */
			//(*print)();
			(this->*print)();
			return ;
		}
		i++;
	}
}
