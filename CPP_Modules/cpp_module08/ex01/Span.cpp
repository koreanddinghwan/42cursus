#include "Span.hpp"
#include <algorithm>
#include <iterator>
#include <numeric>
#include <stdexcept>
#include <vector>

Span::Span(void) : maxCount(0), curCount(0)  
{
	std::cout<<"Span Default Constructor Called"<<std::endl;
}

Span::Span(unsigned int n) : maxCount(n), curCount(0)  
{
	std::cout<<"Span Constructor Called"<<std::endl;
}

Span::Span(const Span& copy) : maxCount(copy.maxCount), curCount(copy.curCount)
{
	this->vec.assign(copy.vec.begin(), copy.vec.end());
}

Span::~Span(void)
{
	std::cout<<"Span Destructor Called"<<std::endl;
}

Span& Span::operator=(const Span &copy)
{
	if (this == &copy)
		return (*this);
	this->vec.assign(copy.vec.begin(), copy.vec.end());
	this->maxCount = copy.maxCount;
	this->curCount = copy.curCount;
	return (*this);
}

void Span::addNumber(int n) throw(std::logic_error)
{
	if (curCount == maxCount)
		throw (std::logic_error("This Span is full"));
	vec.push_back(n);
	curCount++;
}

int Span::shortestSpan() throw(std::logic_error)
{
	if (curCount <= 1)
		throw std::logic_error("This Span has 0 or 1 element");

	std::vector<int> tmp;
	int result[maxCount - 1];

	tmp.assign(vec.begin(),vec.end());
	std::sort(tmp.begin(), tmp.end());
	std::adjacent_difference(tmp.begin(), tmp.end(), result);
	return (*std::min_element(result, result + maxCount - 1));
}

int Span::longestSpan() throw(std::logic_error)
{
	if (curCount <= 1)
		throw std::logic_error("This Span has 0 or 1 element");

	return (abs(*std::max_element(vec.begin(), vec.end()) - *std::min_element(vec.begin(),vec.end())));
}

int Span::getCurCnt(void) const
{
	return (this->curCount);
}

std::vector<int>& Span::getVector(void)
{
	return (this->vec);
}
