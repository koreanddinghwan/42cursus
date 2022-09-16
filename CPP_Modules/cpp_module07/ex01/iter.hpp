#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>
#include <iostream>

template <typename T>
void iter(T *arr, std::size_t len, void (*fnc)(T const &a))
{
	std::size_t i = 0;

	while (i < len)
		fnc(arr[i++]);
}

//clang++ -Xclang -ast-print -fsyntax-only main.cpp
template <typename T> 
void    print(T const& x) {
	std::cout << x << std::endl;
	return ;
}

class Test {
	private:
			int n;
	public:
			Test(void) : n(42)
			{}
			int getn( void ) const 
			{
				return this->n;
			}
};

#endif
