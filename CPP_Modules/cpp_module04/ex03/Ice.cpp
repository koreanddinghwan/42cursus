#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
	std::cout<<"Ice Constructor Called"<<std::endl;
}

Ice::Ice(const Ice& copy) : AMateria(copy.type)
{
	std::cout<<"Ice Copy Constructor Called"<<std::endl;
}

Ice& Ice::operator=(const Ice &copy)
{
	this->type = copy.type;
	return (*this);
}

Ice::~Ice(void)
{
	std::cout<<"Ice Destructor Called"<<std::endl;
}

AMateria* Ice::clone(void) const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter &target)
{
	std::cout<<"* shoots an ice bolt at "<<target.getName()<<" *"<<std::endl;
}
