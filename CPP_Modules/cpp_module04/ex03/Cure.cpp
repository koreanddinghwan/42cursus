#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
	std::cout<<"Cure Constructor Called"<<std::endl;
}

Cure::Cure(const Cure& copy) : AMateria(copy.type)
{
	std::cout<<"Cure Copy Constructor Called"<<std::endl;
}

Cure& Cure::operator=(const Cure &copy)
{
	this->type = copy.type;
	return (*this);
}

Cure::~Cure(void)
{
	std::cout<<"Cure Destructor Called"<<std::endl;
}

AMateria* Cure::clone(void) const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
	std::cout<<"* heals "<<target.getName()<<"'s wounds *"<<std::endl;
}
