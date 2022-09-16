#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal()
{
	std::cout<<"["<<type<<"]"<<"WrongCat Default constructor called"<<std::endl;
}

WrongCat::WrongCat(std::string name) : WrongAnimal(name)
{
	std::cout<<"["<<type<<"]"<<"WrongCat constructor called"<<std::endl;
}

WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal(copy)
{
	std::cout<<"["<<type<<"]"<<"WrongCat copy constructor called"<<std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &copy)
{
	this->type = copy.type;
	return (*this);
}

WrongCat::~WrongCat(void)
{
	std::cout<<"["<<type<<"]"<<"WrongCat destructor called"<<std::endl;
}

void WrongCat::makeSound(void) const
{
	std::cout<<"["<<getType()<<"]"<<"meowww"<<std::endl;
}
