#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat
{
	private:
		const std::string name;
		unsigned int grade;
		static const unsigned int MAXGRADE = 1;
		static const unsigned int MINGRADE = 150;
	public:
		Bureaucrat(void);
		Bureaucrat(const std::string name, const unsigned int grade) throw(GradeTooHighException, GradeTooLowException);
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat& operator=(const Bureaucrat &copy);
		~Bureaucrat(void);
	public:
		std::string getName(void) const;
		int getGrade(void) const;
		void increGrade(void) throw (GradeTooHighException);
		void decreGrade(void) throw (GradeTooLowException);
	class GradeTooHighException : public std::exception
	{
		public:
			const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			const char *what() const throw();
	};
};

std::ostream& operator<<(std::ostream &os, const Bureaucrat &target);

#endif
