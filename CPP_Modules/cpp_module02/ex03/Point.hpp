/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 18:53:39 by myukang           #+#    #+#             */
/*   Updated: 2022/07/14 01:44:16 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed x;
		const Fixed y;
	public:
		Point(void);
		Point(const float a, const float b);
		Point(const Point &copy);
		Point& operator=(const Point &target);
		~Point(void);
		Fixed getx(void) const;
		Fixed gety(void) const;
		bool operator==(const Point &target) const;
	private:
		void donothing(const Point &target);
};
bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
