/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:12:56 by myukang           #+#    #+#             */
/*   Updated: 2022/07/18 13:15:31 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
//	DiamondTrap d1("test");

	DiamondTrap *ptr1 = new DiamondTrap("t2");

	ptr1->ShowStatus();
	ptr1->whoAmI();
	ptr1->attack("hi");
	delete ptr1;

	ScavTrap *ptr2 = new DiamondTrap("t3");
	delete ptr2;
	return 0;
}
