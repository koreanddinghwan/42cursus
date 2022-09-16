/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:00:15 by myukang           #+#    #+#             */
/*   Updated: 2022/07/07 16:13:29 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	std::cout<<"객체 생명주기1"<<std::endl;
	Zombie::randomChump("zombie1");

	std::cout<<std::endl;

	std::cout<<"객체 생명주기2"<<std::endl;
	{
		Zombie zombie3;
		zombie3.announce();
	}
	std::cout<<std::endl;

	std::cout<<"객체 생명주기3"<<std::endl;
	Zombie *zombie2 = Zombie::newZombie("zombie2");
	zombie2->announce();
//	delete zombie2;

	std::cout<<std::endl;

	std::cout<<"객체 생명주기4"<<std::endl;
	{
		Zombie *zombie3 = Zombie::newZombie("zombie3");
		zombie3->announce();
		delete zombie3;//
	}
	delete zombie2;
	//zombie3->announce();
}
