#include <iostream>
#include <vector>

int main(void) {
  {
    std::vector<int> v;
    v.push_back(6);
    v.push_back(6);
    v.push_back(6);
    v.push_back(6);
    v.push_back(6);
    v.push_back(6);
    std::cout << v.size() << std::endl;
    std::cout << v.max_size() << std::endl;
    std::cout << v.capacity() << std::endl;
  }

  return 0;
}
