#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound(); //compiler found member function in v-table
	meta->makeSound();

	std::cout<<std::endl;
	std::cout<<std::endl;
	std::cout<<std::endl;

	const WrongAnimal* k = new WrongCat();
	std::cout << k->getType() << " " << std::endl;
	k->makeSound();
	//pointer is actually a WrongCat, but makeSound is not a virtual,
	// so compiler calls member function from WrongAnimal
	return 0;
}