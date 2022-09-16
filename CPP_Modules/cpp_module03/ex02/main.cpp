/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:12:56 by myukang           #+#    #+#             */
/*   Updated: 2022/07/14 17:45:15 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap c1;
	ScavTrap s1;
	ScavTrap s2("s2");

	c1.ShowStatus();
	s1.guardGate();
	s2.guardGate();
	s1.ShowStatus();
	s2.ShowStatus();
	return 0;
}
