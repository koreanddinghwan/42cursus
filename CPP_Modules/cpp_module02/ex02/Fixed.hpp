/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:45:35 by myukang           #+#    #+#             */
/*   Updated: 2022/07/14 13:45:50 by myukang          ###   ########.fr       */
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
		/*
		 * comparison
		 * */
		bool operator>(const Fixed &target) const;
		bool operator<(const Fixed &target) const;
		bool operator>=(const Fixed &target) const;
		bool operator<=(const Fixed &target) const;
		bool operator==(const Fixed &target) const;
		bool operator!=(const Fixed &target) const;
		/*
		 * arithmetic
		 * */
		Fixed operator+(const Fixed &target) const;
		Fixed operator-(const Fixed &target) const;
		Fixed operator*(const Fixed &target) const;
		Fixed operator/(const Fixed &target) const;
		/*
		 * pre, post
		 * */
		Fixed& operator++();
		const Fixed operator++(int);
		Fixed& operator--();
		const Fixed operator--(int);
		/*
		 * functions
		 * */
		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed &a, const Fixed &b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed &a, const Fixed &b);
};

std::ostream& operator<<(std::ostream &ostm, const Fixed &ref);
#endif
