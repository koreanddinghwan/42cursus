/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:51:18 by myukang           #+#    #+#             */
/*   Updated: 2022/07/14 21:04:09 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"
FragTrap::FragTrap(void) : ClapTrap(100, 100, 30)
{
	std::cout<<"["<<name<<"]"<<"FragTrap Constructor Called"<<std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30)
{
	std::cout<<"["<<name<<"]"<<"FragTrap Constructor Called"<<std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy.name, copy.hp, copy.energy, copy.damage)
{
	std::cout<<"["<<name<<"]"<<"FragTrap copy Constructor Called"<<std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &target)
{
	this->name.assign(target.name);
	this->hp = target.hp;
	this->energy = target.energy;
	this->damage = target.damage;
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout<<"["<<name<<"]"<<"FragTrap Destructor Called"<<std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout<<"["<<name<<"]"<<"FragTrap highfives!!👏"<<std::endl;
}
