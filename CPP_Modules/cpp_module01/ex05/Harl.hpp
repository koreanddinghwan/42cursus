/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 21:57:38 by myukang           #+#    #+#             */
/*   Updated: 2022/07/11 15:39:51 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <string>
#include <iostream>

class Harl
{
	typedef struct s_table
	{
		std::string key;
		void (Harl::*fp)(void);
	} t_table;
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
		t_table table[4];
	public:
		Harl(void);
		void complain(std::string level);
};

#endif
