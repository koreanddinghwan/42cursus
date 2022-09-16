/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:15:15 by myukang           #+#    #+#             */
/*   Updated: 2022/07/07 21:05:38 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::set_name(std::string name)
{
	this->name.assign(name);
}

const char *Zombie::get_name(void) const
{
	return (this->name.data());
}

Zombie *Zombie::zombieHorde(int n, const std::string name)
{

	Zombie *rtn = new Zombie[n];
	if (!rtn)
		return (NULL);
	for (int i = 0; i < n; i++)
	{
		rtn[i].set_name(name);
	}
	return (rtn);
}
