#include "Data.hpp"

int main(void)
{
	Data ptr;

	ptr.n = 123;

	uintptr_t rawbit = serialize(&ptr);
	std::cout<<"ptr 의 rawbit: "<<rawbit<<std::endl;
	std::cout.flags(std::ios::hex);
	std::cout<<"ptr 의 rawbit hex: "<<rawbit<<std::endl;
	std::cout<<"ptr 의 주소값: "<<reinterpret_cast<void *>(&ptr)<<std::endl;
	std::cout.unsetf(std::ios::hex);
	std::cout<<deserialize(rawbit)->n<<std::endl;
	return 0;
}
