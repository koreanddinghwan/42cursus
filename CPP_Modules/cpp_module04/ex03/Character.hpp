#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <cstddef>
#include <string>

class Character : public ICharacter
{
	private:
		std::string name;
		AMateria *slots[4];
		AMateria *unequiped[100];
		int idx;
		int unequiped_idx;
	public:
		Character(void);
		Character(const std::string name);
		Character(const Character &copy);
		Character& operator=(const Character &copy);
		~Character(void);
	public:
		std::string const &getName(void) const;
		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);
};

#endif
