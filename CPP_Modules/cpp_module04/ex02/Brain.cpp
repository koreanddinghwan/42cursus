#include "Brain.hpp"

Brain::Brain(void) : idea_index(0)
{
	std::cout<<"Brain constructor called"<<std::endl;
}

Brain::Brain(const Brain &copy) : idea_index(0)
{
	setter(copy);
	std::cout<<"Brain Copy constructor called"<<std::endl;
}

Brain& Brain::operator=(const Brain &copy)
{
	setter(copy);
	return (*this);
}

Brain::~Brain(void)
{
	std::cout<<"Brain destructor called"<<std::endl;
}

std::string* Brain::getter(void)
{
	return (ideas);
}

void Brain::setter(const Brain &copy)
{
	for (int i = 0;i < copy.idea_index; i++)
		ideas[i].assign(copy.ideas[i]);
	for (int i = copy.idea_index; i < 100; i++)
		ideas[i].clear();
	this->idea_index = copy.idea_index;
}

void Brain::think(const std::string idea)
{
	this->ideas[idea_index++].assign(idea);
}
