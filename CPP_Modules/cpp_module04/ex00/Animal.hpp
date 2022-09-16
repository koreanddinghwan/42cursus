#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
	protected:
		std::string type;
	public:
		Animal(void);
		Animal(std::string name);
		Animal(const Animal& copy);
		Animal& operator=(const Animal& copy);
		virtual ~Animal(void);
	public:
		virtual void makeSound(void) const;//순수가상함수(ex02)
		std::string getType(void) const;
		void set_type(std::string copy);
};
#endif
