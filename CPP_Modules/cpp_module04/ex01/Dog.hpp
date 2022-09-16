#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *brain;
	public:
		Dog(void);
		Dog(std::string name);
		Dog(const Dog& copy);
		Dog& operator=(const Dog& copy);
		~Dog(void);
	public:
		void makeSound(void) const;
		void think(const std::string think) const;
		void print_think(void) const;
};

#endif
