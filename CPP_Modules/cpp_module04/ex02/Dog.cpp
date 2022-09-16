#include "Dog.hpp"
#include "Animal.hpp"

Dog::Dog(void) : Animal("Dog")
{
	this->brain = new Brain();
	std::cout<<"["<<type<<"]"<<"Dog Default constructor called"<<std::endl;
}

Dog::Dog(std::string name) : Animal(name)
{
	this->brain = new Brain();
	std::cout<<"["<<type<<"]"<<"Dog constructor called"<<std::endl;
}

Dog::Dog(const Dog& copy) : Animal(copy)
{
	this->brain = new Brain();
	this->brain->setter(*(copy.brain));
	std::cout<<"["<<type<<"]"<<"Dog copy constructor called"<<std::endl;
}

Dog& Dog::operator=(const Dog &copy)
{
	this->type = copy.type;
	this->brain->setter(*(copy.brain));
	return (*this);
}

Dog::~Dog(void)
{
	delete this->brain;
	std::cout<<"["<<type<<"]"<<"Dog destructor called"<<std::endl;
}

void Dog::makeSound(void) const
{
	std::cout<<"["<<getType()<<"]"<<"Barking..."<<std::endl;
}

void Dog::think(const std::string think) const
{
	this->brain->think(think);
}

void Dog::print_think(void) const
{
	std::string *ideas = this->brain->getter();
	for (int i = 0; i < this->brain->idea_index; i++)
	{
		std::cout<<"{"<<i<<"}"<<ideas[i]<<std::endl;
	}
}
