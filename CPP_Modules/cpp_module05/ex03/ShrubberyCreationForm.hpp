#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"
#include <fstream>

class ShrubberyCreationForm : public Form
{
	private:
		static const std::string shrubbery;
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm &copy);
		~ShrubberyCreationForm(void);
		void execute(Bureaucrat const & executor) const throw(GradeTooLowException, FileOpenError);
	private:
		void generator(void) const throw(FileOpenError);
	class FileOpenError : public std::exception
	{
		const char *what() const throw();
	};
};

#endif
