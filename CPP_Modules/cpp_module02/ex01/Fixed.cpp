/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:57:27 by myukang           #+#    #+#             */
/*   Updated: 2022/07/14 00:42:02 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : rawbits(0)
{
	std::cout<<"Default constructor called"<<std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout<<"Copy constructor called"<<std::endl;
	*this = copy;
}

Fixed& Fixed::operator=(const Fixed &target)
{
	std::cout<<"Copy assignment operator called"<<std::endl;
	this->rawbits = target.rawbits;
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout<<"Destructor called"<<std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout<<"getRawBits member function called"<<std::endl;
	return (rawbits);
}

void Fixed::setRawBits(int const raw)
{
	this->rawbits = raw;
}

	/* fixed_point num bits layout
	 * 1 | 1 1 1 1 1 1 1 1 ...1 (23)| 1 1 1 1 1 1 1 1 (8)
	 * |                            |
	 * signbit                      |
	 *   |                          |
	 *   integer part               |
	 *                              |
	 *                              fractional part
	 * */
/*
 * integer to fixed_point value
 * */
Fixed::Fixed(const int num)
{
	std::cout<<"Int constructor called"<<std::endl;
	rawbits = num << 8;
}

/*
 * floating point value to fixed point value
 * */
Fixed::Fixed(const float num)
{
	std::cout<<"Float constructor called"<<std::endl;
	rawbits = static_cast<int>(roundf(num * (1 << fraction)));
}

/*
 * fixed point value -> floating point value
 * */
float Fixed::toFloat(void) const
{
	return ((float)rawbits / (float)(1 << fraction));
}

/*
 * fixed point value -> integer
 * */
int Fixed::toInt(void) const
{
	return (rawbits >> 8);
}

std::ostream& operator<<(std::ostream &ostm, const Fixed &ref)
{
	ostm<<ref.toFloat();
	return (ostm);
}
