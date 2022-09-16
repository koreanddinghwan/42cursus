#include "Form.hpp"

Form::Form(void) : name("NoName"), is_signed(false), sign_perm(150), exec_perm(150)
{
	std::cout<<"Form Constructor Called"<<std::endl;
}

Form::Form(const std::string name, const unsigned int sign_perm, const unsigned int exec_perm) throw(GradeTooHighException, GradeTooLowException) : name(name), is_signed(false), sign_perm(sign_perm), exec_perm(exec_perm)
{
	std::cout<<"Form Constructor Called"<<std::endl;
	if (this->sign_perm < 1 || this->exec_perm < 1)
		throw GradeTooHighException();
	else if (this->sign_perm > 150 || this->exec_perm > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &copy) : name(copy.getName()), is_signed(copy.getSigned()), sign_perm(copy.getSignPerm()), exec_perm(copy.getExecPerm())
{
	std::cout<<"Form Copy Constructor Called"<<std::endl;
}

Form& Form::operator=(const Form &copy)
{
	(void)copy;
	return (*this);
}

Form::~Form(void)
{
	std::cout<<"Form Destructor Called"<<std::endl;
}

std::string Form::getName(void) const
{
	return (this->name);
}

bool Form::getSigned(void) const
{
	return (this->is_signed);
}

unsigned int Form::getSignPerm(void) const
{
	return (this->sign_perm);
}

unsigned int Form::getExecPerm(void) const
{
	return (this->exec_perm);
}

void Form::beSigned(const Bureaucrat &bure) throw(IsAlreadySignedException, GradeTooLowException)
{
	if (this->getSigned() == true)
		throw IsAlreadySignedException();
	if (bure.getGrade() > this->getSignPerm())
		throw GradeTooLowException();
	this->is_signed = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("[Form threw exception : Grade Too High!]");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("[Form threw exception : Grade Too Low!]");
}

const char *Form::IsAlreadySignedException::what() const throw()
{
	return ("[Form threw exception : It is already signed!]");
}

std::ostream& operator<<(std::ostream &os, const Form &form)
{
	std::cout<<"["<<form.getName()<<" STATUS]"<<std::endl;
	std::cout<<"["<<(form.getSigned() ? "SIGNED" : "NOT SIGNED")<<"]"<<std::endl;
	std::cout<<"["<<"SIGN PERM : "<<form.getSignPerm()<<"]"<<std::endl;
	std::cout<<"["<<"EXEC PERM : "<<form.getExecPerm()<<"]"<<std::endl<<std::endl;
	return (os);
}
