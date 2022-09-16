/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:45:35 by myukang           #+#    #+#             */
/*   Updated: 2022/07/13 15:11:01 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int	rawbits;
		static const int fraction  = 8;
	public:
		Fixed(void);
		Fixed(const Fixed &copy);
		Fixed& operator=(const Fixed &target);
		~Fixed(void);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		Fixed(const int num);
		Fixed(const float num);
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream& operator<<(std::ostream &ostm, const Fixed &ref);
#endif
