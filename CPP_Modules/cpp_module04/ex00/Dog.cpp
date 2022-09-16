#include "Dog.hpp"
#include "Animal.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout<<"["<<type<<"]"<<"Dog Default constructor called"<<std::endl;
}

Dog::Dog(std::string name) : Animal(name)
{
	std::cout<<"["<<type<<"]"<<"Dog constructor called"<<std::endl;
}

Dog::Dog(const Dog& copy) : Animal(copy)
{
	std::cout<<"["<<type<<"]"<<"Dog copy constructor called"<<std::endl;
}

Dog& Dog::operator=(const Dog &copy)
{
	this->type = copy.type;
	return (*this);
}

Dog::~Dog(void)
{
	std::cout<<"["<<type<<"]"<<"Dog destructor called"<<std::endl;
}

void Dog::makeSound(void) const
{
	std::cout<<"["<<getType()<<"]"<<"Barking..."<<std::endl;
}
