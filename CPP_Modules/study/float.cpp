#include <iostream>

int main(void)
{
	float a;
	float b;
	double c;

	a = 3.14159212312;
	b = 1 / 3;
	c = 1.0/3.0;
	float d = 3.402823466e+38;
	std::cout<<a<<std::endl;
	std::cout<<static_cast<double>(a)<<std::endl;
	std::cout<<b<<std::endl;
	std::cout<<c<<std::endl;
	std::cout<<c + c + c<<std::endl;
	std::cout<<d<<std::endl;
}
