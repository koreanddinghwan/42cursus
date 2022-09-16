/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 01:37:00 by myukang           #+#    #+#             */
/*   Updated: 2022/07/10 13:43:38 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

//use member function in initilizer list
Replacer::Replacer(char *argv[])
	: old_name(argv[1]), new_name(get_new_name(argv[1])), s1(argv[2]), s2(argv[3])
{}

std::string Replacer::get_new_name(std::string str)
{
	return (str.append(".replace"));
}

void Replacer::openfile(void) const
{
	std::fstream new_file;
	std::fstream old_file;
	old_file.open(old_name, std::fstream::in);
	if (!old_file.is_open())
	{
		std::cout<<"I can not open this file =>"<<old_name<<std::endl;
		exit(1);
	}
	new_file.open(new_name, std::fstream::out);
	if (!new_file.is_open())
	{
		std::cout<<"I can not open this file =>"<<new_name<<std::endl;
		old_file.close();
		exit(1);
	}
	replace(old_file, new_file);
	old_file.close();
	new_file.close();
}

void Replacer::get_replace_line(std::string &line, size_t found, std::string &replace_line) const
{
	if (std::string::npos == found)
	{
		replace_line.append(line);
		return ;
	}
	else
	{
		size_t	i;
		i = 0;
		while (i < found)
			replace_line.push_back(line[i++]);
		line.erase(0, found + s1.length());
		replace_line.append(s2);
		get_replace_line(line, line.find(s1), replace_line);
	}
}

void Replacer::replace(std::fstream &old_file, std::fstream &new_file) const
{
	std::string line;
	std::string replace_line;

	while (std::getline(old_file, line))
	{
		replace_line.clear();
		size_t found = line.find(s1);
		if (std::string::npos == found)
			new_file.write(line.data(), line.length());
		else
		{
			get_replace_line(line, found, replace_line);
			new_file.write(replace_line.data(), replace_line.length());
		}
		new_file.write("\n", 1);
	}
}
