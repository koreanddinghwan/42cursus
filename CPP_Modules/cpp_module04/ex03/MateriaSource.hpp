#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include <cstddef>

class MateriaSource : public IMateriaSource
{
	private:
		AMateria *slots[4];
		int idx;
	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource &copy);
		MateriaSource& operator=(const MateriaSource &copy);
		~MateriaSource();
		void learnMateria(AMateria*);
		AMateria *createMateria(std::string const &type);
};

#endif
