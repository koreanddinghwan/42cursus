/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:00:15 by myukang           #+#    #+#             */
/*   Updated: 2022/07/07 19:10:51 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	std::string	name("zombies");

	Zombie *zombies = Zombie::zombieHorde(5, name);
	for (int i = 0; i < 5; i++)
	{
		std::cout<<zombies[i].get_name()<<std::endl;
		zombies[i].announce();
	}
	delete []zombies;
}
