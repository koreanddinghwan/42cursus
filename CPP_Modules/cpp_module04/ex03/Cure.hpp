#ifndef Cure_HPP
# define Cure_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure(void);
		Cure(const Cure& copy);
		Cure& operator=(const Cure& copy);
		~Cure(void);
	public:
		AMateria* clone(void) const;
		void use(ICharacter& target);
};

#endif
