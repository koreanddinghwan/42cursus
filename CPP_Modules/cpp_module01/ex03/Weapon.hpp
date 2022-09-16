/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 20:57:40 by myukang           #+#    #+#             */
/*   Updated: 2022/07/08 00:20:39 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon
{
	private:
		std::string type;
	public:
		Weapon(void);
		Weapon(std::string type);
		const std::string &getType(void) const;
		void	setType(const std::string type);
};
#endif
