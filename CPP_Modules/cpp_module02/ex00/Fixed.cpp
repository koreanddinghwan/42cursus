/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:57:27 by myukang           #+#    #+#             */
/*   Updated: 2022/07/12 20:10:32 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : value(0)
{
	std::cout<<"Default constructor called"<<std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout<<"Copy constructor called"<<std::endl;
	this->value = copy.getRawBits();
}

Fixed& Fixed::operator=(const Fixed &target)
{
	std::cout<<"Copy assignment operator called"<<std::endl;
	this->value = target.value;
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout<<"Destructor called"<<std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout<<"getRawBits member function called"<<std::endl;
	return (this->value);
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}
