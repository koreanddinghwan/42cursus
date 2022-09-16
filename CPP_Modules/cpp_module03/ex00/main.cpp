/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:12:56 by myukang           #+#    #+#             */
/*   Updated: 2022/07/14 15:24:31 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap c1;
	ClapTrap c2("c2");
	ClapTrap c3(c2);

	c1.attack("c2");
	c1.ShowStatus();

	c1.beRepaired(5000000);
	c1.ShowStatus();

	c1.beRepaired(2147483648);
	c1.ShowStatus();
	
	c1.beRepaired(2147483648);
	c1.ShowStatus();
	
	c1.beRepaired(2147483648);
	c1.beRepaired(2147483648);
	c1.beRepaired(2147483648);
	c1.beRepaired(2147483648);
	c1.ShowStatus();


	c1.attack("c3");
	c1.ShowStatus();
	c1.attack("c3");
	c1.ShowStatus();

	c1.attack("c3");
	c1.ShowStatus();

	c1.attack("c3");
	c1.ShowStatus();

	c1.attack("c3");
	c1.ShowStatus();

	c1.attack("c3");
	c1.ShowStatus();

	c1.attack("c3");
	c1.ShowStatus();

	return 0;
}
