/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 14:27:55 by myukang           #+#    #+#             */
/*   Updated: 2022/07/14 17:36:31 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
#include <iostream>
#include <climits>

class ClapTrap
{
	protected:
		std::string name;
		unsigned int hp;
		unsigned int energy;
		unsigned int damage;
	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(unsigned int hp, unsigned int energy, unsigned int damage);
		ClapTrap(std::string name, unsigned int hp, unsigned int energy, unsigned int damage);
		ClapTrap(const ClapTrap& copy);
		ClapTrap& operator=(const ClapTrap &target);
		virtual ~ClapTrap(void);
	public:
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void ShowStatus(void) const;
};

#endif
