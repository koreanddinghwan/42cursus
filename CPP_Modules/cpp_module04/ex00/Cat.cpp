#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	std::cout<<"["<<type<<"]"<<"Cat Default constructor called"<<std::endl;
}

Cat::Cat(std::string name) : Animal(name)
{
	std::cout<<"["<<type<<"]"<<"Cat constructor called"<<std::endl;
}

Cat::Cat(const Cat& copy) : Animal(copy)
{
	std::cout<<"["<<type<<"]"<<"Cat copy constructor called"<<std::endl;
}

Cat& Cat::operator=(const Cat &copy)
{
	this->type = copy.type;
	return (*this);
}

Cat::~Cat(void)
{
	std::cout<<"["<<type<<"]"<<"Cat destructor called"<<std::endl;
}

void Cat::makeSound(void) const
{
	std::cout<<"["<<getType()<<"]"<<"meowww"<<std::endl;
}
