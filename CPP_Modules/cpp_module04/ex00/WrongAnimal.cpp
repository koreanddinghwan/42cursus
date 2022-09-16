#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("Unknown")
{
	std::cout<<"["<<type<<"]"<<"WrongAnimal Default constructor called"<<std::endl;
}

WrongAnimal::WrongAnimal(std::string name) : type(name)
{
	std::cout<<"["<<type<<"]"<<"WrongAnimal constructor called"<<std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy) : type(copy.type)
{
	std::cout<<"["<<type<<"]"<<"WrongAnimal copy constructor called"<<std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &copy)
{
	this->type = copy.type;
	return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout<<"["<<type<<"]"<<"WrongAnimal destructor called"<<std::endl;
}

void WrongAnimal::makeSound(void) const
{
	std::cout<<"["<<type<<"]"<<"WrongAnimal makeSound()"<<std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return (type);
}

void WrongAnimal::set_type(std::string copy)
{
	type = copy;
}
