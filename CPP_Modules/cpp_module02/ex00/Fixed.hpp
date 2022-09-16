/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:45:35 by myukang           #+#    #+#             */
/*   Updated: 2022/07/13 15:03:07 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int	value;
		static const int fraction = 8;
	public:
		Fixed(void);
		Fixed(const Fixed &copy);
		Fixed& operator=(const Fixed &target);
		~Fixed(void);
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif
