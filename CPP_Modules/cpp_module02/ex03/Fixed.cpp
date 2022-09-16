/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:57:27 by myukang           #+#    #+#             */
/*   Updated: 2022/07/14 01:45:07 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : rawbits(0)
{
}

Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
}

Fixed& Fixed::operator=(const Fixed &target)
{
	this->rawbits = target.rawbits;
	return (*this);
}

Fixed::~Fixed(void)
{
}

int Fixed::getRawBits(void) const
{
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
	rawbits = num << fraction;
}

/*
 * floating point value to fixed point value
 * */
Fixed::Fixed(const float num)
{
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
	return (rawbits >> fraction);
}

std::ostream& operator<<(std::ostream &ostm, const Fixed &ref)
{
	ostm<<ref.toFloat();
	return (ostm);
}

/*
 * ex02
 * comparison
 * */

bool Fixed::operator>(const Fixed &target) const
{
	return (this->getRawBits() > target.getRawBits());
}

bool Fixed::operator<(const Fixed &target) const
{
	return (this->getRawBits() < target.getRawBits());
}

bool Fixed::operator>=(const Fixed &target) const
{
	return (this->getRawBits() >= target.getRawBits());
}

bool Fixed::operator<=(const Fixed &target) const
{
	return (this->getRawBits() <= target.getRawBits());
}

bool Fixed::operator==(const Fixed &target) const
{
	if (this->rawbits == target.getRawBits())
		return (true);
	else
		return (false);
}

bool Fixed::operator!=(const Fixed &target) const
{
	return (!(*this == target));
}

/*
 * arithmetic
 * https://vanhunteradams.com/FixedPoint/FixedPoint.html
 * */


Fixed Fixed::operator+(const Fixed &target) const
{
	Fixed ret = (this->toFloat() + target.toFloat());
	return (ret);
}

Fixed Fixed::operator-(const Fixed &target) const
{
	Fixed ret = (this->toFloat() - target.toFloat());
	return (ret);
}

Fixed Fixed::operator*(const Fixed &target) const
{
	long long rtn;
	Fixed ret;

	rtn = static_cast<long long>(this->getRawBits()) * static_cast<long long>(target.getRawBits());
	rtn >>= fraction;
	ret.setRawBits(static_cast<int>(rtn));
	return (ret);
}

Fixed Fixed::operator/(const Fixed &target) const
{
	long long rtn;
	Fixed ret;

	if (target.getRawBits() == 0)
	{
		std::cout << "Zero Devision" << std::endl;
		return (target);
	}
	rtn = (static_cast<long long>(this->getRawBits()) << fraction) / target.getRawBits();
	ret.setRawBits(static_cast<int>(rtn));
	return (ret);
}

Fixed& Fixed::operator++(void)
{
	rawbits += 1;
	return (*this);
}

const Fixed Fixed::operator++(int)
{
	const Fixed retobj(*this);

	this->setRawBits(this->getRawBits() + 1);
	return (retobj);
}

Fixed& Fixed::operator--(void)
{
	rawbits -= 1;
	return (*this);
}

const Fixed Fixed::operator--(int)
{
	const Fixed retobj(*this);

	this->setRawBits(this->getRawBits() - 1);
	return (retobj);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}
