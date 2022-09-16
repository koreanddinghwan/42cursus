/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:13:25 by myukang           #+#    #+#             */
/*   Updated: 2022/07/08 00:15:28 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void)
{
	{//block A
		Weapon club = Weapon("crude spiked club");

		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{//block B
		Weapon club = Weapon("crude spiked club");
		
		HumanB jim("Jim");//jim not armed here
		jim.attack();
		jim.setWeapon(club);//jim armed here
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return (0);
}
