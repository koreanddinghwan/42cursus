/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 14:28:14 by myukang           #+#    #+#             */
/*   Updated: 2022/07/14 17:35:26 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : name("Unknown"), hp(10), energy(10), damage(0)
{
	std::cout<<"["<<name<<"]"<<"ClapTrap Default Constructor Called"<<std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hp(10), energy(10), damage(0)
{
	std::cout<<"["<<name<<"]"<<"ClapTrap Constructor Called"<<std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy) : name(copy.name), hp(copy.hp), energy(copy.energy), damage(copy.damage)
{
	std::cout<<"["<<name<<"]"<<"ClapTrap Copy Constructor Called"<<std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &target)
{
	this->name.assign(target.name);
	this->hp = target.hp;
	this->energy = target.energy;
	this->damage = target.damage;
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout<<"["<<name<<"]"<<"ClapTrap Destructor Called"<<std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (hp == 0)
		return ;
	if (energy == 0)
	{
		std::cout<<"["<<name<<"] can not attack, check energy"<<std::endl;
		return ;
	}
	std::cout<<"["<<name<<"] attacks "<<"{"<<target<<"}, causing "<<damage<<" points of damage!"<<std::endl;
	this->energy--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hp == 0)
		return ;
	hp = (hp > amount) ? (hp - amount) : 0;
	std::cout<<"["<<name<<"] takes "<<"{"<<amount<<"}"<<"points of damage!"<<std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hp == 0 || hp == UINT_MAX)
		return ;
	hp = (hp + amount > hp) ? (hp + amount) : (UINT_MAX);
	if (energy == 0)
	{
		std::cout<<"["<<name<<"] can not repair, check energy"<<std::endl;
		return ;
	}
	std::cout<<"["<<name<<"] takes "<<"{"<<amount<<"}"<<"points of Repair!"<<std::endl;
	this->energy--;
}

void ClapTrap::ShowStatus(void) const
{
	std::cout<<"||"<<this->name<<"'s status ||"<<std::endl;
	std::cout<<"||hp :"<<hp<<"||"<<std::endl;
	std::cout<<"||energy :"<<energy<<"||"<<std::endl;
	std::cout<<"||damage :"<<damage<<"||"<<std::endl;
}

ClapTrap::ClapTrap(unsigned int hp, unsigned int energy, unsigned int damage) : name("Unknown"), hp(hp), energy(energy), damage(damage) 
{
	std::cout<<"["<<name<<"]"<<"ClapTrap Constructor Called"<<std::endl;
}

ClapTrap::ClapTrap(std::string name, unsigned int hp, unsigned int energy, unsigned int damage) : name(name), hp(hp), energy(energy), damage(damage)
{
	std::cout<<"["<<name<<"]"<<"ClapTrap Constructor Called"<<std::endl;
}
