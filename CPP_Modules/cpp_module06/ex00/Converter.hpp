#ifndef CONVERTER_HPP
# define CONVERTER_HPP

#include <string>
#include <iostream>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <exception>
#include <stdexcept>
#include <sstream>

class Converter
{
	private:
		char *av;
		char *endp;
		double f;
		long int i;
		char *iendp;
	public:
		Converter(void) throw(std::invalid_argument);
		Converter(char *av) throw(std::invalid_argument);
		~Converter();
	private:
		Converter(const Converter& copy);
		Converter& operator=(const Converter &copy);
	public:
		void print(void) const;
	private:
		const std::string getchar(void) const;
		const std::string getint(void) const;
		const std::string getfloat(void) const;
		const std::string getdouble(void) const;
};

template <typename T>
std::string tostr(const T& t);

template <>
std::string tostr<char>(const char& t);

template <>
std::string tostr<float>(const float& t);

template <>
std::string tostr<double>(const double& t);

#endif
