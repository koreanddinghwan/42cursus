#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain *brain;
	public:
		Cat(void);
		Cat(std::string name);
		Cat(const Cat& copy);
		Cat& operator=(const Cat& copy);
		~Cat(void);
	public:
		void makeSound(void) const;
};

#endif
