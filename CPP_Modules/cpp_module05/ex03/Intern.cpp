#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"


Intern::Intern(void)
{
	std::cout<<"Intern Constructor Called"<<std::endl;
}

Intern::Intern(const Intern &copy)
{
	(void)copy;
	std::cout<<"Intern Constructor Called"<<std::endl;
}

Intern& Intern::operator=(const Intern &copy)
{
	(void)copy;
	return (*this);
}

Intern::~Intern(void)
{
	std::cout<<"Intern Destructor Called"<<std::endl;
}

Form *Intern::makeForm(const std::string formName, const std::string target) throw (FormNameException)
{
	std::string slots[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	for (int i = 0; i < 3; i++)
	{
		if (slots[i].compare(formName) == 0)
		{
			switch (i) {
				case 0:
					return (new ShrubberyCreationForm(target));
				case 1:
					return (new RobotomyRequestForm(target));
				case 2:
					return (new PresidentialPardonForm(target));
			}
		}
	}
	throw FormNameException();
	return (NULL);
}

const char *Intern::FormNameException::what() const throw()
{
	return ("I cannot find that form! sorry....");
}
