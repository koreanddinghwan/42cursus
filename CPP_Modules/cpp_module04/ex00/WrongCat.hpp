#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat(void);
		WrongCat(std::string name);
		WrongCat(const WrongCat& copy);
		WrongCat& operator=(const WrongCat& copy);
		~WrongCat(void);
	public:
		void makeSound(void) const;
};

#endif
