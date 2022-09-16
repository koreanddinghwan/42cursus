/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 00:36:12 by myukang           #+#    #+#             */
/*   Updated: 2022/07/09 16:50:20 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void ac_num_check(int ac)
{
	if (ac != 4)
	{
		std::cout<<"check parameters..."<<std::endl;
		exit(1);
	}
	else
		std::cout<<"parameter number ok"<<std::endl;
}

int main(int ac, char *argv[])
{
	ac_num_check(ac);
	Replacer replacer = Replacer(argv);
	replacer.openfile();
}
