/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 01:37:01 by myukang           #+#    #+#             */
/*   Updated: 2022/07/09 17:06:58 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACER_HPP
# define REPLACER_HPP

#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <string>

class Replacer
{
	private:
		const std::string	old_name;
		const std::string	new_name;
		const std::string	s1;
		const std::string	s2;
	private:
		std::string			get_new_name(std::string str);
		void replace(std::fstream &old_file, std::fstream &new_file) const;
		void get_replace_line(std::string &line, size_t found, std::string &replace_line) const;
	public:
		Replacer(char *argv[]);
		void openfile(void) const;
};


#endif
