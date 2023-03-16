#include <algorithm>
#include <cstdio>
#include <exception>
#include <fstream>
#include <iterator>
#include <stdexcept>
#include <string>
#include <iostream>
#include "DateAndValue.hpp"

#ifndef __USERDATABASE_HPP__
# define __USERDATABASE_HPP__

class UserDatabase {
	private:
		std::ifstream file;

	public:
		UserDatabase(int ac, char *av[]);
		~UserDatabase();

	private:
		UserDatabase(UserDatabase &o);
		UserDatabase& operator=(UserDatabase &o);

	public:
		DateAndValue* get(void) throw (std::exception);
};

#endif
