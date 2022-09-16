#include "easyfind.hpp"
#include <vector>


template <typename T>
void print(T begin, T end)
{
	while (begin != end)
	{
		std::cout<< *begin << " ";
		begin++;
	}
	std::cout<< std::endl;
}

int main(void)
{
	std::vector<int> vec;

	vec.push_back(5);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(10);
	vec.push_back(9);
	vec.push_back(8);

	std::cout<<"현재 상태"<<std::endl;
	print(vec.begin(), vec.end());

	try {
		easyfind< std::vector<int> >(vec, 11);
	} catch (std::exception &e) {
		std::cout<<e.what()<<std::endl;
	}
}
