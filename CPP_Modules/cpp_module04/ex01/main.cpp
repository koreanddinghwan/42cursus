#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal *k = new Animal();
	delete k;

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
	const Animal *arr[100];
	for (int i = 0; i < 100; i++)
	{
		if (i < 50)
			arr[i] = new Dog();
		else
			arr[i] = new Cat();
	}
	for (int i = 0; i < 100; i++)
	{
		std::cout<<"["<<i<<"]"<<std::endl;
		delete arr[i];
		std::cout<<std::endl;
	}
	
	const Dog *test = new Dog();

	test->think("im hungry");
	test->think("im sleepy");
	test->think("it is very lazy");
	test->print_think();

	std::cout<<std::endl;

	const Dog test2 = *test;
	std::cout<<std::endl;
	test2.print_think();

	std::cout<<"*********************test2**********************"<<std::endl;
	test2.think("test 1");
	test2.think("test 2");
	test2.print_think();
	std::cout<<"*********************test1********************"<<std::endl;
	test->print_think();

	delete test;
	return 0;
}
