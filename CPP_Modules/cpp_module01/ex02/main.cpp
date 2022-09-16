/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:13:25 by myukang           #+#    #+#             */
/*   Updated: 2022/07/07 20:54:33 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(void)
{
	const char *temp = "HI THIS IS BRAIN";
	std::string str(temp);

	const std::string *stringPTR = &str;
	const std::string &stringREF = str;

	std::cout<<"string address : "<<&str<<std::endl;//string class allocate internal buffer
	std::cout<<"stringPTR : "<<stringPTR<<std::endl;
	std::cout<<"stringREF : "<<(&stringREF)<<std::endl;
	std::cout<<std::endl;
	std::cout<<"string varible value : "<<str<<std::endl;
	std::cout<<"value of stringPTR : "<<(*stringPTR)<<std::endl;
	std::cout<<"value of stringREF : "<<stringREF<<std::endl;
}
