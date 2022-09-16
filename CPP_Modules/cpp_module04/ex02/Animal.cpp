#include "Animal.hpp"

Animal::Animal(void) : type("Unknown")
{
	std::cout<<"["<<type<<"]"<<"Animal Default constructor called"<<std::endl;
}

Animal::Animal(std::string name) : type(name)
{
	std::cout<<"["<<type<<"]"<<"Animal constructor called"<<std::endl;
}

Animal::Animal(const Animal& copy) : type(copy.type)
{
	std::cout<<"["<<type<<"]"<<"Animal copy constructor called"<<std::endl;
}

Animal& Animal::operator=(const Animal &copy)
{
	this->type = copy.type;
	return (*this);
}

Animal::~Animal(void)
{
	std::cout<<"["<<type<<"]"<<"Animal destructor called"<<std::endl;
}

std::string Animal::getType(void) const
{
	return (type);
}

void Animal::set_type(std::string copy)
{
	type = copy;
}
