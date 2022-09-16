/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:50:13 by myukang           #+#    #+#             */
/*   Updated: 2022/07/07 16:22:56 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::announce(void) const
{
	std::cout<<name<<": "<<"BraiiiiiiinnnzzzZ..."<<std::endl;
}

Zombie::Zombie(std::string name) : name(name)
{}

Zombie::Zombie(void) : name("NoNamed")
{}

Zombie::~Zombie(void)
{
	std::cout<<"Destructor Called by ["<<name<<"]"<<std::endl;
}

Zombie *newZombie(std::string name)
{
	Zombie *rtn;

	rtn = new Zombie(name);
	return (rtn);
}

void randomChump(std::string name)
{
	Zombie temp(name);

	temp.announce();
}
