#ifndef INTERN_HPP
# define INTERN_HPP

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <typeinfo>

class Intern
{
	public:
		Intern(void);
		Intern(const Intern &copy);
		Intern& operator=(const Intern &copy);
		~Intern(void);
	public:
		Form *makeForm(const std::string formName, const std::string target) throw(FormNameException);
	class FormNameException : public std::exception
	{
		const char *what() const throw();
	};
};

#endif
