/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:48:23 by myukang           #+#    #+#             */
/*   Updated: 2022/07/07 21:05:36 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	private:
		std::string name;
	public:
		Zombie(std::string name);
		Zombie(void);
		~Zombie(void);
	public:
		void announce(void) const;
		void set_name(std::string name);
		const char *get_name(void) const;
	public:
		static Zombie	*newZombie(std::string name);
		static void		randomChump(std::string name);
		static Zombie	*zombieHorde(int n, std::string name);
};
#endif
