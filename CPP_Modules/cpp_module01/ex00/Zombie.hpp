/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:48:23 by myukang           #+#    #+#             */
/*   Updated: 2022/07/07 17:00:05 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <new>

class Zombie
{
	private:
		const std::string name;
	public:
		Zombie(std::string name);
		Zombie(void);
		~Zombie(void);
	public:
		void announce(void) const;
	public:
		static Zombie	*newZombie(std::string name);
		static void	randomChump(std::string name);
};
#endif
