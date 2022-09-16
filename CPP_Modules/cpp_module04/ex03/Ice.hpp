#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice(void);
		Ice(const Ice& copy);
		Ice& operator=(const Ice& copy);
		~Ice(void);
	public:
		AMateria* clone(void) const;
		void use(ICharacter& target);
};

#endif
