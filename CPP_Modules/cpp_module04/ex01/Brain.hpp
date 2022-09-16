#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>
#include <iostream>

class Brain
{
	public:
		std::string ideas[100];
		int idea_index;
	public:
		Brain(void);
		Brain(const Brain &copy);
		Brain& operator=(const Brain &copy);
		~Brain();
	public:
		std::string *getter(void);
		void setter(const Brain &copy);
		void think(const std::string idea);
};
#endif
