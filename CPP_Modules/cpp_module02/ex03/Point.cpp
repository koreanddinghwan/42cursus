/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 18:53:17 by myukang           #+#    #+#             */
/*   Updated: 2022/07/14 01:44:34 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Point::Point(void) : x(0), y(0)
{}

Point::Point(const float a, const float b) : x(a), y(b) 
{}

Point::Point(const Point &copy) : x(copy.x), y(copy.y)
{}

Point& Point::operator=(const Point &target)
{
	donothing(target);
	return (*this);
}

Point::~Point(void)
{}

Fixed Point::getx(void) const
{
	return (x);
}

Fixed Point::gety(void) const
{
	return (y);
}

bool Point::operator==(const Point &target) const
{
	if ((this->getx() == target.getx()) && (this->gety() == target.gety()))
		return (true);
	else
		return (false);
}

void Point::donothing(const Point &target)
{
	if (target.getx() == 0)
		return ;
	else
		return;
}
