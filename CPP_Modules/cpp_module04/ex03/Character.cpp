#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(void) : ICharacter(), name("NoName"), idx(0), unequiped_idx(0)
{
	std::cout<<"Character Constructor Called"<<std::endl;
}

Character::Character(const std::string name) : ICharacter(), name(name), idx(0), unequiped_idx(0)
{
	std::cout<<"Character Constructor Called"<<std::endl;
}

Character::Character(const Character &copy) : ICharacter(), name(copy.name), idx(copy.idx), unequiped_idx(copy.unequiped_idx)
{
	std::cout<<"Character Copy Constructor Called"<<std::endl;
	for (int i = 0 ; i < copy.idx ; i++)
		this->slots[i] = copy.slots[i]->clone();
	for (int i = 0; i < copy.unequiped_idx; i++)
		this->unequiped[i] = copy.unequiped[i]->clone();
}

Character& Character::operator=(const Character &copy)
{
	for (int i = 0; i < this->idx ; i++)
		delete this->slots[i];
	for (int i = 0; i < this->unequiped_idx ; i++)
		delete this->unequiped[i];
	for (int i = 0 ; i < copy.idx ; i++)
		this->slots[i] = copy.slots[i]->clone();
	for (int i = 0; i < copy.unequiped_idx; i++)
		this->unequiped[i] = copy.unequiped[i]->clone();
	this->idx = copy.idx;
	this->unequiped_idx = copy.unequiped_idx;
	return (*this);
}

Character::~Character(void)
{
	std::cout<<"Character Destructor Called"<<std::endl;
	for (int i = 0; i < this->idx; i++)
		delete this->slots[i];
	for (int i = 0; i < this->unequiped_idx; i++)
		delete this->unequiped[i];
}

std::string const & Character::getName(void) const
{
	return (this->name);
}

void Character::equip(AMateria *m)
{
	if (this->idx > 3)
	{
		delete m;
		return ;
	}
	this->slots[this->idx] = m;
	this->idx++;
}

void Character::unequip(int idx)
{
	if (this->idx == 0)
	{
		std::cout<<"check index"<<std::endl;
		return ;
	}
	else if (this->idx - 1 < idx)
	{
		std::cout<<"check index"<<std::endl;
		return ;
	}
	else if (this->unequiped_idx > 99)
	{
		std::cout<<"unequiped slot is full"<<std::endl;
		return ;
	}
	else
	{
		this->unequiped[this->unequiped_idx++] = this->slots[idx];
		for (int i = idx ; i < 3 ; i++)
			this->slots[i] = this->slots[i + 1];
		this->idx--;
	}
}

void Character::use(int idx, ICharacter &target)
{
	if (this->idx == 0)
	{
		std::cout<<"check index"<<std::endl;
		return ;
	}
	else if (this->idx - 1 < idx)
	{
		std::cout<<"check index"<<std::endl;
		return ;
	}
	this->slots[idx]->use(target);
}
