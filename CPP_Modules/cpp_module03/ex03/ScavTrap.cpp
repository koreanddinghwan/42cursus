/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:22:48 by myukang           #+#    #+#             */
/*   Updated: 2022/07/14 17:49:59 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap(100, 50, 20)
{
	std::cout<<"["<<name<<"]"<<"ScavTrap Constructor Called"<<std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20)
{
	std::cout<<"["<<name<<"]"<<"ScavTrap Constructor Called"<<std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &target)
{
	this->name.assign(target.name);
	this->hp = target.hp;
	this->energy = target.energy;
	this->damage = target.damage;
	return (*this);
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy.name, copy.hp, copy.energy, copy.damage)
{
	std::cout<<"["<<name<<"]"<<"ScavTrap copy Constructor Called"<<std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout<<"["<<name<<"]"<<"ScavTrap Destructor Called"<<std::endl;
}

void ScavTrap::guardGate(void)
{
	if (hp == 0)
		return ;
	if (energy == 0)
	{
		std::cout<<"["<<name<<"] needs more energy"<<std::endl;
		return ;
	}
	std::cout<<"["<<name<<"]"<<"is now in Gate keeper mode"<<std::endl;
	energy--;
}

void ScavTrap::attack(const std::string& target)
{
	if (hp == 0)
		return ;
	if (energy == 0)
	{
		std::cout<<"ScavTrap ["<<name<<"] can not attack, check energy"<<std::endl;
		return ;
	}
	std::cout<<"ScavTrap ["<<name<<"] attacks "<<"{"<<target<<"}, causing "<<damage<<" points of damage!"<<std::endl;
	this->energy--;
}
