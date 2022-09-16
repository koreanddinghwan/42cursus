#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource(void) : idx(0)
{
	std::cout<<"MateriaSource Constructor Called"<<std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &copy) : idx(copy.idx)
{
	for (int i = 0;  i < copy.idx; i++)
		this->slots[i] = copy.slots[i]->clone();
}

MateriaSource& MateriaSource::operator=(const MateriaSource &copy)
{
	for (int i = 0; i < this->idx; i++)
		delete this->slots[i];
	for (int i = 0; i < copy.idx; i++)
		this->slots[i] = copy.slots[i]->clone();
	return (*this);
}

MateriaSource::~MateriaSource(void)
{
	std::cout<<"MateriaSource Destructor Called"<<std::endl;
	for (int i = 0; i < this->idx ; i++)
		delete this->slots[i];
}

void MateriaSource::learnMateria(AMateria *mate)
{
	if (this->idx > 3)
	{
		delete mate;
		return ;
	}
	this->slots[this->idx++] = mate;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < this->idx; i++)
	{
		if (this->slots[i]->getType().compare(type) == 0)
			return (this->slots[i]->clone());
	}
	return (NULL);
}
