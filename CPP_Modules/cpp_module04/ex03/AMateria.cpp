/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 23:52:40 by myukang           #+#    #+#             */
/*   Updated: 2022/07/20 14:29:15 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"

AMateria::AMateria(std::string const &type) : type(type)
{
	std::cout<<"Amateria Constructor Called"<<std::endl;
}

AMateria::AMateria(const AMateria& copy) : type(copy.type)
{
	std::cout<<"Amateria Copy Constructor Called"<<std::endl;
}

AMateria::~AMateria(void)
{
	std::cout<<"Amateria Destructor Called"<<std::endl;
}

const std::string &AMateria::getType(void) const
{
	return (this->type);
}

void AMateria::use(ICharacter &target)
{
	(void)target;
	std::cout<<"Amateria::use Called"<<std::endl;
}
