#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
//	const Animal* test1 = new Animal(); =>Animal class is abstract class 

	const Animal* j = new Dog();
	std::cout<<std::endl;
	std::cout<<std::endl;
	const Animal* i = new Cat();
	std::cout<<std::endl;
	std::cout<<std::endl;


	delete j;//should not create a leak
	std::cout<<std::endl;
	delete i;
	std::cout<<std::endl;
	return 0;
}
