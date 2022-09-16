#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	this->brain = new Brain();
	std::cout<<"["<<type<<"]"<<"Cat Default constructor called"<<std::endl;
}

Cat::Cat(std::string name) : Animal(name)
{
	this->brain = new Brain();
	std::cout<<"["<<type<<"]"<<"Cat constructor called"<<std::endl;
}

Cat::Cat(const Cat& copy) : Animal(copy)
{
	this->brain = new Brain();
	this->brain->setter(*(copy.brain));
	std::cout<<"["<<type<<"]"<<"Cat copy constructor called"<<std::endl;
}

Cat& Cat::operator=(const Cat &copy)
{
	this->type = copy.type;
	this->brain->setter(*(copy.brain));
	return (*this);
}

Cat::~Cat(void)
{
	delete this->brain;
	std::cout<<"["<<type<<"]"<<"Cat destructor called"<<std::endl;
}

void Cat::makeSound(void) const
{
	std::cout<<"["<<getType()<<"]"<<"meowww"<<std::endl;
}
