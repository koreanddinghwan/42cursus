/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 20:57:12 by myukang           #+#    #+#             */
/*   Updated: 2022/07/08 00:21:11 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void) : type("None")
{}

const std::string& Weapon::getType(void) const
{
	return (this->type);
}

void Weapon::setType(const std::string type)
{
	this->type.assign(type);
}

Weapon::Weapon(std::string type) : type(type)
{}
