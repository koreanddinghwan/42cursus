#include "Span.hpp"
#include <cstdlib>
#include <vector>

void test1(void)
{
	int i = 0;
	Span sp(10000);

	srand(time(NULL));
	while (i < 10000)
	{
		sp.addNumber(rand() % 10000);
		i++;
	}
	for(std::vector<int>::iterator it = sp.getVector().begin(); it != sp.getVector().end(); it++)
	{
		std::cout<<*it<<" ";
	}
	std::cout<<std::endl;
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void test0(void)
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

int main()
{
	test0();
	std::cout<<std::endl;
	test1();
	return 0;
}
