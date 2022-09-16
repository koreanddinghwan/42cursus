/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:50:13 by myukang           #+#    #+#             */
/*   Updated: 2022/07/07 16:05:54 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name)
{}

Zombie::Zombie(void) : name("NoNamed")
{}

Zombie::~Zombie(void)
{
	std::cout<<"Destructor Called by ["<<name<<"]"<<std::endl;
}

void Zombie::announce(void) const
{
	std::cout<<name<<": "<<"BraiiiiiiinnnzzzZ..."<<std::endl;
}

Zombie *Zombie::newZombie(std::string name)
{
	Zombie *rtn;

	rtn = new Zombie(name);
	return (rtn);
}

void Zombie::randomChump(std::string name)
{
	Zombie temp(name);

	temp.announce();
}
