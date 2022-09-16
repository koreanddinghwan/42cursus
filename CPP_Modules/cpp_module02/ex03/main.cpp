/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 01:01:02 by myukang           #+#    #+#             */
/*   Updated: 2022/07/14 13:42:25 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int main(void)
{
	Point a(2.0f, 0.0f);
	Point b(0.0f, 2.0f);
	Point c(0.0f, 0.0f);
	Point check(0.1f, 0.0f);

	if (bsp(a, b, c, check) == true)
	{
		std::cout<<"in triangle"<<std::endl;
	}
	else
	{
		std::cout<<"not in triangle"<<std::endl;
	}
	return (0);
}
