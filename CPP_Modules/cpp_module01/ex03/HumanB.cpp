/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 23:13:45 by myukang           #+#    #+#             */
/*   Updated: 2022/07/08 00:13:20 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name)
{
	this->weapon = NULL;
}

void HumanB::attack(void) const
{
	if (this->weapon == NULL)
	{
		std::cout<<name<<" don't have any arm"<<std::endl;
		return ;
	}
	std::cout<<name<<" attacks with their "<<weapon->getType()<<std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
