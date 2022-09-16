#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>
#include <string>

template <typename T>
void swap(T& a, T& b)
{
	T c(a);

	a = b;
	b = c;
}

template <typename T>
const T& min(const T& a, const T& b)
{
	return !(b < a) ? a : b;
}

template <typename T>
T& min(T& a, T& b)
{
	return !(b < a) ? a : b;
}

template <typename T>
const T& max(const T& a, const T& b)
{
	std::cout<<"called const max!"<<std::endl;
	return (a < b) ? b : a;
}

template <typename T>
T& max(T& a, T& b)
{
	std::cout<<"called max!"<<std::endl;
	return (a < b) ? b : a;
}


#endif
