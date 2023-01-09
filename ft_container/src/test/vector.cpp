#include "../vector/vector.hpp"
#include <iostream>
#include <vector>

template<typename _Tp>
void printVector(_Tp vector) {
	auto iterator = vector.begin();
	while (iterator != vector.end()) {
		std::cout<<*iterator<<std::endl;
		iterator++;
	}
}

int main(void) {

  {
    ft::vector<int> test;
    test.push_back(1);
    test.push_back(1);
    test.push_back(1);
    test.push_back(1);
  }

  {
    std::vector<int> test;
    test.push_back(1);
    test.push_back(1);
    test.push_back(1);
    test.push_back(1);
	std::vector<int> copy(test.begin(), test.end());
	printVector(copy);
  }
  return 0;
}
