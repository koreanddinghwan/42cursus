#include "../vector.hpp"
#include <iostream>
#include <vector>

class A {
private:
  int *p;
  A() { p = new int[5]; }
  ~A() { delete[] p; }
};

void printft(ft::vector<int> a) {
  for (auto begin = a.begin(); begin < a.end(); begin++) {
    std::cout << *begin << std::endl;
  }
}

void printstd(std::vector<int> a) {
  for (auto begin = a.begin(); begin < a.end(); begin++) {
    std::cout << *begin << std::endl;
  }
}

int main(void) {

  { ft::vector<A> test; }

  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;

  {
    ft::vector<int> test;
    test.push_back(1);
    test.push_back(1);
    test.push_back(1);
    test.push_back(1);
    printft(test);
  }

  {
    std::vector<int> test;
    test.push_back(1);
    test.push_back(1);
    test.push_back(1);
    test.push_back(1);
    printstd(test);
  }

  {}
  while (1)
    ;
  return 0;
}
