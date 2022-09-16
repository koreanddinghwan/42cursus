#include "Converter.hpp"

int main(int ac, char *av[])
{
	if (ac != 2 || std::strlen(av[1]) == 0)
	{
		std::cout<<"check argument num"<<std::endl;
		return (1);
	}
	try {
	Converter conv(av[1]);
	} catch (std::exception &e)
	{
		std::cout<<e.what()<<std::endl;
	}
	return (0);
}
