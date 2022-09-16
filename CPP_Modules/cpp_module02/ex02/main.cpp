/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:44:01 by myukang           #+#    #+#             */
/*   Updated: 2022/07/14 00:42:33 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed( 2 ));

	std::cout<< a <<std::endl;
	std::cout<< ++a <<std::endl;
	std::cout<< a <<std::endl;
	std::cout<< a++ <<std::endl;
	std::cout<< a <<std::endl;

	std::cout << b <<std::endl;
	std::cout << Fixed::max(a, b) <<std::endl;

	Fixed c(-2.1f);
	Fixed d(-2);
	std::cout << c * d << std::endl;
	std::cout << 2.1f * 2.0f<<std::endl;
	std::cout << (c > d) << std::endl;
	Fixed e = Fixed(4.5f);
	Fixed f = Fixed(2.0f);
	std::cout << (e / f) << std::endl;
return (0);
}
