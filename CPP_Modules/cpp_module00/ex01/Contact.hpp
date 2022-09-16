/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 00:35:01 by myukang           #+#    #+#             */
/*   Updated: 2022/07/14 14:48:21 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
#include <iostream>
#include <string>
#include <cstdio>
#include <cctype>
class Contact
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nick_name;
		std::string	phone_number;
		std::string	darkest_secret;
		void set_string(std::string &obj, const char *str);
		int  is_empty(std::string obj) const;
	public:
		void make_contact(void);
		const std::string get_first_name(std::string &buffer) const;
		const std::string get_last_name(std::string &buffer) const;
		const std::string get_nick_name(std::string &buffer) const;
		void printall() const;
};

#endif
