#ifndef FORM_HPP
# define FORM_HPP

class Bureaucrat;
#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string name;
		bool is_signed;
		const unsigned int sign_perm;
		const unsigned int exec_perm;
	public:
		Form(void);
		Form(const std::string name, const unsigned int sign_perm, const unsigned int exec_perm) throw(GradeTooHighException, GradeTooLowException);
		Form(const Form &copy);
		Form& operator=(const Form &copy);
		virtual ~Form(void);
	public:
		std::string getName(void) const;
		bool getSigned(void) const;
		unsigned int getSignPerm(void) const;
		unsigned int getExecPerm(void) const;
		void beSigned(const Bureaucrat &bure) throw(IsAlreadySignedException, GradeTooLowException);
		virtual void execute(Bureaucrat const & executor) const = 0; //순수 가상함수, Form의 추상클래스화

	class GradeTooHighException : public std::exception 
	{
		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		const char *what() const throw();
	};
	
	class IsAlreadySignedException : public std::exception
	{
		const char *what() const throw();
	};
};

std::ostream& operator<<(std::ostream &os, const Form &form);

#endif
