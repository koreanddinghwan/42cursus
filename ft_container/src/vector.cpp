#include "vector.hpp"

int main(void){
    {
    ft::vector<int> first;
    }
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;
    {
	ft::vector<int> second(4, 100);
    }
    {
	/* ft::vector<int> third(second.begin(), second.end()); */
    }
    return 0;
}
