/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 11:33:10 by myukang           #+#    #+#             */
/*   Updated: 2022/07/23 15:54:50 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <cmath>

void checknan(float test)
{
	if (isnan(test))
	{
		std::cout<<"check : "<<test<<" is nan"<<std::endl;
	}
}

int main(void)
{
	char str1[] = "Nan";
	const char *strings[] = {"42.1f", "42222", "214748.00012341234"};

	char *end;

	checknan(strtod(str1, &end));
	int i = 0;
	float test;
	double test2;
	while (i < 3)
	{
		test = strtod(strings[i], &end);
		test2 = strtod(strings[i], &end);
		std::cout << 42.1 << std::setprecision(4) << std::endl;
		std::cout<<"'"<<test<<"' ,"<<test2<<": "<<end<<std::endl;
		checknan(test);
		i++;
	}
	return 0;
}
