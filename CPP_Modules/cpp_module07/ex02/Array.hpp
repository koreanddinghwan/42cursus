#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <new>
#include <exception>

template <typename T>
class Array
{
	private:
		unsigned int num;
		T *arr;
	public:
		Array(void);
		Array(unsigned int n);
		Array(const Array &copy);
		~Array(void);

		Array& operator=(const Array &copy);
		T& operator[](unsigned int i);
		const T& operator[](unsigned int i) const;

		unsigned int size(void) const;

		class OutOfBoundException : public std::exception
		{
			const char *what(void) const throw();
		};
};

# include "Array.tpp"

#endif
