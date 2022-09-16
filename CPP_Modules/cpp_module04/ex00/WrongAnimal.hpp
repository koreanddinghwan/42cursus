#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal(void);
		WrongAnimal(std::string name);
		WrongAnimal(const WrongAnimal& copy);
		WrongAnimal& operator=(const WrongAnimal& copy);
		virtual ~WrongAnimal(void);
	public:
		void makeSound(void) const;//순수가상함수(ex02)
		std::string getType(void) const;
		void set_type(std::string copy);
};
#endif
