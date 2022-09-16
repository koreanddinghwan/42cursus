#ifndef SPAN_HPP
# define SPAN_HPP

#include <cstdlib>
#include <exception>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <numeric>

class Span{
	private:
		unsigned int maxCount;
		unsigned int curCount;
		std::vector<int> vec;
	public:
		Span(void);
		Span(unsigned int n);
		Span(const Span& copy);
		~Span(void);
	public:
		Span& operator=(const Span& copy);
	public:
		void addNumber(int n) throw(std::logic_error);

		int shortestSpan(void) throw(std::logic_error);
		int longestSpan(void) throw(std::logic_error);

		template <typename T>
		void addRange(typename T::iterator begin, typename T::iterator end) throw(std::logic_error)
		{
			for (; begin != end; begin++)
				addNumber(*begin);
		}

		int getCurCnt(void) const;
		std::vector<int>& getVector(void);
};

std::ostream& operator<<(std::ostream& os, Span& sp);

#endif
