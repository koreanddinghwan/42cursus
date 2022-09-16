/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 00:20:29 by myukang           #+#    #+#             */
/*   Updated: 2022/07/31 00:21:22 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <iostream>
#include <vector>


template <typename Iter>
void print(Iter begin, Iter end)
{
	while (begin != end)
	{
		std::cout<<*begin<<" ";
		begin++;
	}
	std::cout<<std::endl;
}


int main()
{
	std::vector<int> vec;

	vec.push_back(5);
	vec.push_back(3);
	vec.push_back(1);
	vec.push_back(6);
	vec.push_back(4);
	vec.push_back(7);
	vec.push_back(2);
	std::cout<<"정렬 전"<<std::endl;

	print(vec.begin(), vec.end());

	std::sort(vec.begin(), vec.end());
	std::cout<<"정렬 후"<<std::endl;
	
	return 0;
}

