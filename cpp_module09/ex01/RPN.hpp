#include <exception>
#include <iostream>
#include <stack>
#include <cctype>

#ifndef __RPN_HPP__
# define __RPN_HPP__

class RPN {
	private:
		std::stack<int> Default;
		std::stack<int> Result;
		bool errBit;

	public:
		RPN(int ac, char *av[]);
		~RPN();

		void printResult();

	private:
		RPN(RPN &o);
		RPN& operator=(RPN &o);
};

#endif
